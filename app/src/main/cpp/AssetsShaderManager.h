//
// Created by 윤중현 on 2017. 3. 3..
//

#ifndef PENGUINET_ASSETSSHADERMANAGER_H
#define PENGUINET_ASSETSSHADERMANAGER_H

#include <unordered_map>

#include "AssetsManager.h"

/**
 * assets안에 있는 Shader(VertexShader.vs)를 메모리에 불러온다.
 *
 * 몇번이나 불러올 필요 없이 한번 불러오면 이미 있는 메모리에서 가져오도록 설계했다.
 *
 * 이게 없으면 AssetsManager에서 readFile할때 시간이 오래걸려 튕긴다.
 *
 * Test 방법
    AssetsShaderManager *assetsShaderManager = &AssetsShaderManager::getInstance();
    assetsShaderManager->get("VertexShader.fs");
    assetsShaderManager->get("VertexShader.fs");
 */
class AssetsShaderManager {
private:
    AssetsShaderManager();

    ~AssetsShaderManager();

    std::unordered_map<std::string, std::string> *_shaderData;

    AssetsManager *_assetsManager;

public:
    static AssetsShaderManager &getInstance();

    char *get(const char *SHADER);

    void destroy();
};


#endif //PENGUINET_ASSETSSHADERMANAGER_H
