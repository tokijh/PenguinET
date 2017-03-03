//
// Created by 윤중현 on 2017. 2. 28..
//

#include "GameSystem.h"
#include "Rectangle.h"
#include "Triangle.h"

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
    // 배경색을 매 프래임마다 점점 밝아지도록 무한루프
    static float grey;
    grey += 0.01f;
    if (grey > 1.0f) {
        grey = 0.0f;
    }
    // 해당색으로 화면 전체를 초기화
    glClearColor(grey, grey, grey, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    // 사각형 그리기
    Rectangle * rectangle = new Rectangle();
    rectangle->draw();
    rectangle->~Rectangle();

    // 삼각형 그리기
    Triangle *triangle = new Triangle();
    triangle->draw();
    triangle->~Triangle();
}

void onTouchEvent(int eventsCount, int **touchInfo)
{
    for (int i = 0; i < eventsCount; i++) {
        LOGI("nativeOnTouchEvent :: touched %d : %d , (%d, %d)\n", touchInfo[i][0], touchInfo[i][1], touchInfo[i][2], touchInfo[i][3]);
    }
}