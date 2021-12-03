
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

double cameraX = 0;
double cameraY = 0.7;
double cameraZ = 1.5;
// fence variables
double fence_R = 0.5;
double fence_G = 0.2;
double fence_B = 0;
bool fenceM = false;
double fenceRot = 0;
//gate variables 
double gateY = 0;
bool gateD = false;
//snowman 
double snowX = 1;
double snowY = 1;
double snowZ = 1;
bool snowM = false;
bool small = false;

//present variables+
double present1_y = 0.07;
double present2_y = 0.07;
double present3_y = 0.07;
double presentRot = 0;
bool p1Taken = false;
bool p2Taken = false;
bool p3Taken = false;
bool rotating = false;

// lantern variables
double lantern_rot = 0;
double lantern_x = 0;
bool L_pressed = false;
double lantern_R = 1;
double lantern_G = 0.9;
double lantern_B = 0.7;
double lanternLeg_R = 0.7;
double lanternLeg_G = 0.4;
double lanternLeg_B = 0.3;
bool J_pressed = false;
bool returning = false;

//player variables
double player_x=0;
double player_y=0.3;
double player_z=0;
double playerRotR = 0;
double playerRotL = 0;
bool lookingForward = true;
bool lookingBack = false;
bool lookingRight = false;
bool lookingLeft = false;
bool flying = false;

double wx = 0;
double wy = 0.5;
double wy2 = 0.5;
double wz = 0;
double wRot = 0;
bool won = false;
bool lost = false;
double randomRot = 0;

double rainRandx = 0;
double rainY = 0.5;
double rainRandz = 0;
//void setupLights() {
//	GLfloat ambient[] = { 0.7f, 0.7f, 0.7, 1.0f };
//	GLfloat diffuse[] = { 0.6f, 0.6f, 0.6, 1.0f };
//	GLfloat specular[] = { 1.0f, 1.0f, 1.0, 1.0f };
//	GLfloat shininess[] = { 50 };
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
//
//	GLfloat lightIntensity[] = { 0.4f, 0.4f, 1, 1.0f };
//	GLfloat lightPosition[] = { -7.0f, 6.0f, 3.0f, 0.0f };
//	glLightfv(GL_LIGHT0, GL_POSITION, lightIntensity);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightIntensity);
//}

