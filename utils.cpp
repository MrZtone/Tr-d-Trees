#include "utils.h"

unsigned char* readShaderFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        std::cout << "ERROR: Cannot open shader file!" << std::endl;
  		  return 0;
    }
    int bytesinfile = (int)filelength(file);
    unsigned char *buffer = new unsigned char[bytesinfile+1];
    int bytesread = (int)fread( buffer, 1, bytesinfile, file);
    buffer[bytesread] = 0; // Terminate the string with 0
    fclose(file);

    return buffer;
}

long filelength(FILE *file) {
    long numbytes;
    long savedpos = ftell(file); // Remember where we are
    fseek(file, 0, SEEK_END);    // Fast forward to the end
    numbytes = ftell(file);      // Index of last byte in file
    fseek(file, savedpos, SEEK_SET); // Get back to where we were
    return numbytes;             // This is the file length
}

int createShader(const unsigned int &shader, const char * filename)
{
    const char *ShaderStrings = (char*)readShaderFile(filename);
    int  success;
    char infoLog[512];
    glShaderSource(shader, 1, &ShaderStrings, NULL);
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    return success;
}