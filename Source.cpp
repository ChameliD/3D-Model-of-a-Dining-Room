#include<Windows.h>
#include<GL/glut.h>
#include<math.h>
#include <iostream>
#include "SOIL2.h"

#define PI 3.14159265f

using namespace std;


//variables for animation of clock
GLfloat rota = 0.0f;
GLfloat rotb = 0.0f;

//variables for animation of fair
GLfloat fx1 = -8;
GLfloat fx2 = -17;
GLfloat fy1 = -19;
GLfloat fy2 = -13;

GLfloat thickMarks = 0.0f;

GLfloat x1step = 0.37f;
GLfloat x2step = 0.37f;
GLfloat y1step = 0.35f;
GLfloat y2step = 0.35f;

// variables to move outermost Object Frame (to move all the rendered environment)
GLfloat moveX = 0.0f;
GLfloat moveY = 0.0f;
GLfloat moveZ = 0.0f;

// variables to rotate outermost Object Frame (to move all the rendered environment)
GLfloat rotX = 0.0f;
GLfloat rotY = 0.0f;
GLfloat rotZ = 0.0f;


//variables to move the camera
GLfloat camY = 0.0f;
GLfloat camX = 0.0f;
GLfloat camZ = 0.0f;
GLuint tex;

void initTexture1() {

	int width, height;
	unsigned char* image = SOIL_load_image("F:/texture/usSoil2/usSoil2/images/eve.bmp", &width, &height, 0, SOIL_LOAD_RGB);



	if (!image) {
		std::cout << "Failed to load texture: " << sizeof(image) << std::endl;
	}
	else {
		std::cout << &image << std::endl;
	}


	unsigned char data[] =
	{
		128, 128, 128, 255,
		255, 0, 0, 255,
		0, 255, 0, 255,
		0, 0, 255, 255
	};

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
		GL_UNSIGNED_BYTE, image);

	// Use the following line in order to load the created texture map instead of the image
	// glTexImage2D( GL_TEXTURE_2D, 0,GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );    

}

void initTexture2() {

	int width, height;
	unsigned char* image2 = SOIL_load_image("F:/texture/usSoil2/usSoil2/images/carpetred.bmp", &width, &height, 0, SOIL_LOAD_RGB);



	if (!image2) {
		std::cout << "Failed to load texture: " << sizeof(image2) << std::endl;
	}
	else {
		std::cout << &image2 << std::endl;
	}


	unsigned char data[] =
	{
		128, 128, 128, 255,
		255, 0, 0, 255,
		0, 255, 0, 255,
		0, 0, 255, 255
	};

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
		GL_UNSIGNED_BYTE, image2);

	// Use the following line in order to load the created texture map instead of the image
	// glTexImage2D( GL_TEXTURE_2D, 0,GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );    

}

void initTexture3() {

	int width, height;
	unsigned char* image3 = SOIL_load_image("F:/texture/usSoil2/usSoil2/images/wood.bmp", &width, &height, 0, SOIL_LOAD_RGB);



	if (!image3) {
		std::cout << "Failed to load texture: " << sizeof(image3) << std::endl;
	}
	else {
		std::cout << &image3 << std::endl;
	}


	unsigned char data[] =
	{
		128, 128, 128, 255,
		255, 0, 0, 255,
		0, 255, 0, 255,
		0, 0, 255, 255
	};

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
		GL_UNSIGNED_BYTE, image3);

	// Use the following line in order to load the created texture map instead of the image
	// glTexImage2D( GL_TEXTURE_2D, 0,GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );    

}

void initLighting() {

	// GLfloat L0_Ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat L0_Diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat L0_Specular[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat L0_postion[] = { 5, 5, 0, 1.0 };

	// glLightfv(GL_LIGHT0, GL_AMBIENT, L0_Ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, L0_Diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, L0_postion);
	glLightfv(GL_LIGHT0, GL_SPECULAR, L0_Specular);
}