void setupCamera() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-0.5, 0.5, -0.5, 0.5, -1, 1);
	gluPerspective(60, 640 / 480, 0.001, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraX, cameraY,cameraZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void ground() {
	glColor3d(1, 1, 1);
	glPushMatrix();
	glTranslated(0, 0.01, 0);
	glScaled(1.3, 0.01, 1.3);
	glutSolidCube(1);
	glPopMatrix();
}

void verticalB(double shift) {
	glPushMatrix();
	glTranslated(-0.6 + shift, 0.15, -0.6);
	glRotated(fenceRot, 1, 0, 0);
	glScaled(1, 3, 0.1);
	glutSolidCube(0.1);
	glPopMatrix();
}
void horizontalB(double shift) {
	glPushMatrix();
	glTranslated(-0.45 + shift, 0.15, -0.6);
	glRotated(fenceRot, 1, 0, 0);
	glScaled(2, 1, 0.1);
	glutSolidCube(0.1);
	glPopMatrix();
}

void fence(){
	glColor3d(fence_R, fence_G, fence_B);
	verticalB(0);
	horizontalB(0);
	verticalB(0.2);
	horizontalB(0.2);
	verticalB(0.4);
	horizontalB(0.4);
	verticalB(0.6);
	horizontalB(0.6);
	verticalB(0.8);
	horizontalB(0.8);
	verticalB(1);
	horizontalB(1);
	verticalB(1.2);
	
	

}
void snowman() {
	//Large ball
	glPushMatrix();
	glTranslated(-0.4, 0.1, -0.4);
	glColor3d(1, 1, 1);
	glScaled(snowX, snowY, snowZ);
	glutSolidSphere(0.11,15,50);
	glPopMatrix();
	//medium ball
	glPushMatrix();
	glTranslated(-0.4, 0.23, -0.4);
	glColor3d(1, 1, 1);
	glScaled(snowX, snowY, snowZ);
	glutSolidSphere(0.08, 15, 50);
	glPopMatrix();
	//small ball
	glPushMatrix();
	glTranslated(-0.4, 0.33, -0.4);
	glColor3d(1, 1, 1);
	glScaled(snowX, snowY, snowZ);
	glutSolidSphere(0.06, 15, 50);
	glPopMatrix();
	//nose
	glPushMatrix();
	glTranslated(-0.4, 0.34, -0.4);
	glColor3d(1, 0.3, 0);
	glScaled(snowX, snowY, snowZ);
	glutSolidCone(0.02, 0.15, 50,20);
	glPopMatrix();
	//eyes
	//left
	glPushMatrix();
	glTranslated(- 0.415, 0.36, -0.35);
	glColor3d(0, 0, 0);
	glScaled(snowX, snowY, snowZ);
	glutSolidSphere(0.009, 15, 50);
	glPopMatrix();
	//right
	glPushMatrix();
	glTranslated(- 0.385, 0.36, -0.35);
	glColor3d(0, 0, 0);
	glScaled(snowX, snowY, snowZ);
	glutSolidSphere(0.009, 15, 50);
	glPopMatrix();

	//hat
	glColor3d(0.9, 0, 0);
	glPushMatrix();
	glTranslated(-0.4, 0.38, -0.4);
	glRotated(-90, 1, 0, 0);
	glScaled(snowX, snowY, snowZ);
	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluCylinder(qobj, 0.05, 0.05, 0.05, 8, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.4, 0.38 + 0.05, -0.4);
	glScaled(snowX, snowY, snowZ);
	glScaled(1.1, 0.01, 1.1);
	glutSolidSphere(0.05, 10, 10);
	glPopMatrix();

	glColor3d(0, 0, 0);
	glPushMatrix();
	glTranslated(-0.4, 0.38, -0.4);
	glScaled(snowX, snowY, snowZ);
	glScaled(1.1, 0.01, 1.1);
	glutSolidSphere(0.065, 10, 10);
	glPopMatrix();

	
}

void present1() {
	glPushMatrix();
	glTranslated(0, present1_y, -0.3);
	glColor3d(0.9, 0, 0);
	glRotated(presentRot, 0, 1, 0);
	glutSolidCube(0.1);
    glPopMatrix();

	glPushMatrix();
	glColor3d(1, 0.9, 0);
	glTranslated(0, present1_y+0.05, -0.3);
	glScaled(1.01, 0.1, 1.01);
	glRotated(presentRot, 0, 1, 0);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(0.9, 0, 0);
	glTranslated(0, present1_y + 0.06, -0.3);
	glRotated(presentRot, 0, 1, 0);
	glScaled(1.01, 0.01, 0.3*1.01);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(0.9, 0, 0);
	glTranslated(0, present1_y + 0.06, -0.3);
	glRotated(presentRot, 0, 1, 0);
	glRotated(90, 0, 1, 0);
	glScaled(1.01, 0.01, 0.3 * 1.01);
	glutSolidCube(0.1);
	glPopMatrix();

}

void present2() {
	glPushMatrix();
	glTranslated(-0.5, present2_y, 0.5);
	glColor3d(0.2, 0.6, 0);
	glRotated(presentRot, 0, 1, 0);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(0.8, 0, 0);
	glTranslated(-0.5, present2_y + 0.05, 0.5);
	glScaled(1.01, 0.1, 1.01);
	glRotated(presentRot, 0, 1, 0);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(0.7, 1, 0.3);
	glTranslated(-0.5, present2_y + 0.06, 0.5);
	glRotated(presentRot, 0, 1, 0);
	glScaled(1.01, 0.01, 0.3*1.01);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(0.7, 1, 0.3);
	glTranslated(-0.5, present2_y + 0.06, 0.5);
	glRotated(presentRot, 0, 1, 0);
	glRotated(90, 0, 1, 0);
	glScaled(1.01, 0.01, 0.3 * 1.01);
	glutSolidCube(0.1);
	glPopMatrix();
}

void present3() {
	glPushMatrix();
	glTranslated(0.5, present3_y, 0.5);
	glColor3d(0.2, 0.2, 0.6);
	glRotated(presentRot, 0, 1, 0);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(0.5, 0.6, 1);
	glTranslated(0.5, present3_y + 0.05, 0.5);
	glScaled(1.01, 0.1, 1.01);
	glRotated(presentRot, 0, 1, 0);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1, 0.9, 0);
	glTranslated(0.5, present3_y + 0.06, 0.5);
	glRotated(presentRot, 0, 1, 0);
	glScaled(1.01, 0.01, 0.3*1.01);
	glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
	glColor3d(1, 0.9, 0);
	glTranslated(0.5, present3_y + 0.06, 0.5);
	glRotated(presentRot, 0, 1, 0);

	glRotated(90, 0, 1, 0);
	glScaled(1.01, 0.01, 0.3 * 1.01);
	glutSolidCube(0.1);
	glPopMatrix();


}

