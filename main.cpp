/////////////////////////////////
// box.cpp
//
// This program draws a wire box.
//
// Sumanta Guha.
/////////////////////////////////

#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

int Xangle = 0;  int Yangle = 0; int Zangle = 0; int rotateDoor = 0; float door = 0.0; float maju = 10.0;

void drawBlock(float x, float X, float y, float Y, float z, float Z)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex3f(x, y, z);
	glVertex3f(x, Y, z);
	glVertex3f(X, Y, z);
	glVertex3f(X, y, z);

	glVertex3f(x, y, Z);
	glVertex3f(x, Y, Z);
	glVertex3f(X, Y, Z);
	glVertex3f(X, y, Z);

	glVertex3f(x, Y, z);
	glVertex3f(x, Y, Z);
	glVertex3f(X, Y, Z);
	glVertex3f(X, Y, z);

	glVertex3f(x, y, z);
	glVertex3f(x, y, Z);
	glVertex3f(X, y, Z);
	glVertex3f(X, y, z);

	glVertex3f(x, y, z);
	glVertex3f(x, y, Z);
	glVertex3f(x, Y, Z);
	glVertex3f(x, Y, z);

	glVertex3f(X, y, z);
	glVertex3f(X, y, Z);
	glVertex3f(X, Y, Z);
	glVertex3f(X, Y, z);
	glEnd();
}
void drawLine(float x, float X, float y, float Y, float z, float Z)
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_LINE_STRIP);
	glVertex3f(x, y, z);
	glVertex3f(x, Y, z);
	glVertex3f(X, Y, z);
	glVertex3f(X, y, z);
	glVertex3f(x, y, z);

	glVertex3f(x, y, Z);
	glVertex3f(x, Y, Z);
	glVertex3f(X, Y, Z);
	glVertex3f(X, y, Z);
	glVertex3f(x, y, Z);

	glVertex3f(x, Y, z);
	glVertex3f(x, Y, Z);
	glVertex3f(X, Y, Z);
	glVertex3f(X, Y, z);
	glVertex3f(x, Y, z);

	glVertex3f(x, y, z);
	glVertex3f(x, y, Z);
	glVertex3f(X, y, Z);
	glVertex3f(X, y, z);
	glVertex3f(x, y, z);

	glVertex3f(x, y, z);
	glVertex3f(x, y, Z);
	glVertex3f(x, Y, Z);
	glVertex3f(x, Y, z);
	glVertex3f(x, y, z);

	glVertex3f(X, y, z);
	glVertex3f(X, y, Z);
	glVertex3f(X, Y, Z);
	glVertex3f(X, Y, z);
	glVertex3f(X, y, z);
	glEnd();
}

