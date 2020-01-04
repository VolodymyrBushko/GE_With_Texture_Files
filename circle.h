#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <GL/glut.h>
#include "object.h"
#include "color.h"
#include "point.h"
#include <vector>
#include <math.h>

class Circle: public Object
{
public:

   Circle(std::vector<Point> _points, float _step, float _radius);
   Circle(std::vector<Point> _points, float _step, float _radius, const Color& _color);
   void Draw() override;

private:

   float step;
   float radius;
};

#endif
