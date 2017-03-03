//
// Created by 윤중현 on 2017. 3. 3..
//

#ifndef PENGUINET_TRIANGLE_H
#define PENGUINET_TRIANGLE_H

#include <GLES2/gl2.h>
#include "Shape.h"
#include "AssetsShaderManager.h"


class Triangle : public Shape {
private:
    void destroy();
public:
    void init(const char *VS, const char *FS);

    void draw();

    Triangle();

    ~Triangle();
};


#endif //PENGUINET_TRIANGLE_H
