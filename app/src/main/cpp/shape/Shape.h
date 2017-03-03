//
// Created by 윤중현 on 2017. 3. 3..
//

#ifndef PENGUINET_SHAPE_H
#define PENGUINET_SHAPE_H

#include <GLES2/gl2.h>
#include "Shader.h"
#include "../logger.h"

class Shape {
public:
    GLuint _program;
    GLuint _vPositionHandle;
    GLuint _vColorHandle;

    virtual void init(const char *VS, const char *FS) = 0;

    virtual void draw() = 0;

    virtual void destroy() = 0;
};


#endif //PENGUINET_SHAPE_H