void loadpresent() {
	glPushMatrix();
	if (!p1Taken)
	present1();
	if (!p2Taken)
	present2();
	if(!p3Taken)
	present3();
	glPopMatrix();
	glutPostRedisplay();
}

void toriiGateLeg() {
	glPushMatrix();
	glScaled(0.2, 3, 0.2);
	glutSolidCube(0.2);
	glPopMatrix();
}

void toriiGate() {
	//right
	glPushMatrix();
	glColor3d(0.8, 0, 0);
	glTranslated(0.25+0.15, 0.3+gateY, 0);
	toriiGateLeg();
	glPopMatrix();
	//left
	glPushMatrix();
	glColor3d(0.8, 0, 0);
	glTranslated(-0.25+0.15, 0.3+gateY, 0);
	toriiGateLeg();
	glPopMatrix();
	//down
	glPushMatrix();
	glColor3d(0.8, 0, 0);
	glTranslated(0.15, 0.5+gateY, 0);
	glRotated(90, 0, 0, 1);
	toriiGateLeg();
	glPopMatrix();
	//up -red
	glPushMatrix();
	glColor3d(0.8, 0, 0);
	glTranslated(0.15, 0.6+gateY, 0);
	glScaled(1, 1, 1.05);
	glRotated(90,0,0,1);
	toriiGateLeg();
	glPopMatrix();

	//up -black
	glPushMatrix();
	glColor3d(0, 0, 0);
	glTranslated(0.15, 0.62+gateY, 0);
	glScaled(1.01, 0.2, 1.1);
	glRotated(90, 0, 0, 1);
	toriiGateLeg();
	glPopMatrix();

	//plate 
	glPushMatrix();
	glColor3d(0.6,0.5,0.5);
	glTranslated(0.15, 0.58+gateY, 0.04);
	glRotated(90, 0, 1, 0);
	glScaled(0.01, 1.2, 0.4);
	glutSolidCube(0.1);
	glPopMatrix();

}

void lanternleg() {
	glColor3d(lanternLeg_R, lanternLeg_G, lanternLeg_B);
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glScaled(1, 1.5, 1);
	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluCylinder(qobj, 0.01, 0.01, 0.5, 8, 8);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.14, 0.5, 0);
	glScaled(1, 1.5, 1);
	glRotated(-90, 0, 1, 0);
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluCylinder(qobj, 0.01, 0.01, 0.15, 8, 8);
	glPopMatrix();

	//base
	glPushMatrix();
	glRotated(-90, 1, 0, 0);
	glutSolidCone(0.1,0.06,10,8);
	glPopMatrix();
}

void lanternBody() {
	glColor3d(lantern_R, lantern_G, lantern_B);
	glPushMatrix();
	glTranslated(0, 0.4, 0);
	glScaled(0.03, 0.03, 0.03);
	glutSolidDodecahedron();
	glPopMatrix();
}

void lantern() {
	// first
	glPushMatrix();
	glTranslated( - 0.4+lantern_x, 0, 0.1);
	glRotated(lantern_rot, 0, 1, 0);
	lanternBody();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.5+lantern_x,0,0.1);
	lanternleg();
	glPopMatrix();

	// second
	glPushMatrix();
	glTranslated(0.4- lantern_x, 0, 0.1);
	glRotated(lantern_rot, 0, 1, 0);
	lanternBody();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5- lantern_x, 0, 0.1);
	glRotated(180, 0, 1, 0);
	lanternleg();
	glPopMatrix();

	// third
	glPushMatrix();
	glTranslated(-0.4 + lantern_x, 0, 0.1+0.23);
	glRotated(lantern_rot, 0, 1, 0);
	lanternBody();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-0.5+ lantern_x, 0, 0.1 + 0.23);
	lanternleg();
	glPopMatrix();

	// forth
	glPushMatrix();
	glTranslated(0.4- lantern_x, 0, 0.1 + 0.23);
	glRotated(lantern_rot, 0, 1, 0);
	lanternBody();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.5- lantern_x, 0, 0.1 + 0.23);
	glRotated(180, 0, 1, 0);
	lanternleg();
	glPopMatrix();
}

