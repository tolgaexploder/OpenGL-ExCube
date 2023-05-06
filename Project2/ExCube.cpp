#include "ExCube.h"

void ExCube::quad(int a, int b, int c, int d) {
    glBegin(GL_QUADS);
    glColor3fv(col[a]);
    glVertex3fv(v[a]);

    glColor3fv(col[b]);
    glVertex3fv(v[b]);

    glColor3fv(col[c]);
    glVertex3fv(v[c]);

    glColor3fv(col[d]);
    glVertex3fv(v[d]);
    glEnd();
}

void ExCube::cube() {
    quad(0, 3, 2, 1);
    quad(2, 3, 7, 6);
    quad(0, 4, 7, 3);
    quad(1, 2, 6, 5);
    quad(4, 5, 6, 7);
    quad(0, 1, 5, 4);
}

std::vector<Vec3> ExCube::generateRandomStarPositions(int numStars, float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
    std::vector<Vec3> position;
    position.reserve(numStars);

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < numStars; ++i) {
        Vec3 star_pos;
        star_pos.x = minX + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxX - minX)));
        star_pos.y = minY + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxY - minY)));
        star_pos.z = minZ + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxZ - minZ)));
        position.push_back(star_pos);
    }
    return position;
}

void ExCube::init() {
    int numStars = 100;
    float minX = -10.0f, maxX = 10.0f;
    float minY = -10.0f, maxY = 10.0f;
    float minZ = -10.0f, maxZ = 10.0f;

    starPositions = generateRandomStarPositions(numStars, minX, maxX, minY, maxY, minZ, maxZ);
}

void ExCube::drawStar(Vec3 position) {
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(position.x - 0.1f, position.y - 0.1f, position.z);
    glVertex3f(position.x + 0.1f, position.y - 0.1f, position.z);
    glVertex3f(position.x + 0.1f, position.y + 0.1f, position.z);
    glVertex3f(position.x - 0.1f, position.y + 0.1f, position.z);
    glEnd();
}

void ExCube::display() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(60, w / h, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3, 3, 3, 0, 0, 0, 0, 0, 1);

    // update rotation angles based on spin values
    rotate_y += spin_y;
    rotate_x += spin_x;

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    printf("rotate_x: %f | rotate_y: %f\n", rotate_x, rotate_y);
    printf("Window Width: %d | Window Height: %d\n", w, h);

    int numStars = 100;
    float minX = -10.0f, maxX = 10.0f;
    float minY = -10.0f, maxY = 10.0f;
    float minZ = -10.0f, maxZ = 10.0f;

    for (int i = 0; i <= numStars; i++) {
        drawStar(starPositions[i]);
    }

    cube();

    glutSwapBuffers();
}

void ExCube::idle() {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    static ExCube cube{};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(767, 326);
    glutCreateWindow("exploder");

    cube.init();

    glutDisplayFunc([]() {
        cube.display();
        });
    glEnable(GL_DEPTH_TEST);

    glutIdleFunc([]() {
        cube.idle();
        });

    glutMainLoop();
    return 0;
}
