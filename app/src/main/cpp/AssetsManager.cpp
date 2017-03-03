//
// Created by 윤중현 on 2017. 3. 3..
//

#include "AssetsManager.h"

AAssetManager *AssetsManager::_aAssetManager = NULL;

void AssetsManager::createAssetsManager(JNIEnv * env, jobject assetManager)
{
    AssetsManager::_aAssetManager = AAssetManager_fromJava(env, assetManager);
    if (AssetsManager::_aAssetManager) {
        LOGI("AssetsManager is created!\n");
    }
    else {
        LOGE("AssetsManager is not created!\n");
    }
}

char* AssetsManager::readFile(const char* filename)
{
    AAsset *asset = AAssetManager_open(AssetsManager::_aAssetManager, filename,
                                       AASSET_MODE_UNKNOWN);

    if (asset == NULL)
        return NULL;

    int fileSize = AAsset_getLength(asset);

    if (fileSize == 0)
        return NULL;

    char *buf = (char *) malloc(sizeof(char) * fileSize);
    AAsset_read(asset, buf, fileSize);

    AAsset_close(asset);
    return buf;
}