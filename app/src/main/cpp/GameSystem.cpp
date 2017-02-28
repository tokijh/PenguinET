//
// Created by 윤중현 on 2017. 2. 28..
//

#include "GameSystem.h"

void onSurfaceCreate()
{
    glClearColor(0.4f, 0.4f, 0.4f, 0.4f);
}

void onSurfaceChanged(int width, int height)
{
    glViewport(0, 0, width, height);
}

void updateGameLoop()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void onTouchEvent(int x, int y, int touchFlag)
{

}