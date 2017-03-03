//
// Created by 윤중현 on 2017. 3. 4..
//

#include "Circle.h"

Circle::Circle() : Shape()
{
    init("VertexShader.vs", "VertexShader.fs");
}

Circle::~Circle()
{
    destroy();
}

GLfloat vertices[364 * 3];

void makeCircle() {
    vertices[0] = 0;
    vertices[1] = 0;
    vertices[2] = 0;

    for (int i = 1; i < 364; i++) {
        vertices[(i * 3) + 0] = (float) (0.5 * cos((3.14 / 180) * (float) i));
        vertices[(i * 3) + 1] = (float) (0.5 * sin((3.14 / 180) * (float) i));
        vertices[(i * 3) + 2] = 0;
    }
}

const GLfloat color[] = {1.0f, 0.0f, 0.0f, 0.0f};

void Circle::init(const char *VS, const char *FS)
{
    _program = createProgram((*(&AssetsShaderManager::getInstance())).get(VS), (*(&AssetsShaderManager::getInstance())).get(FS));
    if (!_program) {
        LOGE("Could not create program.");
        return;
    }
    _vPositionHandle = glGetAttribLocation(_program, "vPosition");
    _vColorHandle = glGetUniformLocation(_program, "vColor");

    makeCircle();
}

void Circle::draw()
{
//    LOGI("Circle draw");
    glUseProgram(_program);

    glVertexAttribPointer(_vPositionHandle, 3, GL_FLOAT, GL_FALSE, 12, vertices);
    glEnableVertexAttribArray(_vPositionHandle);

    glUniform4fv(_vColorHandle, 1, color);

    glDrawArrays(GL_TRIANGLE_FAN, 0, sizeof(vertices) / sizeof(GLfloat) / 3);

    glDeleteShader(_vColorHandle);
    glDeleteShader(_vPositionHandle);
}

void Circle::destroy()
{
    glDeleteProgram(_program);
}