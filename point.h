#ifndef POINT_H_
#define POINT_H_

struct Point
{
   Point(double _x, double _y, double _z): x(_x), y(_y), z(_z){}
   double x,y,z;
};

#endif
