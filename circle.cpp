#include "circle.h"

Circle::Circle(std::vector<Point> _points, float _step, float _radius): Object(_points)
{
   step = _step;
   radius = _radius;
}

Circle::Circle(std::vector<Point> _points, float _step, float _radius, const Color& _color): Object(_points, _color)
{
   step = _step;
   radius = _radius;
}

void Circle::Draw()
{
   glPushMatrix();
   glTranslatef(0.0f, 0.0f, 0.0f);

   float theta;
   float pi = acos(-1.0);

   glBegin(GL_TRIANGLE_FAN);

   for(GLfloat a = 0.0f; a < 360.0f; a += step) {
     theta = 2.0f * pi * a / 180.0f;
     glColor3f(color.r, color.g, color.b);
     glVertex3f(radius * cos(theta) + points[0].x, radius * sin(theta) + points[0].y, points[0].z);
   }

   glEnd();
   glPopMatrix();
}
