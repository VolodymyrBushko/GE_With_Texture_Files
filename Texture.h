#include <GL/glut.h>
#include <sstream>

struct Texture {
  unsigned char* image;
  int width;
  int height;
};

class ManagerTexture {

public:
  GLuint id;
  GLuint fon;
  Texture texture;

  ManagerTexture(int);
  int LoadTexture(char*);
};
