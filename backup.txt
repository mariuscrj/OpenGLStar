/*
*  planet.c
*  Programul arata cum se compun transformarile de rotatie si de translatie
*  pentru desenarea obiectelor rotite sau translatate.
*  Interactiune:  left, right, up, down
*
*/
#include "glos.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <glaux.h>

void myinit(void);
void drawPlane(void);
void CALLBACK dayAdd(void);
void CALLBACK daySubtract(void);
void CALLBACK yearAdd(void);
void CALLBACK yearSubtract(void);
void CALLBACK display(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void stea();

static int year = 0, day = 0, positionX = 0, positionY = 0;

void CALLBACK dayAdd(void)
{
	day = (day + 10) % 360;
}

void CALLBACK daySubtract(void)
{
	day = (day - 10) % 360;
}

void CALLBACK yearAdd(void)
{
	year = (year + 5) % 360;
}

void CALLBACK yearSubtract(void)
{
	year = (year - 5) % 360;
}

void CALLBACK plusX(void) {
	positionX = (positionX + 1) % 360;
}

void CALLBACK minusX(void) {
	positionX = (positionX - 1) % 360;
}

void CALLBACK plusY(void) {
	positionY = (positionY + 1) % 360;
}

void CALLBACK minusY(void) {
	positionY = (positionY - 1) % 360;
}

void CALLBACK display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLfloat position[] = { -2.0, 0.0, 0.0, 1.0 }; // pozitia susrei

	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_CULL_FACE);//activeaza eliminarea fetelor
	glCullFace(GL_BACK);//sunt eliminate fetele spate
	glPushMatrix();//pentru a nu iesi obiectele din fereastra la reapelarea functiei display()

	/*  Luna    */
	glPushMatrix();
	glTranslatef((GLfloat)positionX, 0.0, 0.0);
	glTranslatef(0.0, (GLfloat)positionY, 0.0);
	glColor3f(0.5, 1.0, 0.5);
	auxSolidSphere(1.0);
	glPopMatrix();

	//Stea
	glPushMatrix();
	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
	glTranslatef(-2.0, 0.0, 0.0);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glRotatef((GLfloat)day, 0.0, 1.0, 0.0);
	glDisable(GL_LIGHTING);
	stea();
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPopMatrix();
	glFlush();
}

void stea() {
	/*  Stea */
	glColor3f(1, 1, 0);
	//colturi
	//dreapta
	glPushMatrix();
	glBegin(GL_POLYGON);
	GLUquadricObj *right = gluNewQuadric();
	gluCylinder(right, 0.2, 0, 0.6, 30, 60);
	glEnd();
	glPopMatrix();
	//dreapta

	//stanga
	glPushMatrix();
	glRotatef(180, 0, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj *left = gluNewQuadric();
	gluCylinder(left, 0.2, 0, 0.6, 30, 60);
	glEnd();
	glPopMatrix();
	//stanga
	//top
	glPushMatrix();
	glRotatef(90, -80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *top = gluNewQuadric();
	gluCylinder(top, 0.2, 0, 0.6, 30, 60);
	glEnd();
	glPopMatrix();
	//top
	//bottom
	glPushMatrix();
	glRotatef(90, 80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *bottom = gluNewQuadric();
	gluCylinder(bottom, 0.2, 0, 0.6, 30, 60);
	glEnd();
	glPopMatrix();
	//bottom
	//colturi
	auxSolidSphere(0.2);
}

void myinit(void) {
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}


int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB | AUX_DEPTH);
	auxInitPosition(0, 0, 500, 500);
	auxInitWindow("Fortza Steaua");
	myinit();
	auxKeyFunc(AUX_LEFT, yearSubtract);
	auxKeyFunc(AUX_RIGHT, yearAdd);
	auxKeyFunc(AUX_UP, dayAdd);
	auxKeyFunc(AUX_DOWN, daySubtract);
	auxKeyFunc(AUX_1, minusX);
	auxKeyFunc(AUX_2, plusX);
	auxKeyFunc(AUX_3, plusY);
	auxKeyFunc(AUX_4, minusY);
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}
