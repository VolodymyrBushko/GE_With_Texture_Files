#ifndef SQUARE_H_
#define SQUARE_H_

#include <GL/glut.h>
#include "object.h"
#include "color.h"
#include "point.h"
#include <vector>

class Square: public Object
{
public:
   Square(std::vector<Point> _points);
   Square(std::vector<Point> _points, const Color& _color);
   void Draw() override;
};

#endif