void player_eyes() {
	//white left 
	glPushMatrix();
	glColor3d(1, 1, 1);
	if (lookingForward)
	   glTranslated(player_x - 0.0153, player_y, player_z + 0.04);
	else if (lookingBack)
		glTranslated(player_x - 0.0153, player_y, player_z - 0.04);
	else if (lookingRight) {
		glTranslated(player_x + 0.04 , player_y, player_z - 0.0153);
		glRotated(playerRotR, 0, 1, 0);
	}
	else {
		glTranslated(player_x - 0.04, player_y, player_z - 0.0153);
		glRotated(playerRotR, 0, 1, 0);
	}
	glScaled(1, 1, 0.2);
	glutSolidSphere(0.012, 15, 50);
	glPopMatrix();
	//black left
	glPushMatrix();
	glColor3d(0, 0, 0);
	if (lookingForward)
	   glTranslated(player_x - 0.0153, player_y, player_z + 0.041);
	else if (lookingBack)
		glTranslated(player_x - 0.0153, player_y, player_z - 0.041);
	else if (lookingRight) {
		glTranslated(player_x + 0.041, player_y, player_z - 0.0153);
		glRotated(playerRotR, 0, 1, 0);
	}
	else {
		glTranslated(player_x - 0.041, player_y, player_z - 0.0153);
		glRotated(playerRotR, 0, 1, 0);
	}
	glScaled(0.8, 0.8, 0.2);
	glutSolidSphere(0.01, 15, 50);
	glPopMatrix();

	//white right 
	glPushMatrix();
	glColor3d(1, 1, 1);
	if (lookingForward)
	  glTranslated(player_x + 0.0153, player_y, player_z + 0.04);
	else if (lookingBack)
		glTranslated(player_x + 0.0153, player_y, player_z - 0.04);
	else if (lookingRight) {
		glTranslated(player_x + 0.04, player_y, player_z + 0.0153);
		glRotated(playerRotR, 0, 1, 0);
	}
	else {
		glTranslated(player_x - 0.04, player_y, player_z + 0.0153);
		glRotated(playerRotR, 0, 1, 0);
	}
	glScaled(1, 1, 0.2);
	glutSolidSphere(0.012, 15, 50);
	glPopMatrix();
	//black right
	glPushMatrix();
	glColor3d(0, 0, 0);
	if (lookingForward)
	   glTranslated(player_x + 0.0153, player_y, player_z + 0.041);
	else if (lookingBack)
		glTranslated(player_x + 0.0153, player_y, player_z - 0.041);
	else if (lookingRight) {
		glTranslated(player_x + 0.041, player_y, player_z + 0.0153);
		glRotated(playerRotR, 0, 1, 0);
	}
	else {
		glTranslated(player_x - 0.041, player_y, player_z + 0.0153);
		glRotated(playerRotR, 0, 1, 0);
	}
	glScaled(0.8, 0.8, 0.2);
	glutSolidSphere(0.01, 15, 50);
	glPopMatrix();
}

