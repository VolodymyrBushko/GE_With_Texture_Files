#include "texture.h"

ManagerTexture::ManagerTexture(int id) {
    this->id = id;
}

int ManagerTexture::LoadTexture(char* fileName) {
    FILE* file = fopen(fileName, "rb");
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

    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, texture.width, texture.height, GL_BGR_EXT, GL_UNSIGNED_BYTE, texture.image);
    free(texture.image);
    fclose(file);
    fon = id;

    return 1;
}
