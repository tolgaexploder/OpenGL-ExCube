# OpenGL-ExCube

So the project purprose is drawing 3D cube by applying rotation transformations to the cube. The rotation angles(x, y) are stored in our rotate_x and rotate_y variables. and angles are updated in display() function by adding the spin_x and spin_y values to the rotation angles. The rotations are applied using the glRotatef() function, which takes the rotation angle and the rotation axis as arguments. 
So, the rotation axes are(1, 0, 0) for the x - axis and (0, 1, 0) for the y - axis.

The perspective projection takes four arguments, FOV angle, aspect ratio(width / height), and the near and far clipping planes. The perspective projection matrix is calculated based on these parameters, transforming the 3D coordinates of the vertices into 2D coordinates on the screen.

The math behind the perspective projection: Where f = 1 / tan(FOV / 2) is the focal length, aspect is the aspect ratio, A = (far + near) / (near - far), and B = (2 * far * near) / (near - far).

https://user-images.githubusercontent.com/71831052/236647009-77c441fc-4dab-48a9-a78e-8a81acd48feb.mp4


# How to setup OpenGL
https://youtu.be/HurTyJ3v_xg