void arm() {
	//left
	glColor3d(0.9, 0.7, 0.5);

	glPushMatrix();
    glTranslated(player_x-0.02, player_y-0.06, player_z);
	glRotated(-55+playerRotL, 0, 1, 0);
	glRotated(70, 1, 0, 0);
	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluCylinder(qobj, 0.008, 0.008, 0.1, 8, 8);
	glPopMatrix();

	//right
	glPushMatrix();
	glTranslated(player_x + 0.02, player_y - 0.06, player_z);
	glRotated(55+playerRotR, 0, 1, 0);
	glRotated(70, 1, 0, 0);
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluCylinder(qobj, 0.008, 0.008, 0.1, 8, 8);
	glPopMatrix();

}
void player() {
	//face 
	glPushMatrix();
	glColor3d(0.9, 0.7,0.5);
	glTranslated(player_x, player_y,player_z);
	glutSolidSphere(0.04, 15, 50);
	glPopMatrix();
	//eyes
	player_eyes();
	//chest
	glPushMatrix();
	glColor3d(0.9, 0, 0);
	glTranslated(player_x, player_y-0.07, player_z);
	if(lookingBack)
		glRotated(180, 0, 1, 0);
	else
    	glRotated(playerRotR, 0, 1, 0);
	glScaled(1.1, 1, 1);
	glutSolidSphere(0.03, 15, 50);
	glPopMatrix();

	//arm 
	arm();
	//body
	glPushMatrix();
	glColor3d(0.9, 0, 0);
	glTranslated(player_x, player_y-0.3, player_z);
	glRotated(-90, 1, 0, 0);
	glutSolidCone(0.06,0.26, 15, 50);
	glPopMatrix();

	//hair 
	glPushMatrix();
	glColor3d(0.5, 0.2, 0);
	if (lookingForward)
	   glTranslated(player_x, player_y+0.01, player_z-0.015);
	else if(lookingRight)
		glTranslated(player_x - 0.015, player_y + 0.01, player_z);
	else if (lookingLeft)
		glTranslated(player_x +0.015, player_y + 0.01, player_z);
	else
		glTranslated(player_x, player_y + 0.01, player_z + 0.015);

	glRotated(playerRotR, 0, 1, 0);
	glutSolidSphere(0.04, 10, 10);
	glPopMatrix();

	//ponytail
	glPushMatrix();
	glColor3d(0.5, 0.2, 0);
	if(lookingForward)
	    glTranslated(player_x, player_y-0.05, player_z-0.05);
	else if(lookingRight)
		glTranslated(player_x-0.05, player_y - 0.05, player_z);
	else if (lookingLeft)
		glTranslated(player_x+0.05, player_y - 0.05, player_z);
	else
		glTranslated(player_x, player_y - 0.05, player_z + 0.05);

	glRotated(-90, 1, 0, 0);
	glutSolidCone(0.02, 0.07, 10, 8);
	glPopMatrix();
}
void lookRight() {
	
	playerRotR = 90;
	playerRotL = 90;
	lookingForward = false;
	lookingBack = false;
	lookingLeft = false;


	glutPostRedisplay();
}
void lookLeft() {
	
	
	playerRotR = -90;
	playerRotL = -90;
	lookingBack = false;
	lookingForward = false;
	lookingRight = false;
	glutPostRedisplay();

}
void lookForward() {
	
	playerRotL = 0;
	playerRotR = 0;
	lookingRight = false;
	lookingLeft = false;
	lookingBack = false;

	glutPostRedisplay();

}
void lookBack() {
	
	playerRotL = -90;
	playerRotR = 90;
	lookingRight = false;
	lookingLeft = false;
	lookingForward = false;

	glutPostRedisplay();

}

void key(unsigned char k, int x, int y)//keyboard function, takes 3 parameters
									// k is the key pressed from the keyboard
									// x and y are mouse postion when the key was pressed.
{
	if (k == 'l')
		L_pressed = !L_pressed;

	//camera movement
	if (k == 's')
		cameraZ += 0.1;
	if (k == 'w')
		cameraZ -= 0.1;
	if (k == 'd')
		cameraX += 0.1;
	if (k == 'a')
		cameraX -= 0.1;
	if (k == 'q')
		cameraY += 0.1;
	if (k == 'e')
		cameraY -= 0.1;

	if (k == 'z') {  //front view
		 cameraX = 0;
		 cameraY = 0.1;
		 cameraZ = 1.5;
	}
	if (k == 'x') {  //top view
		cameraX = 0;
		cameraY = 1.2;
		cameraZ = 0.1;
	}
	if (k == 'c') {  //side view
		cameraX = 1.5;
		cameraY = 0.1;
		cameraZ = 0;
	}
	if (k == 'r') {
		rotating = !rotating;
	}
	if (k == 'g') {
		flying = !flying;
	}
	if (k == 'k') {
		snowM = !snowM;
	}
	if (k == 'f') {
		fenceM = !fenceM;
	}
	if (k == 'j') {
		J_pressed = !J_pressed;
	}


	glutPostRedisplay();//redisplay to update the screen with the changes
}

