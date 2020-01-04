#include <GL/glut.h>
#include <sstream>
#include "object.h"
#include "point.h"
#include <string>
#include <iostream>

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



class TextureObj: protected Object {
public:
  TextureObj(std::vector<Point> _point) : Object(_point) {}

  static bool LoadTexture(std::string path, TextureObj& texture) {
    FILE* file = fopen(path.c_std(), "rb");
    if (file == NULL) return 0;

    fseek(file, 18, SEEK_SET);
    fread(&(texture.width), 2, 1, file);
    fseek(file, 2, SEEK_CUR);
    fread(&(texture.height), 2, 1, file);

    if ((texture.image = (unsigned char*)malloc(sizeof(unsigned char) * 3 * texture.width * texture.height)) == NULL) {
      fclose(file);
      return 0;
    }

    fseek(file, 30, SEEK_CUR);
    fread(texture.image, 3, texture.width * texture.height, file);

    glGenTextures(1, &texture.id);
    glBindTexture(GL_TEXTURE_2D, texture.id);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, texture.width, texture.height, GL_BGR_EXT, GL_UNSIGNED_BYTE, texture.image);
    free(texture.image);
    fclose(file);

    return texture.id;
  }

  void Draw() override {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glBindTexture(GL_TEXTURE_2D, id);

    if(points.size() == 3) {
      glBegin(GL_TRIANGLES);
    } else if(points.size() == 4) {
      glBegin(GL_QUADS);
      glTexCoord2f(0.0, 0.0);
      glVertex3f(points[0].x, points[0].y, 0.0);
      glTexCoord2f(0.0, 1.0);
      glVertex3f(points[1].x, points[1].y, 0.0);
      glTexCoord2f(1.0, 1.0);
      glVertex3f(points[2].x, points[2].y, 0.0);
      glTexCoord2f(1.0, 0.0);
      glVertex3f(points[3].x, points[3].y, 0.0);
    } else if(points.size() > 4) {
      glBegin(GL_POLYGON);
    } else {
      std::cout << "Error" << std::endl;
      return;
    }

    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
  } 

  int id;
};
