#include <iostream>
#include <vector>
#include <GL/glut.h>

#include "object.h"
#include "triangle.h"
#include "square.h"
#include "circle.h"
#include "color.h"
#include "point.h"
#include "init.h"


void MouseEvent(int button, int state, int x, int y){
   std::cout<< "button: " << button << "\t State: "<< state << "\t x: "<< x << "\t y: "<< y << std::endl;
   glutPostRedisplay();
}


std::vector<Object*> vect;

static void DrawFigure() {
   std::cout << "DrawFigure" << std::endl;
   glClearColor(1.0,1.0,1.0,0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   for(auto item : vect){
     item->Draw();
   }
   glutSwapBuffers();
}

float left = 0.0;
float right = 2.0;
float bottom = 0.0;
float top = 2.0;
float near = -1.0;
float far = 1.0;

static void Reshape(int width, int height) {
   if(height == 0) height = 1;
   float aspect_ratio = (float)width / (float)height;

   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   if(width >= height) {
     glOrtho(left * aspect_ratio, right * aspect_ratio, bottom, top, near, far);
   } else {
     glOrtho(left, right, bottom / aspect_ratio, top / aspect_ratio, near, far);
   }
}

int main(int argc, char* argv[]) {

   glutInit(&argc, argv);

   InitMainWindow("MainWindow");

   //*************CreateFigure*************//

   std::vector<Point> points;
   points.push_back(Point(0.5,0.5,0.0));

   Circle* circle = new Circle(points,0.1,0.1);

   vect.push_back(circle);

   //*************CreateFigure*************//


   glutDisplayFunc(DrawFigure);
   glutReshapeFunc(Reshape);
   glutMouseFunc(MouseEvent);
   glutMainLoop();

   return 0;
}
