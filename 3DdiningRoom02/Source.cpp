#include<Windows.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.14159265f

GLfloat rota = 0.0f;
GLfloat rotb = 0.0f;
GLfloat fx1 = -8;
GLfloat fx2 = -17;
GLfloat fy1 = -19;
GLfloat fy2 = -13;
GLfloat thickMarks = 0.0f;
GLfloat x1step = 0.37f;
GLfloat x2step = 0.37f;
GLfloat y1step = 0.35f;
GLfloat y2step = 0.35f;


void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);                // Enable the Depth testig in openGL
	glEnable(GL_CULL_FACE);                 // Enable Hidden Surface Removal
	glPolygonMode(GL_FRONT, GL_FILL);       // Set the Front of the faces of the cube to be unfilled (Skeleton Model)
	glPolygonMode(GL_BACK, GL_FILL);        // Set the Back of the faces of the cube to be filled with the color

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

	if (fx1 <= -8||fx1 >= -4)
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
	//bottom
	glBegin(GL_POLYGON);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(4, 0, 0);
	glVertex3f(4, 0, 4);
	glVertex3f(0, 0, 4);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(2, 2, 2);
	glVertex3f(0, 0, 4);
	glEnd();

	//front
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	glVertex3f(0, 0, 0);
	glVertex3f(4, 0, 0);
	glVertex3f(2, 2, 2);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex3f(4, 0, 4);
	glVertex3f(2, 2, 2);
	glVertex3f(0, 0, 4);
	glEnd();

	//back
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	glVertex3f(4, 0, 0);
	glVertex3f(4, 0, 4);
	glVertex3f(2, 2, 2);
	glEnd();
}

void table() {

	tableLeg(0, 15, 0, 1, 0, 25);

	tableLeg(0.5, 1.5, -10.0, 0.0, 23.5, 24.5);
	tableLeg(0.5, 1.5, -10.0, 0.0, 0.5, 1.5);
	tableLeg(13.5, 14.5, -10.0, 0.0, 23.5, 24.5);
	tableLeg(13.5, 14.5, -10.0, 0.0, 0.5, 1.5);

}
void window(float x1, float x2, float y1, float y2, float z1)
{
	glPushMatrix();

	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 0.1f);
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);
	glEnd();
	glPopMatrix();

	//window frame
	glPushMatrix();
	glColor4f(1.0f, 0.0f, 1.0f, 0.1f);
	tableLeg(x2 - 1, x2 + 1, y1 - 1, y2 + 1, z1, z1 + 0.6);
	tableLeg(x1 - 1, x1 + 1, y1 - 1, y2 + 1, z1, z1 + 0.6);
	tableLeg(x1 - 1, x2 + 1, y1 + 1, y1 - 1, z1, z1 + 0.6);
	tableLeg(x1 - 1, x2 + 1, y2 + 1, y2 - 1, z1, z1 + 0.6);

	tableLeg(((x2 + x1) / 2) - 1.0f, ((x2 + x1) / 2) + 1.0f, y1 - 1, y2 + 1, z1, z1 + 0.6);
	tableLeg(x1 - 1, x2 + 1, ((y2 + y1) / 2) - 1, ((y2 + y1) / 2) + 1, z1, z1 + 0.6);
	glPopMatrix();
}

void furnece() {
	glColor4f(1.0f, 1.0f, 1.0f, 0.1f);
	tableLeg(-25, 1, -35, 31, -30, -20);

	glColor4f(0.5f, 0.35f, 0.05f, 1.0f);
	tableLeg(-28, 4, -35, -28, -30, -18);

	tableLeg(-28, 4, -10, -8, -30, -18);
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


}


void chair()
{
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
}
void tableWithChair()
{
	glScalef(1.5, 1.5, 1.5);
	glPushMatrix();

	glColor4f(0.5f, 0.35f, 0.05f, 1.0f);
	table();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 0, 20);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
	glRotatef(180.0f, 0.0, 1.0, 0.0);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, 0, 0);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 0, 11);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glRotatef(180.0f, 0.0, 1.0, 0.0);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, 0, 10);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	chair();
	glPopMatrix();

	glPushMatrix();
	glRotatef(270, 0, 1, 0);
	glTranslatef(20, 0, -15);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0, 8);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glRotatef(90.0f, 0.0, 1.0, 0.0);
	chair();
	glPopMatrix();


}

void clock()
{

	//glRotatef(-30.0f, 1.0, 0.0, 0.0);
	//glRotatef(120.0f, 0.0, 1.0, 0.0);
	//glRotatef(-20.0f, 0.0, 0.0, 1.0);

	glScalef(5, 5, 5); //make big

	GLfloat radius = 1;
	GLfloat radiusBig = 1.05;
	glEnable(GL_POINT_SIZE);
	glPointSize(5);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_LINE_SMOOTH);

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
}

void wall(float x1, float x2, float y1, float y2, float z1, float z2) {

	glPushMatrix();
	glRotatef(-30.0f, 1.0, 0.0, 0.0);
	glRotatef(135.0f, 0.0, 1.0, 0.0);

	// BACK
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 0.0f, 0.1f);
	glVertex3f(x2, y2, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);
	glEnd();

	// bottom
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 0.1f);
	glVertex3f(x1, y1, z2);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x2, y1, z2);
	glEnd();

	// left
	glBegin(GL_POLYGON);
	glColor4f(0.0f, 0.0f, 1.0f, 0.1f);
	glVertex3f(x1, y1, z2);
	glVertex3f(x1, y2, z2);
	glVertex3f(x1, y2, z1);
	glVertex3f(x1, y1, z1);
	glEnd();

	//door
	glBegin(GL_POLYGON);
	glColor4f(0.0f, 1.0f, 0.0f, 0.1f);
	glVertex3f(x1 + 0.1, -30, 26);
	glVertex3f(x1 + 0.1, 20, 26);
	glVertex3f(x1 + 0.1, 20, 10);
	glVertex3f(x1 + 0.1, -30, 10);
	glEnd();

	//door frame
	glColor4f(0.0f, 1.0f, 1.0f, 0.1f);
	tableLeg(x1, x1 + 0.1, -30, 21, 26, 27);
	tableLeg(x1, x1 + 0.1, -30, 21, 9, 10);
	tableLeg(x1, x1 + 0.1, 20, 21, 10, 26);

	//window
	window(10, 40, -5, 20, -29);

	//furnace
	furnece();



	glPopMatrix();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//table with 4 chairs
	glPushMatrix();
	glRotatef(-30.0f, 1.0, 0.0, 0.0);
	glRotatef(135.0f, 0.0, 1.0, 0.0);
	glTranslatef(25, -10, -10);
	tableWithChair();
	glPopMatrix();

	//bulb();

	//walls
	glPushMatrix();
	wall(-30.0, 45.0, -30.0, 30.0, -30.0, 32.0);
	glPopMatrix();

	//wallClock
	glPushMatrix();
	glTranslatef(10, 25, 14);
	clock();
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

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);       // Enable the Depht preception as well
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("OpenGL 3D Introduction");
	glutDisplayFunc(display);
	glutReshapeFunc(changeSize);
	glutTimerFunc(1000, Timer1, 2);
	glutTimerFunc(10000, Timer2, 3);
	glutTimerFunc(500, Timer3, 4);
	init();
	glutMainLoop();


	return 0;
}