/*void initLighting2() {
	// GLfloat L1_Ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat L1_Diffuse[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat L1_Specular[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat L1_postion[] = { 5, 5, 0, 1.0 };

	// glLightfv(GL_LIGHT1, GL_AMBIENT, L1_Ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, L1_Diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, L1_postion);
	glLightfv(GL_LIGHT1, GL_SPECULAR, L1_Specular);


}*/

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	GLfloat globalAmbient[] = { 0.5, 0.5, 0.5, 1.0 };
	glEnable(GL_DEPTH_TEST);                // Enable the Depth testig in openGL
	glEnable(GL_CULL_FACE);                 // Enable Hidden Surface Removal
	glPolygonMode(GL_FRONT, GL_FILL);       // Set the Front of the faces of the cube to be unfilled (Skeleton Model)
	glPolygonMode(GL_BACK, GL_FILL);        // Set the Back of the faces of the cube to be filled with the color

	 //Enable the adding of lights
	glEnable(GL_LIGHTING);


	glShadeModel(GL_SMOOTH);

	// Changing the global Ambient illumination without any lights present
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbient);

	(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);


	initLighting();

	// Enabling the color tracking of each faces of the materials. this enables the color visibility of the materials
	glEnable(GL_COLOR_MATERIAL);

	//Turn on lighting
	//glEnable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	//glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHT2);


	// enable the normalization of the normal vectors (converting the vector values to the range 0-1)
	glEnable(GL_NORMALIZE);


}

//Calculate the normals for two vectors va, vb ( normal for a plane/face )
GLfloat* calNormal(GLfloat* va, GLfloat* vb) {
	GLfloat vNormal[3];
	vNormal[0] = va[1] * vb[2] - va[2] * vb[1];
	vNormal[1] = va[0] * vb[2] - va[2] * vb[0];
	vNormal[2] = va[0] * vb[1] - va[1] * vb[0];

	return vNormal;
}

// Find the Normal from three points in 3d space.
// BE AWARE THAT THE POINTS SHOULD BE DECLARED IN ANTI-CLOCKWISE ORDER FOR THE TWO SIDES(FORMING THE TWO VECTORS)
// HAVING ONE VERTEX COMMON TO BOTH SIDES (vertices abc form two sides as 'ab' and 'ac')
// Otherwise you'll get the wrong/ reverse vector
GLfloat* findNormal(GLfloat* a, GLfloat* b, GLfloat* c) {

	GLfloat va[] = { b[0] - a[0], b[1] - a[1], b[2] - a[2] };
	GLfloat vb[] = { c[0] - a[0], c[1] - a[1], c[2] - a[2] };

	return calNormal(va, vb);
}

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		moveZ += 1;

	if (key == GLUT_KEY_DOWN)
		moveZ -= 1;

	if (key == GLUT_KEY_LEFT)
		rotY -= 5.0;

	if (key == GLUT_KEY_RIGHT)
		rotY += 1.0;

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {

	if (key == 'w')
		camY += 0.5;
	if (key == 's')
		camY -= 0.5;

	if (key == 'c')
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (key == 'C')
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	if (key == 'k')
		glDisable(GL_LIGHT0);
	if (key == 'K')
		glEnable(GL_LIGHT0);

	glutPostRedisplay();

}

void Timer1(int value) {
	rota += rota >= 360 ? -rota : 2;
	glutPostRedisplay();
	glutTimerFunc(1000, Timer1, 2);
}

void Timer2(int value) {

	rotb += rotb >= 360 ? -rotb : 2;
	glutPostRedisplay();
	glutTimerFunc(10000, Timer2, 3);
}

void Timer3(int value) {

	if (fx1 <= -8 || fx1 >= -4)
		x1step = -x1step;
	fx1 += x1step;

	if (fx2 <= -20 || fx2 >= -18)
		x2step = -x2step;
	fx2 += x2step;

	if (fy1 <= -21 || fy1 >= -15)
		y1step = -y1step;
	fy1 += y1step;

	if (fy2 <= -14 || fy2 >= -11)
		y2step = -y2step;
	fy2 += y2step;

	glutPostRedisplay();
	glutTimerFunc(500, Timer3, 4);

}

