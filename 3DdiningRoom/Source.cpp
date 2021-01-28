#include<Windows.h>
#include<GL/glut.h>
#include<math.h>

GLfloat x = 6.0f;
GLfloat y = 6.0f;
GLfloat z = 6.0f;


void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);                // Enable the Depth testig in openGL
	glEnable(GL_CULL_FACE);                 // Enable Hidden Surface Removal
	glPolygonMode(GL_FRONT, GL_FILL);       // Set the Front of the faces of the cube to be unfilled (Skeleton Model)
	glPolygonMode(GL_BACK, GL_FILL);        // Set the Back of the faces of the cube to be filled with the color

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
void table() {
	
	tableLeg(0, 10, 0, 1, 0, 20);

	tableLeg(0.5, 1.5, -7.0, 0.0, 18.5, 19.5);
	tableLeg(0.5, 1.5, -7.0, 0.0, 0.5, 1.5);
	tableLeg(8.5, 9.5, -7.0, 0.0, 18.5, 19.5);
	tableLeg(8.5, 9.5, -7.0, 0.0, 0.5, 1.5);

}

void chair() 
{	
	tableLeg(5.0, 10.0, -2.0, -2.4, 2.0, 7.5);
	//legs of chair
	tableLeg(5.0, 5.3, -2.3, -7.3, 2.0, 2.3);
	tableLeg(9.7,10.0, -2.3, -7.3, 2.0, 2.3);
	tableLeg(5.0, 5.3, -2.3, -7.3, 7.0, 7.3);
	tableLeg(9.7, 10.0, -2.3, -7.3, 7.0, 7.3);

	//supporting
	tableLeg(9.7, 10.0, -2.0, 7.0, 2, 2.3);
	tableLeg(9.7, 10.0, -2.0, 7.0, 7.5, 7.8);
	tableLeg(9.7, 10.0, 5.0, 7.0,2.0, 7.5);	
}
void tableWithChair()
{
	glPushMatrix();
	
	glColor4f(0.5f, 0.35f, 0.05f, 1.0f);
	table();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7,0,22);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glRotatef(180.0f, 0.0, 1.0, 0.0);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0, 0);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7, 0, 11);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glRotatef(180.0f, 0.0, 1.0, 0.0);
	chair();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0, 10);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
	chair();
	glPopMatrix();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//table with 4 chairs
	glPushMatrix();
	glRotatef(-30.0f, 1.0, 0.0, 0.0);
	glRotatef(30.0f, 0.0, 1.0, 0.0);
	tableWithChair();
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
		glOrtho(-40.0, 40.0, -40 / aspect_ratio, 40 / aspect_ratio, 40.0, -40.0);
	else
		glOrtho(-40.0 * aspect_ratio, 40.0 * aspect_ratio, -40.0, 40.0, 40.0, -40.0);

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
	init();
	glutMainLoop();


	return 0;
}


