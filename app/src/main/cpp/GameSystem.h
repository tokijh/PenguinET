//
// Created by 윤중현 on 2017. 2. 28..
//

#ifndef PENGUINET_GAMESYSTEM_H
#define PENGUINET_GAMESYSTEM_H

#include <GLES2/gl2.h>

void onSurfaceCreate();
void onSurfaceChanged(int width, int height);
void updateGameLoop();
void onTouchEvent(int x, int y, int touchFlag);

#endif //PENGUINET_GAMESYSTEM_H