void tableLeg(float x1, float x2, float y1, float y2, float z1, float z2)
{
	glPushMatrix();

	glBegin(GL_POLYGON);
	{

		GLfloat front[4][3] = {
			{x2, y2, z1},
			{x1, y2, z1},
			{x1, y1, z1},
			{x2, y1, z1}
		};


		glNormal3fv(findNormal(front[0], front[1], front[2]));
		glTexCoord2f(0, 0);
		glVertex3fv(front[0]);
		glTexCoord2f(1, 0);
		glVertex3fv(front[1]);
		glTexCoord2f(0.5, 1);
		glVertex3fv(front[2]);
		glTexCoord2f(0, 1);
		glVertex3fv(front[3]);
	}

	{
		GLfloat back[4][3] = {
			{x2, y2, z2},
			{x2, y1, z2},
			{x1, y1, z2},
			{x1, y2, z2}
		};

		glNormal3fv(findNormal(back[0], back[1], back[2]));
		glTexCoord2f(0, 0);
		glVertex3fv(back[0]);
		glTexCoord2f(1, 0);
		glVertex3fv(back[1]);
		glTexCoord2f(0.5, 1);
		glVertex3fv(back[2]);
		glTexCoord2f(0, 1);
		glVertex3fv(back[3]);
	}

	{
		// LEFT
		GLfloat left[4][3] = {
			{x1, y1, z1},
			{x1, y2, z1},
			{x1, y2, z2},
			{x1, y1, z2}
		};

		glNormal3fv(findNormal(left[0], left[1], left[2]));
		glTexCoord2f(0, 0);
		glVertex3fv(left[0]);
		glTexCoord2f(1, 0);
		glVertex3fv(left[1]);
		glTexCoord2f(0.3, 1);
		glVertex3fv(left[2]);
		glTexCoord2f(0, 1);
		glVertex3fv(left[3]);
	}

	{
		//Right

		GLfloat right[4][3] = {
			{x2, y2, z2},
			{x2, y2, z1},
			{x2, y1, z1},
			{x2, y1, z2}
		};

		glNormal3fv(findNormal(right[0], right[1], right[2]));
		glTexCoord2f(0, 0);
		glVertex3fv(right[0]);
		glTexCoord2f(1, 0);
		glVertex3fv(right[1]);
		glTexCoord2f(0.5, 1);
		glVertex3fv(right[2]);
		glTexCoord2f(0, 1);
		glVertex3fv(right[3]);
	}
	///////////////////////////////////////////////////////////////////////////
	{

		//Top
		GLfloat top[4][3] = {
			{x2, y2, z1},
			{x2, y2, z2},
			{x1, y2, z2},
			{x1, y2, z1}
		};

		glNormal3fv(findNormal(top[0], top[1], top[2]));
		glTexCoord2f(0, 0);
		glVertex3fv(top[0]);
		glTexCoord2f(1, 0);
		glVertex3fv(top[1]);
		glTexCoord2f(0.5, 1);
		glVertex3fv(top[2]);
		glTexCoord2f(0, 1);
		glVertex3fv(top[3]);
	}

	{

		//Bottom

		GLfloat bottom[4][3] = {
			{x2, y1, z2},
			{x2, y1, z1},
			{x1, y1, z1},
			{x1, y1, z2}
		};

		glNormal3fv(findNormal(bottom[0], bottom[1], bottom[2]));
		glTexCoord2f(0, 0);
		glVertex3fv(bottom[0]);
		glTexCoord2f(1, 0);
		glVertex3fv(bottom[1]);
		glTexCoord2f(0.5, 1);
		glVertex3fv(bottom[2]);
		glTexCoord2f(0, 1);
		glVertex3fv(bottom[3]);
	}

	glEnd();
	glPopMatrix();
}

void cuboid(float x1, float x2, float y1, float y2, float z1, float z2)
{
	// BACK
	glBegin(GL_POLYGON);
	//glColor4f(0.5f, 0.35f, 0.05f, 1.0f);
	glVertex3f(x2, y2, z2);
	glVertex3f(x2, y1, z2);
	glVertex3f(x1, y1, z2);
	glVertex3f(x1, y2, z2);
	glEnd();

	// FRONT
	glBegin(GL_POLYGON);
	//glColor4f(0.5f, 0.35f, 0.05f, 1.0f);
	glVertex3f(x2, y2, z1);
	glVertex3f(x1, y2, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y1, z1);
	glEnd();

	// LEFT
	glBegin(GL_POLYGON);
	//glColor4f(0.5f, 0.35f, 0.05f, 1.0f);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y1, z2);
	glEnd();

	//Right
	glBegin(GL_POLYGON);
	//glColor4f(0.5f, 0.35f, 0.05f, 1.0f);
	glVertex3f(x2, y2, z2);
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x2, y1, z2);
	glEnd();

	//Top
	glBegin(GL_POLYGON);
	//glColor4f(1.0f, 0.5f, 0.5f, 1.0f);
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y2, z2);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y2, z1);
	glEnd();

	//Bottom
	glBegin(GL_POLYGON);
	//glColor4f(0.5f, 0.35f, 0.05f, 1.0f);
	glVertex3f(x2, y1, z2);
	glVertex3f(x2, y1, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y1, z2);
	glEnd();
}

