#include "triangle.h"

Triangle::Triangle(std::vector<Point> _points): Object(_points){}

Triangle::Triangle(std::vector<Point> _points, const Color& _color): Object(_points, _color){}

void Triangle::Draw()
{
  glBegin(GL_TRIANGLES);
  glColor3f(color.r, color.g, color.b);
  glVertex3f(points[0].x,points[0].y,points[0].z);
  glVertex3f(points[1].x,points[1].y,points[1].z);
  glVertex3f(points[2].x,points[2].y,points[2].z);
  glEnd();
}
