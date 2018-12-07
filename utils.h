#include <cstdio>
#include <iostream>
#include "include/glad/glad.h"

unsigned char* readShaderFile(const char *filename);
int createShader(const unsigned int &shader, const char * filename);
long filelength(FILE *file);