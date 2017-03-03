//
// Created by 윤중현 on 2017. 3. 3..
//

#include "Triangle.h"

Triangle::Triangle(GLuint _program) {
    setupGraphics(_program);
}

Triangle::~Triangle()
{

}

bool Triangle::setupGraphics(GLuint _program) {

    gProgram = _program;
    if (!gProgram) {
        LOGE("Could not create program.");
        return false;
    }
    gvPositionHandle = glGetAttribLocation(gProgram, "vPosition");
    gvColorHandle = glGetUniformLocation(gProgram, "vColor");
    return true;
}

const GLfloat gTriangleVertices[] = { 0.0f, 0.5f, 0.0f,
                                      -0.5f, -0.5f, 0.0f,
                                      0.5f, -0.5f, 0.0f };

const GLfloat gTriangleColor[] = {0.0f, 1.0f, 1.0f, 0.0f};

void Triangle::renderFrame() {

    glUseProgram(gProgram);

    glVertexAttribPointer(gvPositionHandle, 3, GL_FLOAT, GL_FALSE, 0, gTriangleVertices);
    glEnableVertexAttribArray(gvPositionHandle);

    glUniform4fv(gvColorHandle, 1, gTriangleColor);

    glDrawArrays(GL_TRIANGLES, 0, sizeof(gTriangleVertices) / sizeof(GLfloat) / 3);

    /*TODO
     * 나중에 이걸 재사용하면서 폐기할때만 불러오도록하자*/
    glDeleteShader(gvColorHandle);
    glDeleteShader(gvPositionHandle);
}

void Triangle::draw() {
    renderFrame();
}