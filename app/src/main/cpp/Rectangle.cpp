//
// Created by 윤중현 on 2017. 3. 3..
//

#include "Rectangle.h"

Rectangle::Rectangle() : Shape()
{
    init("VertexShader.vs", "VertexShader.fs");
}

Rectangle::~Rectangle()
{
    destroy();
}

const GLfloat vertices[] = {  -0.5f, 0.5f,
                              0.5f, 0.5f,
                              -0.5f, -0.5f,
                              0.5f, -0.5f};

const GLfloat color[] = {1.0f, 1.0f, 0.0f, 0.0f};

void Rectangle::init(const char *VS, const char *FS)
{
    _program = createProgram((*(&AssetsShaderManager::getInstance())).get(VS), (*(&AssetsShaderManager::getInstance())).get(FS));
    if (!_program) {
        LOGE("Could not create program.");
        return;
    }
    _vPositionHandle = glGetAttribLocation(_program, "vPosition");
    _vColorHandle = glGetUniformLocation(_program, "vColor");
}

void Rectangle::draw()
{
//    LOGI("Rectangle draw");
    glUseProgram(_program);

    glVertexAttribPointer(_vPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, vertices); // 2는 (-0.5f, 0,5f) 이렇게 2개를 읽는다. (x, y)
    glEnableVertexAttribArray(_vPositionHandle);

    glUniform4fv(_vColorHandle, 1, color);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, sizeof(vertices) / sizeof(GLfloat) / 2); // glVertexAttribPointe의 2로 인해 위에서는 총 4개의 묶음으로 4가 나오도록 설정 (4각형이니까 4번 그린다?)

    glDeleteShader(_vColorHandle);
    glDeleteShader(_vPositionHandle);
}

void Rectangle::destroy()
{
    glDeleteProgram(_program);
}