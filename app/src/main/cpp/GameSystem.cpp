//
// Created by 윤중현 on 2017. 2. 28..
//

#include "GameSystem.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Shader.h"

void onSurfaceCreate()
{
    LOGI("nativeCreated :: created\n");
    glClearColor(0.4f, 0.4f, 0.4f, 0.4f);
}

void onSurfaceChanged(int width, int height)
{
    LOGI("nativeChanged :: changed : w = %d, h = %d", width, height);
    glViewport(0, 0, width, height);
}

void onSurfaceUpdated()
{
//    LOGI("nativeUpdateGame :: updated\n");
    static float grey;
    grey += 0.01f;
    if (grey > 1.0f) {
        grey = 0.0f;
    }
    glClearColor(grey, grey, grey, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    GLuint _program = createProgram(gVertexShader, gFragmentShader);

    Rectangle *rectangle = new Rectangle(_program);
    rectangle->draw();
    rectangle->~Rectangle();


    Triangle *triangle = new Triangle(_program);
    triangle->draw();
    triangle->~Triangle();

    glDeleteProgram(_program);
}

void onTouchEvent(int eventsCount, int **touchInfo)
{
    for (int i = 0; i < eventsCount; i++) {
        LOGI("nativeOnTouchEvent :: touched %d : %d , (%d, %d)\n", touchInfo[i][0], touchInfo[i][1], touchInfo[i][2], touchInfo[i][3]);
    }
}