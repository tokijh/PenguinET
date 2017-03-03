//
// Created by 윤중현 on 2017. 3. 3..
//

#ifndef PENGUINET_RECTANGLE_H
#define PENGUINET_RECTANGLE_H

#include <GLES2/gl2.h>
#include <stdlib.h>
#include "logger.h"
#include "Shader.h"


class Rectangle {
private:

    GLuint gProgram;
    GLuint gvPositionHandle;
    GLuint gvColorHandle;

    bool setupGraphics(GLuint _program);
    void renderFrame();

public:
    Rectangle(GLuint _program);
    ~Rectangle();

    void draw();
};


#endif //PENGUINET_RECTANGLE_H
