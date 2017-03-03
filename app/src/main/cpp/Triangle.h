//
// Created by 윤중현 on 2017. 3. 3..
//

#ifndef PENGUINET_TRIANGLE_H
#define PENGUINET_TRIANGLE_H

#include <GLES2/gl2.h>
#include <stdlib.h>
#include "logger.h"
#include "Shader.h"

class Triangle {
private:

    GLuint gProgram;
    GLuint gvPositionHandle;
    GLuint gvColorHandle;


    bool setupGraphics(GLuint _program);
    void renderFrame();

public:
    Triangle(GLuint _program);
    ~Triangle();

    void draw();
};


#endif //PENGUINET_TRIANGLE_H