void spe(int k, int x, int y)// keyboard special key function takes 3 parameters
							// int k: is the special key pressed such as the keyboard arrows the f1,2,3 and so on
{
	if (k == GLUT_KEY_RIGHT ) {
		if (lookingRight && player_x < 0.5)
		   player_x += 0.05;
		else {
			lookRight();
			lookingRight = true;
		}
	}

	if (k == GLUT_KEY_LEFT ) {
		if(lookingLeft && player_x > -0.5)
		  player_x -= 0.05;
		else {
			lookLeft();
			lookingLeft = true;
		}
	}
	if (k == GLUT_KEY_DOWN ) { //back
		if (lookingBack && player_z > -0.5)
		  player_z -= 0.05;
		else {
			lookBack();
			lookingBack = true;
		}
	}
	if (k == GLUT_KEY_UP ) { //forward
		if (lookingForward && player_z < 0.5)
	    	player_z += 0.05;
		else {
			lookForward();
			lookingForward = true;
		}
	}
	
	glutPostRedisplay();
}
void timer(int val) {
	// fence alternating colour
	if (fence_R == 0.5) {
		fence_R = 0.9;
		fence_G = 0;
		fence_B = 0;
	}
	else if (fence_R == 0.9) {
		fence_R = 0;
		fence_G = 0;
		fence_B = 0;
	}
	else {
		fence_R = 0.5;
		fence_G = 0.2;
	    fence_B = 0;
	}
	// lantern colour
	if (L_pressed) {
		if (lost && lantern_B == 0.7) {
			lantern_R = 0.5;
			lantern_G = 0;
			lantern_B = 0.5;
		}
		else if (lantern_B == 0 || (lost && lantern_B == 0.5) ) {
			lantern_R = 1;
			lantern_G = 0.9;
			lantern_B = 0.7;
		}
		else {
			lantern_R = 1;
			lantern_G = 0.6;
			lantern_B = 0;
		}
	}
	if (won)
		randomRot = rand() % 181;


	glutPostRedisplay();								
	glutTimerFunc(1000, timer, 0);
}

