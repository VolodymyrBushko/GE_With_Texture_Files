#include "square.h"

Square::Square(std::vector<Point> _points): Object(_points){}

Square::Square(std::vector<Point> _points, const Color& _color): Object(_points,_color){}

void Square::Draw()
{
  glBegin(GL_POLYGON);
  glColor3f(color.r, color.g, color.b);
  glVertex3f(points[0].x,points[0].y,points[0].z);
  glVertex3f(points[1].x,points[1].y,points[1].z);
  glVertex3f(points[2].x,points[2].y,points[2].z);
  glVertex3f(points[3].x,points[3].y,points[3].z);
  glEnd();
}
