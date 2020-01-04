#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <GL/glut.h>
#include "object.h"
#include "color.h"
#include "point.h"
#include <vector>

class Triangle: public Object
{
public:
   Triangle(std::vector<Point> _points);
   Triangle(std::vector<Point> _points, const Color& _color);
   void Draw() override;
};

#endif