void drawDoorDetail(float x, float X, float y, float Y, float z, float Z)
{
	glBegin(GL_LINE_STRIP);
	glVertex3f(x + 1, y, z);
	glVertex3f(x + 1, Y, z);
	glVertex3f(X - 1, Y, z);
	glVertex3f(X - 1, y, z);

	glVertex3f(x + 1, y, Z);
	glVertex3f(x + 1, Y, Z);
	glVertex3f(X - 1, Y, Z);
	glVertex3f(X - 1, y, Z);
	glEnd();

	for (float i = 0.4; i < Y; i += 3.4)
	{
		glBegin(GL_LINE_STRIP);
		glVertex3f(x + 1, y + i, z);
		glVertex3f(X - 1, y + i, z);
		glVertex3f(x + 1, y + i, Z);
		glVertex3f(X - 1, y + i, Z);
		glEnd();
	}
}
// Drawing routine.
void drawScene(void)
{
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(95.0, 95.0, 88.0);
	glLoadIdentity();

	glTranslatef(-1.0, -2.0, -maju);

	glRotatef(Xangle, 1.0, 0.0, 0.0);
	glRotatef(Yangle, 0.0, 1.0, 0.0);
	glRotatef(Zangle, 0.0, 0.0, 1.0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_QUADS);
	glVertex3f(-100.0, 0, 100.0);
	glVertex3f(-100.0, 0, -100.0);
	glVertex3f(100.0, 0, -100.0);
	glVertex3f(100.0, 0, 100.0);
	glEnd();

	/*for (float x = -100.0; x < 100; x += 0.5)
	{
		for (float z = -100.0; z < 1.0; z += 0.5)
		{
			glBegin(GL_LINE_STRIP);
			glVertex3f(x, -0.5, -1.0);
			glVertex3f(x, -0.5, -100.0);
			glEnd();
			glBegin(GL_LINE_STRIP);
			glVertex3f(-100.0, -0.5, z);
			glVertex3f(100.0, -0.5, z);
			glEnd();
		}
	}*/
	glColor3ub(215.0, 215.0, 210.0);
	drawBlock(-20.0, -4.0, 0.0, 25.0, -1.0, -2.5);
	drawBlock(8.0, 22.0, 0.0, 25.0, -1.0, -2.5);
	drawBlock(-4.0, 8.0, 18.03, 25.0, -1.0, -2.5);
	glColor3f(0.0, 0.0, 0.0);
	drawLine(-20.0, -4.0, 0.0, 25.0, -1.0, -2.501);
	drawLine(8.0, 22.0, 0.0, 25.0, -1.0, -2.501);
	drawLine(-4.0, 8.0, 18.03, 25.0, -1.0, -2.501);

	glColor3ub(40.0, 40.0, 34.0);
	drawBlock(-4.0, 0.0, 0.0, 18.0, -1.2, -2.3);
	glColor3f(1.0, 1.0, 1.0);
	drawDoorDetail(-4.0, 0.0, 0.0, 18.0, -1.2, -2.3);
	glColor3f(0.0, 0.0, 0.0);
	drawLine(-4.0, 0.0, 0.0, 18.0, -1.2, -2.301);

	glColor3ub(40.0, 40.0, 34.0);
	glTranslatef(-door * 3, 0.0, door);
	glRotatef(rotateDoor, 0.0, -1.0, 0.0);
	drawBlock(0.0, 8.0, 0.0, 18.0, -1.2, -2.3);
	glColor3f(1.0, 1.0, 1.0);
	drawDoorDetail(0.0, 8.0, 0.0, 18.0, -1.2, -2.301);
	glColor3f(0.0, 0.0, 0.0);
	drawLine(0.0, 8.0, 0.0, 18.0, -1.2, -2.301);

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glFrustum(-3.0, 3.0, -2.0, 3.0, 1.0, 25.0);
	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case ' ':
		if (rotateDoor == 0) rotateDoor = 115, door = -2.22;
		else rotateDoor = 0, door = 0;
		glutPostRedisplay();
		break;
	case 'x':
		Xangle += 2.5;
		if (Xangle > 360.0) Xangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'y':
		Yangle += 2.5;
		if (Yangle > 360.0) Yangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'z':
		Zangle += 2.5;
		if (Zangle > 360.0) Zangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'r':
		Xangle = 0; Yangle = 0; Zangle = 0; maju = 10.0;
		glutPostRedisplay();
		break;
	case 'w':
		maju--;
		glutPostRedisplay();
		break;
	case 's':
		maju++;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void consoleText()
{
	std::cout << "\nTekan x untuk memutar sumbu X\n";
	std::cout << "Tekan y untuk memutar sumbu Y\n";
	std::cout << "Tekan z untuk memutar sumbu Z\n";
	std::cout << "Tekan r untuk mengatur ulang\n";
	std::cout << "Tekan w untuk maju\n";
	std::cout << "Tekan s untuk mundur\n";
	std::cout << "Tekan spasi untuk membuka pintu\n";
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);

	consoleText();

	glutCreateWindow("box.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}