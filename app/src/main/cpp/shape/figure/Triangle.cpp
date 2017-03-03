//
// Created by 윤중현 on 2017. 3. 3..
//

#include "Triangle.h"

Triangle::Triangle() : Shape()
{
    init("VertexShader.vs", "VertexShader.fs");
}

Triangle::~Triangle()
{
    destroy();
}

const GLfloat vertices[] = { 0.0f, 0.5f, 0.0f,
                                      -0.5f, -0.5f, 0.0f,
                                      0.5f, -0.5f, 0.0f };

const GLfloat color[] = {0.0f, 1.0f, 1.0f, 0.0f};

void Triangle::init(const char *VS, const char *FS)
{
    _program = createProgram((*(&AssetsShaderManager::getInstance())).get(VS), (*(&AssetsShaderManager::getInstance())).get(FS));
    if (!_program) {
        LOGE("Could not create program.");
        return;
    }
    _vPositionHandle = glGetAttribLocation(_program, "vPosition");
    _vColorHandle = glGetUniformLocation(_program, "vColor");
}

void Triangle::draw()
{
//    LOGI("Triangle draw");

    glUseProgram(_program);

    glVertexAttribPointer(_vPositionHandle, 3, GL_FLOAT, GL_FALSE, 0, vertices); // 3은 (0.0f, 0.5f, 0,0f) 이렇게 3개를 읽는다. (x, y, z)
    glEnableVertexAttribArray(_vPositionHandle);

    glUniform4fv(_vColorHandle, 1, color);

    glDrawArrays(GL_TRIANGLE_STRIP, 0, sizeof(vertices) / sizeof(GLfloat) / 3); // glVertexAttribPointe의 3로 인해 위에서는 총 3개의 묶음으로 3이 나오도록 설정 (3각형이니까 3번 그린다?)

    glDeleteShader(_vColorHandle);
    glDeleteShader(_vPositionHandle);
}

void Triangle::destroy()
{
    glDeleteProgram(_program);
}