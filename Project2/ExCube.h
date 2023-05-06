#pragma once
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>
#include "iostream"
#include <time.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

struct Vec3 {
	float x, y, z;
};

class ExCube {
public:
    void quad(int a, int b, int c, int d);
    void cube();
    std::vector<Vec3> generateRandomStarPositions(int numStars, float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
    std::vector<Vec3> starPositions;
    void drawStar(Vec3 position);
    void display();
    void idle();
    void init();
private:
    float col[8][3] = {
        {0.5f, 0.5f, 1.0f},  // light blue
        {1.0f, 1.0f, 1.0f},  // white
        {0.5f, 0.5f, 1.0f},  // light blue
        {0.0f, 1.0f, 1.0f},  // cyan
        {1.0f, 1.0f, 1.0f},  // white
        {0.0f, 1.0f, 1.0f},  // cyan
        {0.5f, 0.5f, 1.0f},  // light blue
        {1.0f, 1.0f, 1.0f}   // white
    };

    float v[8][3] = {
        {-1,-1,-1},
        {-1,-1,1},
        {-1,1,1},
        {-1,1,-1},
        {1,-1,-1},
        {1,-1,1},
        {1,1,1},
        {1,1,-1}
    };

    float rotate_x = 0;
    float rotate_y = 0;
    float spin_x = 0.5;
    float spin_y = 0.5;
};
