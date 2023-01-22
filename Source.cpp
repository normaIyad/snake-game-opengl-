#include<gl/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
int  x1 = 70, x2 = 100, y3 = 188, y4 = 188 , i=0 ;
float xr = 0, yr = 0 ,thata = 0;
int rand_x = 300 + (rand() % 101);
int rand_y = 200 + (rand() % 101);
int v1, v2;
void drawPoint(int x, int y)
{
	glPointSize(11.0);
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void specialkey(int key, int x, int y) {
	if (xr != 300 && xr != -10 && yr != -70 && yr != 142
		&& xr != rand_x && yr != rand_y) {
		switch (key) {
		case GLUT_KEY_UP:
			yr++;
			if (thata == 0) {
				thata = 90;	}
			glutPostRedisplay();
			cout << "yr++" << yr++
				<< "rand x " << rand_x
				<< "rand y " << rand_y
				<< endl;
			i = 1;
			break;
		case GLUT_KEY_DOWN:
			yr--;
			if (thata == 0) {
				thata = 90; }
			glutPostRedisplay();
			cout << "yr--"
				<< yr-- << endl;
			i = 2;
			break;
		case GLUT_KEY_RIGHT:
			xr++;
			if (thata == 90) {
				thata = 0; }
			glutPostRedisplay();
			cout << "xr++"
				<< xr++ << endl;
			i = 3;
			break;
		case GLUT_KEY_LEFT:
			xr--;
			if (thata == 90) {
				thata = 0;}
			glutPostRedisplay();
			cout << "xr--"
				<< xr-- << endl;
			i = 4;
			break;
		}
	}
	switch (i) {
	case 1:
		yr--; 
		break;
	case 2:
		yr++;
		break;
	case 3:
		xr--;
		break;
	case 4:
		xr++;
		break;
	}
	if ((rand_x == x1 + xr && rand_y == y4 + yr  ) ||
		(rand_x == x2 + xr && rand_y == y3 + yr)) {
		rand_x = 200 + (rand() % 101);
		rand_y = 200 + (rand() % 101);
	}
}
void D_SEC() {
	glColor3f(0.545, 0.271, 0.075);
	glBegin(GL_QUADS);
	glVertex2f(20, 80);
	glVertex2f(380, 80);
	glVertex2f(380, 350);
	glVertex2f(20, 350);
	glEnd();
}
void D_SEC2() {
	glColor3f(0.35, 0, 0.50);
	glBegin(GL_QUADS);
	glVertex2f(30, 90);
	glVertex2f(370, 90);
	glVertex2f(370, 340);
	glVertex2f(30, 340);
	glEnd();
}
void Snake() {
	glPushMatrix();
	glLineWidth(10);
	glTranslatef((x1 + xr), (y4 + yr), 0);
	glRotatef(thata, 0, 0, 1);
	glTranslatef(-(x2 + xr), -(y3 + yr), 0);
	glBegin(GL_LINE_LOOP);
	glColor3f(1,1,0);
	glVertex2i(x1 + xr, y4 + yr);
    glColor3f(1, 1, 1);
	glVertex2i(x2 + xr, y3 + yr);
	glEnd();
	glPopMatrix();
}
void text() {
	glColor3f(1, 1, 1);
	glRasterPos2i(40,370);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'G');
	glColor3f(1, 1, 1);
	glRasterPos2i(50, 370);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'A');
	glColor3f(1, 1, 1);
	glRasterPos2i(60, 370);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'M');
	glColor3f(1, 1, 1);
	glRasterPos2i(70, 370);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'E');
	glColor3f(1.0, 1, 1);
	glRasterPos2i(70, 380);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'S');
	glColor3f(1, 1, 1);
	glRasterPos2i(40, 380);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'N');
	glColor3f(1, 1, 1);
	glRasterPos2i(50, 380);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'A');
	glColor3f(1, 1, 1);
	glRasterPos2i(60, 380);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'K');
	glColor3f(1.0, 1, 1);
	glRasterPos2i(70, 380);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'E');
	glColor3f(1.0, 1, 1);
	glRasterPos2i(80, 380);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'N');
	glColor3f(1.0, 1, 1);
	glRasterPos2i(90, 380);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'O');
	glColor3f(1.0, 1, 1);
	glRasterPos2i(100, 380);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'R');
	glColor3f(1.0, 1, 1);
	glRasterPos2i(110, 380);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'M');
	glColor3f(1.0, 1, 1);
	glRasterPos2i(120, 380);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, 'A');
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	D_SEC();
	D_SEC2();
	Snake();
	text();
	glColor3f(1.0, 1.0, 1.0);
	drawPoint(rand_x +v1, rand_y +v2  );
	glFlush();
	glutSwapBuffers();
}
void init() {
	glClearColor(0.000, 0.392, 0.000,0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(10,400,10,400);
}
int main(int s, char** a) {
	glutInit(&s, a);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
	glutInitWindowPosition(600, 60);
	glutInitWindowSize(800, 800);
	glutCreateWindow("snake game ");
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(specialkey);
	glutMainLoop();
	return 0;
}