void bulb() {
	glPushMatrix();

	initLighting();
	glPushMatrix();

	glBegin(GL_LINES);
	glColor3f(0.1, 0.5, 0.0);
	glVertex3f(0, 40, 0);
	glVertex3f(0, 0, 0);
	glDisable(GL_LINE_WIDTH);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.5, 0.5);
	glutWireSphere(5, 30, 20);
	glPopMatrix();

	glutKeyboardFunc(keyboard);
	glPopMatrix();



}

void table() {
	//glColor3ub(92, 64, 25);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	tableLeg(0, 15, 0, 1, 0, 25);

	tableLeg(0.5, 1.5, -10.0, 0.0, 23.5, 24.5);
	tableLeg(0.5, 1.5, -10.0, 0.0, 0.5, 1.5);
	tableLeg(13.5, 14.5, -10.0, 0.0, 23.5, 24.5);
	tableLeg(13.5, 14.5, -10.0, 0.0, 0.5, 1.5);
	glDisable(GL_TEXTURE_2D);

}

void chair()
{
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	tableLeg(5.0, 10.0, -2.0, -2.4, 2.0, 7.5);

	//legs of chair

	tableLeg(5.0, 5.3, -2.3, -7.3, 2.0, 2.3);

	tableLeg(9.7, 10.0, -2.3, -7.3, 2.0, 2.3);

	tableLeg(5.0, 5.3, -2.3, -7.3, 7.0, 7.3);

	tableLeg(9.7, 10.0, -2.3, -7.3, 7.0, 7.3);

	//supporting

	tableLeg(9.7, 10.0, -2.0, 7.0, 2, 2.3);
	tableLeg(9.7, 10.0, -2.0, 7.0, 7.5, 7.8);
	tableLeg(9.7, 10.0, 5.0, 7.0, 2.0, 7.5);
	glDisable(GL_TEXTURE_2D);



}

void tableWithChair()
{
	initTexture3();
	glScalef(1.5, 1.5, 1.5);
	glPushMatrix();

	table();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, -3, 20);
	glRotatef(180.0f, 0.0, 1.0, 0.0);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, -3, 0);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, -3, 11);
	glRotatef(180.0f, 0.0, 1.0, 0.0);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, -3, 10);
	chair();
	glPopMatrix();

	glPushMatrix();
	glRotatef(270, 0, 1, 0);
	glTranslatef(20, -3, -15);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -3, 8);
	glRotatef(90.0f, 0.0, 1.0, 0.0);
	chair();
	glPopMatrix();


}

void windowOutSide(float x1, float x2, float y1, float y2, float z1) {
	glPushMatrix();
	initTexture1();

	// glRotatef(180, 0, 0, 1);
	glBegin(GL_POLYGON);
	{
		GLfloat win[4][4] = {
			{x2, y2 - 0.1, z1 + 0.1},
			{x2, y1 + 0.1, z1 + 0.1},
			{x1, y1 + 0.1, z1 + 0.1},
			{x1, y2 - 0.1, z1 + 0.1}

		};

		glNormal3fv(findNormal(win[0], win[1], win[2]));
		glTexCoord2f(0, 0);
		glVertex3fv(win[3]);
		glTexCoord2f(1, 0);
		glVertex3fv(win[0]);
		glTexCoord2f(0.5, 1);
		glVertex3fv(win[1]);
		glTexCoord2f(0, 1);
		glVertex3fv(win[2]);
	}
	glEnd();
	glPopMatrix();

}

void window(float x1, float x2, float y1, float y2, float z1)
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	windowOutSide(10, 40, -5, 20, -30);
	windowOutSide(x1, x2, y1, y2, z1);
	glDisable(GL_TEXTURE_2D);

	//window frame
	glPushMatrix();
	glDisable(GL_TEXTURE_2D);

	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	cuboid(x2 - 1, x2 + 1, y1 - 1, y2 + 1, z1, z1 + 0.6);
	cuboid(x1 - 1, x1 + 1, y1 - 1, y2 + 1, z1, z1 + 0.6);
	cuboid(x1 - 1, x2 + 1, y1 + 1, y1 - 1, z1, z1 + 0.6);
	cuboid(x1 - 1, x2 + 1, y2 + 1, y2 - 1, z1, z1 + 0.6);

	cuboid(((x2 + x1) / 2) - 1.0f, ((x2 + x1) / 2) + 1.0f, y1 - 1, y2 + 1, z1, z1 + 0.6);
	cuboid(x1 - 1, x2 + 1, ((y2 + y1) / 2) - 1, ((y2 + y1) / 2) + 1, z1, z1 + 0.6);
	glPopMatrix();
}

