/*
* umbre.c
* Rodica Baciu - Programarea aplicatiilor grafice 3D cu OpenGL
*
*  Programul aratã cum se determina matricea pentru
*  calcularea umbrelor. Este reprezentat un cub care se roteste
*  si care aruncã o umbrã pe un plan.
*/
#include "glos.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <glaux.h>
#include <math.h>

void incarca_textura(const char* s);
void MatriceUmbra(GLfloat puncte[3][3], GLfloat pozSursa[4],
	GLfloat mat[4][4]);
void calcCoeficientiPlan(float P[3][3], float coef[4]);
void CALLBACK rot_y(void);
void CALLBACK rot_x(void);
void CALLBACK rotateR(void);
void CALLBACK dayAdd(void);
void CALLBACK fallStar(void);
void stea();
void plan(void);
void luna(void);
void racheta(void);
void steag(void);
void cinciStea(void);
void soare(void);
void planeta(void);
void initlights(void);
void CALLBACK myReshape(GLsizei w, GLsizei h);
void CALLBACK display(void);

static int yRot = 0; //unghiul de rotaþie în jurul axei y
static int xRot = 0; //unghiul de rotaþie în jurul axei x
static int rot = 0;
static int day = 0;
static int fall = 20;
					 //poziþia sursei de luminã
static GLfloat pozSursa[] = { 60.0, 200.0, -50.0, 1.0 };

void CALLBACK addRot_y(void)
{
	yRot = yRot + 10;
}

void CALLBACK minusRot_y(void)
{
	yRot = yRot - 10;
}

void CALLBACK addRot_x(void)
{
	xRot = xRot + 10;
}

void CALLBACK minusRot_x(void)
{
	xRot = xRot - 10;
}

void CALLBACK rotateR(void)
{
	rot += 10;
}

void CALLBACK dayAdd(void)
{
	day = (day + 10) % 360;
}

void CALLBACK fallStar(void)
{
	fall -= 20;
}


