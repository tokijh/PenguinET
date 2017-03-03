//
// Created by 윤중현 on 2017. 3. 3..
//

#ifndef PENGUINET_ASSETSMANAGER_H
#define PENGUINET_ASSETSMANAGER_H

#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>
#include <jni.h>
#include <stdlib.h>

#include "logger.h"

/**
 * assets폴더에서 데이터를 읽어옴 VertexShader.vs(읽어오는 파일)에서는 마지막에 한줄 띄어줘야 한다.
 *
 * Test 방법
    char *a = (*(&AssetsManager::getInstance())).readFile("VertexShader.vs");
    LOGI("%s :: %s", "VertexShader.vs", a);
 */
class AssetsManager {
private:
    static AssetsManager *_assetsManager;

    AAssetManager *_aAssetManager = NULL;

    AssetsManager();
    ~AssetsManager();

public:
    static void createAssetsManager(JNIEnv *env, jobject assetManager);

    static AssetsManager &getInstance();

    void destroy();

    char *readFile(const char *filename);
};


#endif //PENGUINET_ASSETSMANAGER_H
