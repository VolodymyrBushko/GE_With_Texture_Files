#ifndef COLOR_H_
#define COLOR_H_
struct Color {
 Color(): r(0.0), g(0.0), b(0.0){}
 Color(double r_, double g_, double b_): r(r_), g(g_), b(b_) {}
 double r, g, b;
};
#endif
