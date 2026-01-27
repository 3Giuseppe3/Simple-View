/*
 *  SimpleView3
 *  Author: Giuseppe Akbari
 *  Version: 2025-11-23
 */

#include "Bezier.hpp"
#include <iostream>

extern GLint winWidth, winHeight;

Bezier::Bezier() {
	reset();
}

void Bezier::reset() {
	nCtrlPts = 0;
	nPts = 26;
}

/*  Compute binomial coefficients C[n] for given value of n, output in GLint C[] */
void Bezier::binomialCoeffs(GLint n, GLint C[]) {
	// your code, using O(n) algorithm for C_{n, i), i = 0, 1, ..., n
	GLint nf = tgamma(n + 1);
	for (int i = 0; i <= n; i++){
		GLint k = tgamma(i + 1); 
		GLint w = n - i; 
		GLint mul = tgamma(w + 1); 
		C[i] = nf/(k*mul);
	}
}
/**
 * nCtrlPts is the number of control points 
 * ctrlPts stores the coordinates of the control points 
 * u is the parameter value of the curve
 * bezPt stores the bezier point at u
 */
/*  Compute Bezier point at u, and output in Point *bezPt */
void Bezier::computeBezPt(GLfloat u, GLint nCtrlPts, Point ctrlPts[], GLint C[], Point *bezPt)
{
  // your code
  GLdouble b[nCtrlPts], x = 0, y = 0, z = 0, r; 
  GLint n = nCtrlPts  - 1; 
  if (u < .00001) {
	*bezPt = ctrlPts[0];
  }else if (u >.99999){
	*bezPt = ctrlPts[nCtrlPts];
  }else{
	r = u/(1.-u); 
	b[0] = pow(1.0-u, n); 
	for(int i = 1; i <= n; i++){
		b[i] = b[i-1]*(n-i+1)/i*r; 
	}
	for(int i = 0; i <= n; ++i){
		x += b[i]*ctrlPts[i].x;
		y += b[i]*ctrlPts[i].y;
		z += b[i]*ctrlPts[i].z;
	}
	bezPt->x = x; 
	bezPt->y = y; 
	bezPt->z = z;
  }
}

/*  Compute both Bezier point and tangent at u, and output in Point bezPt and Vector bezTan respectively*/
void Bezier::computeBezPtTan(GLfloat u, GLint nCtrlPts, Point ctrlPts[], GLint C[], Point *bezPt, Vector *bezTan)
{
// your code
	GLint n = nCtrlPts - 1, n1 = nCtrlPts - 2; 
	GLdouble b[n], x = 0, y = 0, z = 0, r; 
	if (u < .00001){
		bezTan->x = ctrlPts[1].x - ctrlPts[0].x;
		bezTan->y = ctrlPts[1].y - ctrlPts[0].y;
		bezTan->z = ctrlPts[1].z - ctrlPts[0].z;
	}else if (u > .99999){
		bezTan->x = ctrlPts[nCtrlPts - 1].x - ctrlPts[nCtrlPts - 2].x;
		bezTan->y = ctrlPts[nCtrlPts - 1].y - ctrlPts[nCtrlPts - 2].y;
		bezTan->z = ctrlPts[nCtrlPts - 1].z - ctrlPts[nCtrlPts - 2].z;
	}else{
		r = u/(1 - u); 
		b[0] = pow(1-u, n1); 
		for(int i = 0; i <= n; ++i){
			b[i] = b[i - 1]*((n1-i+1)/i)*r; 
		}
		for (int i = 0; i <= n; i++){
			x += b[i]*(ctrlPts[i+1].x - ctrlPts[i].x);
			y += b[i]*(ctrlPts[i+1].y - ctrlPts[i].y);
			z += b[i]*(ctrlPts[i+1].z - ctrlPts[i].z);
		}
		bezTan->x = n*x; 
		bezTan->y = n*y; 
		bezTan->z = n*z;
	}
}


/* call to compute the sequence of points on Bezier curve for drawing Bezier curve */
void Bezier::computeBezCurvePts() {
	GLfloat u = 0;
	GLint C[nCtrlPts];
	binomialCoeffs(nCtrlPts-1, C);
	for (int k = 0; k < nPts; k++) {
		u = GLfloat(k) / GLfloat(nPts-1);
		computeBezPt(u, nCtrlPts, ctrlPts, C, &Pts[k]);
	}
}


/* call to compute the sequence of points and tangents on Bezier curve for mesh of rotating Bezier curve */
void Bezier::computeBezPtsTan(GLint npts, Point pts[], Vector tangents[]) {
	GLfloat u = 0;
	GLint C[nCtrlPts];
	binomialCoeffs(nCtrlPts-1, C);
	for (int k = 0; k < npts; k++) {
		u = GLfloat(k) / GLfloat(npts-1);
		computeBezPtTan(u, nCtrlPts, ctrlPts, C, &pts[k],  &tangents[k]);
	}
}


void Bezier::drawCPts() {
	glPointSize(3.0);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < nCtrlPts; i++) {
		// std::cout<<"pt["<<i<<"] = ("<<ctrlPts[i].x<<","<<ctrlPts[i].y<<")"<<std::endl;
		glVertex2f(ctrlPts[i].x, ctrlPts[i].y);
	}
	glEnd();
}

/* display Control points in 2D view */
void Bezier::displayCPts() {
	set2DView(-winWidth / 2, winWidth / 2, -winHeight / 2, winHeight / 2);
	drawCPts();
}

/* display Control points and curve in 2D view */
void Bezier::display() {
	set2DView(-winWidth / 2, winWidth / 2, -winHeight / 2, winHeight / 2);
	drawCPts();
	drawCurve();
}

