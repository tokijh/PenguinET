//
// Created by 윤중현 on 2017. 2. 28..
//

#include "GameSystem.h"

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
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void onTouchEvent(int eventsCount, int **touchInfo)
{
    for (int i = 0; i < eventsCount; i++) {
        LOGI("nativeOnTouchEvent :: touched %d : %d , (%d, %d)\n", touchInfo[i][0], touchInfo[i][1], touchInfo[i][2], touchInfo[i][3]);
    }
}