void fiar() {
	glPushMatrix();
	//initLighting2();
	glEnable(GL_LIGHT1);
	glBegin(GL_TRIANGLES);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-10, -27, -19.88);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-3, fy1, -19.88);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5, -27, -19.88);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-10, -27, -19.88);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(fx1, -10, -19.88);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-2, -27, -19.88);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-13, -27, -19.88);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-11, -13, -19.88);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-8, -27, -19.88);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-17, -27, -19.88);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-13, -15, -19.88);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-11, -27, -19.88);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-21.5, -27, -19.88);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-15, fy2, -19.88);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-10, -27, -19.88);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-21.5, -27, -19.87);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(fx2, -20, -19.87);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(-18, -27, -19.87);
	glEnd();

	//glutKeyboardFunc(keyboard);



	glPopMatrix();
}

void furnece() {

	glColor3ub(33, 56, 74);
	cuboid(-25, 1, -29, 31, -30, -20);
	glColor3ub(33, 56, 74);
	cuboid(-28, 4, -29, -28, -30, -18);

	cuboid(-28, 4, -10, -8, -30, -18);
	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(1, 31, -20);
	glVertex3f(1, -35, -20);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(1, 31, -29.5);
	glVertex3f(1, -35, -29.5);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-25, 31, -20);
	glVertex3f(-25, -35, -20);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(1, -27.8, -20);
	glVertex3f(-25, -27.8, -20);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(1, -27.8, -20);
	glVertex3f(1, -27.8, -30);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(4, -27.8, -18);
	glVertex3f(-28, -27.8, -18);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(4, -27.8, -18);
	glVertex3f(4, -27.8, -30);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(4, -28, -18);
	glVertex3f(4, -35, -18);
	glEnd();

	//up part lining
	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(1, -8, -20);
	glVertex3f(1, -8, -30);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(4, -8, -18);
	glVertex3f(-28, -8, -18);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(4, -8, -18);
	glVertex3f(4, -8, -30);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(4, -8, -18);
	glVertex3f(4, -10, -18);
	glEnd();

	//black background
	glBegin(GL_POLYGON);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(-1, -10, -19.9);
	glVertex3f(-1, -28, -19.9);
	glVertex3f(-22, -28, -19.9);
	glVertex3f(-22, -10, -19.9);
	glEnd();

	//fiar
	fiar();


}

void wallClock()
{

	//glRotatef(90.0f, 0.0, 1.0, 0.0);
	//glRotatef(120.0f, 0.0, 1.0, 0.0);
	//glRotatef(-20.0f, 0.0, 0.0, 1.0);
	glPushMatrix();

	glScalef(5, 5, 5); //make big

	GLfloat radius = 1;
	GLfloat radiusBig = 1.05;
	glEnable(GL_POINT_SIZE);
	glPointSize(5);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

	glPushMatrix();
	glTranslatef(0, 0, 1);
	//1 to 12 numbering
	for (int i = 0; i <= 12; i++) {
		glPushMatrix();
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
		glRotatef(thickMarks += 30.0f, 0, 0, 1);//rotate via z axis.y-x plane
		glTranslatef(1, 0, 0);
		glBegin(GL_POINTS);
		glVertex3f(0, 0, 0);
		glEnd();
		glPopMatrix();
	}

	//circular frame
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	for (GLfloat i = 0; i <= 2 * PI * radiusBig; i += 0.01) {
		glVertex3f(radiusBig * cos(i), radiusBig * sin(i), 0);
	}
	glEnd();
	glPopMatrix();

	glPopMatrix();

	//hour hand
	glPushMatrix();
	glTranslatef(0.0, 0.0, radius);
	glRotatef(-rotb, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, radius / 2, 0);
	glEnd();
	glPopMatrix();

	//minute hand
	glPushMatrix();
	glTranslatef(0.0, 0.0, radius);
	glRotatef(-rota, 0.0f, 0.0f, 1.0f);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, radius, 0);
	glEnd();
	glPopMatrix();

	glPopMatrix();

}

