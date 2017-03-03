//
// Created by 윤중현 on 2017. 3. 3..
//

#include "Rectangle.h"


Rectangle::Rectangle(GLuint _program) {
    setupGraphics(_program);
}

Rectangle::~Rectangle()
{

}

bool Rectangle::setupGraphics(GLuint _program) {

    gProgram = _program;
    if (!gProgram) {
        LOGE("Could not create program.");
        return false;
    }
    gvPositionHandle = glGetAttribLocation(gProgram, "vPosition");
    gvColorHandle = glGetUniformLocation(gProgram, "vColor");
    return true;
}

const GLfloat gRectangleVertices[] = {  -0.5f, 0.5f,
                                        0.5f, 0.5f,
                                        -0.5f, -0.5f,
                                        0.5f, -0.5f};

const GLfloat gRectangleColor[] = {1.0f, 1.0f, 0.0f, 0.0f};

void Rectangle::renderFrame() {

    glUseProgram(gProgram);

    glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, gRectangleVertices);
    glEnableVertexAttribArray(gvPositionHandle);

    glUniform4fv(gvColorHandle, 1, gRectangleColor);

    LOGI("%d : %d", sizeof(gRectangleVertices) / sizeof(GLfloat), sizeof(gRectangleVertices) / sizeof(GLfloat) / 2);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, sizeof(gRectangleVertices) / sizeof(GLfloat) / 2);

    /*TODO
     * 나중에 이걸 재사용하면서 폐기할때만 불러오도록하자*/
    glDeleteShader(gvColorHandle);
    glDeleteShader(gvPositionHandle);
}

void Rectangle::draw() {
    renderFrame();
}