void shape() {
	glPushMatrix();
	glutSolidTorus(0.01, 0.02, 8, 8);
	glPopMatrix();

}
void shapeCmplx() {
	glPushMatrix();
	glTranslated(0, 0.5, 0);
	shape();
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	shape();
	glPopMatrix();

	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	shape();
	glPopMatrix();
	glPopMatrix();
}
void win() {
	glColor3d(1, 1, 0);

	glPushMatrix();
	glRotated(randomRot, 0, 1, 0);
	glPushMatrix();
	
	glTranslated(wx,wy,wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();
	glPopMatrix();

	glPushMatrix();
	glTranslated(wx, wy, -wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(-wx, wy, -wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(wx, wy, 0);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(0, wy, 0);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(0, wy, wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();
	glPushMatrix();
	glTranslated(0, wy, -wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(-wx, wy, wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(-wx, wy,0);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();
	glPopMatrix();

	
	
}
void win2() {
	
	glColor3d(0.4,0.9,1);

	glPushMatrix();
	glRotated(randomRot, 0, 1, 0);
	glPushMatrix();
	glTranslated(wx, wy2, wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();
	glPopMatrix();

	glPushMatrix();
	glTranslated(wx, wy2, -wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(-wx, wy2, -wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(wx, wy2, 0);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(0, wy2, 0);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(0, wy2, wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();
	glPushMatrix();
	glTranslated(0, wy2, -wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(-wx, wy2, wz);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();

	glPushMatrix();
	glTranslated(-wx, wy2, 0);
	glRotated(wRot, 0, 1, 0);

	shapeCmplx();

	glPopMatrix();
	glPopMatrix();


	
}

void rain() {
	glColor3d(0.6,0.6,0.5);
	
	glPushMatrix();
	glTranslated(rainRandx-0.6, rainY, rainRandz-0.6);
	glRotated(-90, 1, 0, 0);
	GLUquadricObj* qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj, GLU_FILL);
	gluCylinder(qobj, 0.004, 0.004, 0.05, 8, 8);
	glPopMatrix();
}

void loadxandz(int val) {
	rainRandx = ((rand() % 12)) * 0.1;
	rainRandz = ((rand() % 12)) * 0.1;
	glutTimerFunc(50, loadxandz, 0);

}
void lose(int val) {
	if (!won) {
		lost = true;
		lanternLeg_R = 0;
		lanternLeg_G = 0;
		lanternLeg_B = 0;
		
		glutTimerFunc(0, loadxandz, 0);
	}

}

void Display() {
	//setupLights();
	setupCamera();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	ground();
	fence();
	player();

	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	fence();
	glPopMatrix();

	glPushMatrix();
	glRotated(90, 0, 1, 0);
	fence();
    glPopMatrix();


	snowman();
	loadpresent();
	glPushMatrix();
	glTranslated(-0.15, 0, 0);
	toriiGate();
	glPopMatrix();

	lantern();
	
	if (player_x >=-0.01 && player_x<=0.01 && player_z <= -0.29 && player_z>=-0.31)
		p1Taken = true;
	if (player_x >= -0.51 && player_x<=-0.49 && player_z >= 0.49 && player_z<=0.51)
		p2Taken = true;
	if (player_x >= 0.49 && player_x<=0.51 && player_z >= 0.49 && player_z<= 0.51)
		p3Taken=true;

	if (p1Taken && p2Taken && p3Taken && !lost) {
		win();
		win2();
		won = true;
	}
	if(lost)
		for (int i = 0; i < 30; i++) {
			
			rain();
		}

	glFlush();
}
void smallBack() {
	if (snowX > 1) {
		snowX -= 0.001;
		snowY -= 0.001;
		snowZ -= 0.001;
	}
	else {
		small = false;
	}
}
void gateDown() {
	if (gateY > 0)
		gateY -= 0.0001;
	else
		gateD = false;
}
void lanternReturn() {
	if (lantern_x > 0)
		lantern_x -= 0.001;
	else
		returning = false;
}
void anim() {
	if (L_pressed) {

		lantern_rot += 0.1;
	}

	if (rotating)
		presentRot += 0.1;
	else
		presentRot = 0;
		
	if (flying) {
		if (gateY < 0.2 && !gateD) {
			gateY += 0.0001;
		}
		else {
			gateD = true;
			gateDown();
		}
	}
	else
		gateY = 0;
	if (won) {
		if(wx<0.4)
		wx += 0.001;
		if(wy>0)
		 wy -= 0.001;
		if (wy2 > -0.4)
			wy2 -= 0.001;
		if(wz<0.4)
		wz += 0.001;
		wRot += 1;
		flying=true;
		L_pressed=true;
		snowM = true;
		fenceM = true;
	}
	if (snowM) {
		if (snowX < 2 && !small) {
			snowX += 0.001;
			snowY += 0.001;
			snowZ += 0.001;
		}
		else {
			small = true;
			smallBack();
		}
	}
	else {
		snowX = 1;
		snowY =1;
		snowZ =1;
	}
	if (fenceM)
		fenceRot+= 0.1;
	else
		fenceRot = 0;
	if (lost) {
		rotating = true;
		L_pressed = true;
		
		if (present1_y < 0.2) {
			present1_y += 0.0001;
			present2_y += 0.0001;
			present3_y += 0.0001;
		}
		else {
			p1Taken = true;
			p2Taken = true;
			p3Taken = true;
		}
		if (rainY > 0) {
			rainY -= 0.01;
		}
		else {
			rainY = 0.5;
		}
		
		
	}
	if (J_pressed) {
		if (lantern_x < 0.4 && !returning)
			lantern_x += 0.001;
		else {
			returning = true;
			lanternReturn();
		}
	}
	else {
		lantern_x = 0;
	}
	glutPostRedisplay();

}

void main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);

	glutCreateWindow("Lab 5");
	glutDisplayFunc(Display);
	glutKeyboardFunc(key);
	glutIdleFunc(anim);
	glutTimerFunc(0, timer, 0);
	glutTimerFunc(20000, lose, 0);
	glutSpecialFunc(spe);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glClearColor(0.2f, 0.3f, 0.4f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glShadeModel(GL_SMOOTH);

	glutMainLoop();
}