void bottom(float x1, float x2, float y1, float y2, float z1, float z2) {
	initTexture2();
	glPushMatrix();
	glBegin(GL_POLYGON);
	{

		GLfloat floor[4][4] = {
			{x1, y1, z2},
			{x1, y1, z1},
			{x2, y1, z1},
			{x2, y1, z2}
		};

		glNormal3fv(findNormal(floor[0], floor[1], floor[2]));
		glTexCoord2f(0, 0);
		glVertex3fv(floor[0]);
		glTexCoord2f(1, 0);
		glVertex3fv(floor[1]);
		glTexCoord2f(0.5, 1);
		glVertex3fv(floor[2]);
		glTexCoord2f(0, 1);
		glVertex3fv(floor[3]);



	}
	glEnd();
	glPopMatrix();
}

void wall(float x1, float x2, float y1, float y2, float z1, float z2) {


	glColor3ub(33, 56, 74);
	glPushMatrix();
	glRotatef(-30.0f, 1.0, 0.0, 0.0);
	glRotatef(135.0f, 0.0, 1.0, 0.0);
	glPushMatrix();
	glTranslatef(30, 8, 0);
	bulb();
	glPopMatrix();
	// BACK
	glBegin(GL_POLYGON);
	glColor3ub(33, 56, 74);

	//glColor4f(1.0f, 1.0f, 0.0f, 0.1f);
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);
	glEnd();

	// left
	glBegin(GL_POLYGON);
	glColor3ub(55, 93, 122);

	//glColor4f(0.0f, 0.0f, 1.0f, 0.1f);
	glVertex3f(x1, y1, z2);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y2, z1);
	glVertex3f(x1, y1, z1);
	glEnd();

	//black space
	glBegin(GL_POLYGON);
	glColor3ub(0, 0, 0);

	glVertex3f(x1 + 0.01, -30, 26);
	glVertex3f(x1 + 0.01, 20, 26);
	glVertex3f(x1 + 0.01, 20, 10);
	glVertex3f(x1 + 0.01, -30, 10);

	glEnd();


	//door
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex3f(x1 + 0.1, -30, 26);
	glVertex3f(x1 + 0.1, 20, 26);
	glVertex3f(x1 + 0.1, 20, 10);
	glVertex3f(x1 + 0.1, -30, 10);
	glEnd();

	//door frame
	glColor3ub(197, 201, 201);
	cuboid(x1, x1 + 0.1, -30, 21, 26, 27);
	cuboid(x1, x1 + 0.1, -30, 21, 9, 10);
	cuboid(x1, x1 + 0.1, 20, 21, 10, 26);

	//window
	window(10, 40, -5, 20, -30);

	//furnace
	furnece();

	//wallClock
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	glTranslatef(-10, 10, 24.5);
	wallClock();
	glPopMatrix();


	glPushMatrix();
	// bottom
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tex);
	bottom(x1, x2, y1, y2, z1, z2);
	glDisable(GL_TEXTURE_2D);


	glPopMatrix();
	glPopMatrix();

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	// camera orientation (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
	gluLookAt(0.0 + camX, 2.0 + camY, 5.0 + camZ, 0, 0, 0, 0, 1.0, 0);

	// move the object frame using keyboard keys
	glTranslatef(moveX, moveY, moveZ);
	glRotatef(rotX, 1.0f, 0.0f, 0.0f);
	glRotatef(rotY, 0.0f, 1.0f, 0.0f);
	glRotatef(rotZ, 0.0f, 0.0f, 1.0f);

	//table with 4 chairs
	glPushMatrix();
	glRotatef(-30.0f, 1.0, 0.0, 0.0);
	glRotatef(135.0f, 0.0, 1.0, 0.0);
	glTranslatef(16, -15, -20);
	tableWithChair();
	glPopMatrix();

	//walls
	glPushMatrix();
	wall(-30.0, 45.0, -30.0, 30.0, -30.0, 32.0);
	glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();
}

void changeSize(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);

	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-52.0, 52.0, -52 / aspect_ratio, 52 / aspect_ratio, 52.0, -52.0);
	else
		glOrtho(-52.0 * aspect_ratio, 52.0 * aspect_ratio, -52.0, 52.0, 52.0, -52.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);       // Enable the Depht preception as well
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("OpenGL 3D Introduction");
	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);

	// keyboard function activation
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);


	glutTimerFunc(1000, Timer1, 2);
	glutTimerFunc(10000, Timer2, 3);
	glutTimerFunc(500, Timer3, 4);
	init();
	glutMainLoop();


	return 0;
}