void stea() {
	/*  Stea */
	glColor3f(1, 1, 0);
	//colturi
	//dreapta
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	GLUquadricObj *right = gluNewQuadric();
	gluCylinder(right, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//dreapta

	//stanga
	glPushMatrix();
	glRotatef(180, 0, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj *left = gluNewQuadric();
	gluCylinder(left, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//stanga
	//top
	glPushMatrix();
	glRotatef(90, -80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *top = gluNewQuadric();
	gluCylinder(top, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//top
	//bottom
	glPushMatrix();
	glRotatef(90, 80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *bottom = gluNewQuadric();
	gluCylinder(bottom, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//bottom
	//colturi
	auxSolidSphere(10);
}

void cinciStea() {
	/*  Stea */
	glColor3f(1, 1, 0);
	//colturi
	//dreapta
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	GLUquadricObj *right = gluNewQuadric();
	gluCylinder(right, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//dreapta

	//stanga
	glPushMatrix();
	glRotatef(180, 0, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj *left = gluNewQuadric();
	gluCylinder(left, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//stanga
	//top
	glPushMatrix();
	glRotatef(90, -80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *top = gluNewQuadric();
	gluCylinder(top, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//top
	//bottom1
	glPushMatrix();
	glRotatef(65, 80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *bottom1 = gluNewQuadric();
	gluCylinder(bottom1, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();

	//bottom2
	glPushMatrix();
	glRotatef(115, 80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *bottom2 = gluNewQuadric();
	gluCylinder(bottom2, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//bottom
	//colturi
	auxSolidSphere(10);
}

void soare() {
	/*  Stea */
	glColor3f(1, 1, 0);
	//colturi
	//dreapta
	glRotatef(90, 0, 1, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	GLUquadricObj *right = gluNewQuadric();
	gluCylinder(right, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//dreapta

	//stanga
	glPushMatrix();
	glRotatef(180, 0, 0, 0);
	glBegin(GL_POLYGON);
	GLUquadricObj *left = gluNewQuadric();
	gluCylinder(left, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//stanga
	//top
	glPushMatrix();
	glRotatef(90, -80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *top = gluNewQuadric();
	gluCylinder(top, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//top
	//bottom
	glPushMatrix();
	glRotatef(90, 80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *bottom = gluNewQuadric();
	gluCylinder(bottom, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//bottom
	//diag1
	glPushMatrix();
	glRotatef(45, 80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *d1 = gluNewQuadric();
	gluCylinder(d1, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//diag1
	//diag2
	glPushMatrix();
	glRotatef(135, 80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *d2 = gluNewQuadric();
	gluCylinder(d2, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//diag2
	//diag3
	glPushMatrix();
	glRotatef(-45, 80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *d3 = gluNewQuadric();
	gluCylinder(d3, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//diag3
	//diag4
	glPushMatrix();
	glRotatef(-135, 80.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	GLUquadricObj *d4 = gluNewQuadric();
	gluCylinder(d4, 10, 0, 30.6, 100, 150);
	glEnd();
	glPopMatrix();
	//diag4
	//colturi
	auxSolidSphere(10);
}


void planeta(void) {
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glColor3f(0, 0, 1);
	GLUquadricObj *cerc = gluNewQuadric();
	gluQuadricDrawStyle(cerc, GLU_SILHOUETTE);
	gluDisk(cerc, 0, 30, 40, 40);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1, 0, 0);
	auxSolidSphere(20);
	glPopMatrix();
}


void calcCoeficientiPlan(float P[3][3], float coef[4])
{
	float v1[3], v2[3];
	float length;
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;
	//calculeazã doi vectori din trei puncte
	v1[x] = P[0][x] - P[1][x];
	v1[y] = P[0][y] - P[1][y];
	v1[z] = P[0][z] - P[1][z];

	v2[x] = P[1][x] - P[2][x];
	v2[y] = P[1][y] - P[2][y];
	v2[z] = P[1][z] - P[2][z];

	//se cacluleazã produsul vectorial al celor doi vectori
	// care reprezintã un al treilea vector perpendicular pe plan 
	// ale cãrui componente sunt chiar coeficienþii A, B, C din ecuaþia planului
	coef[x] = v1[y] * v2[z] - v1[z] * v2[y];
	coef[y] = v1[z] * v2[x] - v1[x] * v2[z];
	coef[x] = v1[x] * v2[y] - v1[y] * v2[x];
	//normalizeazã vectorul
	length = (float)sqrt((coef[x] * coef[x]) + (coef[y] * coef[y]) + (coef[z] * coef[z]));
	coef[x] /= length;
	coef[y] /= length;
	coef[z] /= length;
}
//creazã matricea care dã umbra cunoscându-se coeficienþii planului ºi 
//poziþia sursei. În mat se salveazã matricea.
void MatriceUmbra(GLfloat puncte[3][3], GLfloat pozSursa[4],
	GLfloat mat[4][4])
{
	GLfloat coefPlan[4];
	GLfloat temp;
	//determinã coeficienþii planului
	calcCoeficientiPlan(puncte, coefPlan);
	//determinã si pe D
	coefPlan[3] = -(
		(coefPlan[0] * puncte[2][0]) +
		(coefPlan[1] * puncte[2][1]) +
		(coefPlan[2] * puncte[2][2]));
	//temp=A*xL+B*yL+C*zL+D*w
	temp = coefPlan[0] * pozSursa[0] +
		coefPlan[1] * pozSursa[1] +
		coefPlan[2] * pozSursa[2] +
		coefPlan[3] * pozSursa[3];
	//prima coloanã
	mat[0][0] = temp - pozSursa[0] * coefPlan[0];
	mat[1][0] = 0.0f - pozSursa[0] * coefPlan[1];
	mat[2][0] = 0.0f - pozSursa[0] * coefPlan[2];
	mat[3][0] = 0.0f - pozSursa[0] * coefPlan[3];
	//a doua coloana
	mat[0][1] = 0.0f - pozSursa[1] * coefPlan[0];
	mat[1][1] = temp - pozSursa[1] * coefPlan[1];
	mat[2][1] = 0.0f - pozSursa[1] * coefPlan[2];
	mat[3][1] = 0.0f - pozSursa[1] * coefPlan[3];
	//a treia coloana
	mat[0][2] = 0.0f - pozSursa[2] * coefPlan[0];
	mat[1][2] = 0.0f - pozSursa[2] * coefPlan[1];
	mat[2][2] = temp - pozSursa[2] * coefPlan[2];
	mat[3][2] = 0.0f - pozSursa[2] * coefPlan[3];
	//a patra coloana
	mat[0][3] = 0.0f - pozSursa[3] * coefPlan[0];
	mat[1][3] = 0.0f - pozSursa[3] * coefPlan[1];
	mat[2][3] = 0.0f - pozSursa[3] * coefPlan[2];
	mat[3][3] = temp - pozSursa[3] * coefPlan[3];
}
void plan(void)
{
	glBegin(GL_QUADS);
	glVertex3f(400.0f, -260.0f, -600.0f);
	glVertex3f(-400.0f, -100.0f, -600.0f);
	glVertex3f(-400.0f, -260.0f, 600.0f);
	glVertex3f(400.0f, -130.0f, 600.0f);
	glEnd();
}

void luna(void) {
	GLUquadricObj *moon = gluNewQuadric();
	gluQuadricDrawStyle(moon, GLU_FILL);
	gluSphere(moon, 40, 20, 20);
	gluQuadricTexture(moon, GLU_TRUE);
	gluQuadricNormals(moon, GLU_SMOOTH);
}

void racheta(void) {
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glColor3d(0, 0, 1);
	glRotatef(180, 1, 0, 0);
	GLUquadricObj *cap = gluNewQuadric();
	gluQuadricDrawStyle(cap, GLU_FILL);
	gluCylinder(cap, 20, 0, 20.6, 100, 150);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	GLUquadricObj *corp = gluNewQuadric();
	gluQuadricDrawStyle(corp, GLU_FILL);
	gluCylinder(corp, 20, 20, 50.6, 100, 150);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2, 1, 0);
	glTranslatef(-20.5, 15, 35);
	GLUquadricObj *motor1 = gluNewQuadric();
	gluQuadricDrawStyle(motor1, GLU_FILL);
	gluCylinder(motor1, 5, 5, 20.6, 100, 150);
	glPopMatrix();

	glPushMatrix();
	glColor3f(2, 1, 0);
	glTranslatef(20.5, -15, 35);
	GLUquadricObj *motor2 = gluNewQuadric();
	gluQuadricDrawStyle(motor1, GLU_FILL);
	gluCylinder(motor2, 5, 5, 20.6, 100, 150);
	glPopMatrix();
}

void steag(void) {
	glRotatef(30, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glPushMatrix();
	glColor3f(0.5f, 0.35f, 0.05f);
	GLUquadricObj *bat = gluNewQuadric();
	gluQuadricDrawStyle(bat, GLU_FILL);
	gluCylinder(bat, 1, 1, 30.6, 100, 150);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex3f(1.0,10.0,0);
	glVertex3f(10.0, 10.0, 0);
	glVertex3f(10.0, 0.0, 0);
	glVertex3f(1.0, 0.0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(9, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 1, 0);
	glVertex3f(1.0, 10.0, 0);
	glVertex3f(10.0, 10.0, 0);
	glVertex3f(10.0, 0.0, 0);
	glVertex3f(1.0, 0.0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(18, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(1.0, 10.0, 0);
	glVertex3f(10.0, 10.0, 0);
	glVertex3f(10.0, 0.0, 0);
	glVertex3f(1.0, 0.0, 0);
	glEnd();
	glPopMatrix();
}

GLuint IDtextura;

void incarca_textura(const char* s)
{
	AUX_RGBImageRec *pImagineTextura = auxDIBImageLoad(s);

	if (pImagineTextura != NULL)
	{
		glGenTextures(1, &IDtextura);

		glBindTexture(GL_TEXTURE_2D, IDtextura);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, 3, pImagineTextura->sizeX, pImagineTextura->sizeY,
			0, GL_RGB, GL_UNSIGNED_BYTE, pImagineTextura->data);
	}

	if (pImagineTextura)
	{
		if (pImagineTextura->data)
			free(pImagineTextura->data);

		free(pImagineTextura);
	}

}

void myinit(void)
{
	GLfloat ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat mat_shininess[] = { 128.0f };

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	//permite urmãrirea culorilor
	glEnable(GL_COLOR_MATERIAL);
	//seteazã proprietãþile de material pentru a urma valorile glColor
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	//seteazã sursa		
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, pozSursa);
	//seteazã materialul	    
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glEnable(GL_DEPTH_TEST);//ascunderea suprafeþelor
}


void CALLBACK display(void)
{
	const char* sir;
	GLuint ID1;
	sir = ".\\parchet.bmp";
	incarca_textura(sir);
	ID1 = IDtextura;
	GLfloat matUmbra[4][4];
	//oricare trei puncte din plan în sens CCW
	GLfloat puncte[3][3] = { { -50.0f, -164.0f, -50.0f },
	{ -50.0, -164.0f, 50.0 },
	{ 50.0f, -164.0f, 50.0f } };
	//sterge ecranul
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//determinã matricea pentru calcularea umbrei	
	MatriceUmbra(puncte, pozSursa, matUmbra);
	//salveaza starea matricei de modelare-vizualizare si reprezintã cubul rotit
	glPushMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, pozSursa);
	glColor3f(1.0f, 0.7f, 0.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ID1);
	luna();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix(); //reface matricea initialã

				   //deseneazã umbra
				   //mai întâi se dezactiveazã iluminarea si se salveazã starea matricei de proiectie
	glPushAttrib(GL_LIGHTING_BIT);
	glDisable(GL_LIGHTING);
	glPushMatrix();
	//apoi se înmulteste matricea curentã cu matricea de umbrire
	glMultMatrixf((GLfloat*)matUmbra);
	//si cu cea de rotaþie
	//se deseneazã cubul-umbrã cu gri
	glColor3f(0.3, 0.3, 0.3);
	auxSolidSphere(30);
	glPopMatrix(); //reface matricea de proiecþie la normal

	//deseneazã sursa de luminã ca o sferã micã galbenã în poziþia realã
	glPushMatrix();
	glTranslatef(pozSursa[0], pozSursa[1], pozSursa[2]);
	glColor3f(1.0, 1.0, 0.0);
	soare();
	glPopMatrix();

	//deseneazã planul
	glColor3f(0.4, 0.4, 0.4);
	plan();

	//restaureazã starea variabilelor de iluminare
	glPopAttrib();

	//Racheta
	glPushMatrix();
	glTranslatef(-200, -50, 0);
	glTranslatef(0, yRot, 0);
	glTranslatef(xRot, 0, 0);
	glRotatef(rot, 0, 0, 1);
	racheta();
	glPopMatrix();

	//Steag
	glPushMatrix();
	glTranslatef(-300, -110, 0);
	steag();
	glPopMatrix();

	//mai multe stele
	glPushMatrix();
	glTranslatef(-60.0, 100.0, -200.0);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-200.0, 80.0, -100.0);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-300.0, fall, -100.0);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(60.0, 20.0, -100.0);
	glTranslatef(60.0, fall, -100.0);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200.0, 60.0, -100.0);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(150.0, 200.0, -70.0);
	cinciStea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(200, -20, -70);
	glColor3f(0.5f, 0.35f, 0.05f);
	auxSolidSphere(20);

	glPushMatrix();
	glRotatef(day, 0, 1, 0);

	glPushMatrix();
	glTranslatef(0, 0, 40);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -40);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(60, 0, 0);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60, 0, 0);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60, 0, 30);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-60, 0, -30);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(60, 0, -30);
	stea();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(60, 0, 30);
	stea();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(-300, -40, -40);
	planeta();
	glPopMatrix();

	glFlush();
}


void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-200.0, 200.0, -200.0*(GLfloat)h / (GLfloat)w,
			200.0*(GLfloat)h / (GLfloat)w, -200.0, 200.0);
	else
		glOrtho(-200.0*(GLfloat)w / (GLfloat)h,
			200.0*(GLfloat)w / (GLfloat)h, -200.0, 200.0, -200.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-30, -1.0f, 1.0f, 1.0f); //transformarea de vizualizare
}
int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_DEPTH16 | AUX_RGB);
	auxInitPosition(10, 10, 400, 400);
	auxInitWindow("Reprezentarea umbrelor");
	myinit();
	// inregistreaza functiile callback rot_y, rot_y
	auxKeyFunc(AUX_UP, addRot_y);
	auxKeyFunc(AUX_DOWN, minusRot_y);
	auxKeyFunc(AUX_RIGHT, addRot_x);
	auxKeyFunc(AUX_LEFT, minusRot_x);
	auxKeyFunc(AUX_r, rotateR);
	auxKeyFunc(AUX_q, dayAdd);
	auxKeyFunc(AUX_s, fallStar);
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return(0);
}
