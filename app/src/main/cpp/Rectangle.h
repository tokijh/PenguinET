//
// Created by 윤중현 on 2017. 3. 3..
//

#ifndef PENGUINET_RECTANGLE_H
#define PENGUINET_RECTANGLE_H

#include <GLES2/gl2.h>
#include "Shape.h"
#include "AssetsShaderManager.h"


class Rectangle : public Shape {
private:
    void destroy();
public:
    void init(const char *VS, const char *FS);

    void draw();

    Rectangle();

    ~Rectangle();
};


#endif //PENGUINET_RECTANGLE_H
