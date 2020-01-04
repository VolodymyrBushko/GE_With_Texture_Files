#include "init.h"

void InitMainWindow(char* name)
{
   glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
   glutInitWindowSize(680,420);
   glutInitWindowPosition(300,100);
   glutCreateWindow(name);
}
