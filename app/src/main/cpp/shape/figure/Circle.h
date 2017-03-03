//
// Created by 윤중현 on 2017. 3. 4..
//

#ifndef PENGUINET_CIRCLE_H
#define PENGUINET_CIRCLE_H

#include <GLES2/gl2.h>
#include <math.h>
#include "../Shape.h"
#include "../../manager/AssetsShaderManager.h"


class Circle : public Shape {
private:
    void destroy();
public:
    void init(const char *VS, const char *FS);

    void draw();

    Circle();

    ~Circle();
};


#endif //PENGUINET_CIRCLE_H
