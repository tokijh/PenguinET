//
// Created by 윤중현 on 2017. 3. 3..
//

#include "AssetsShaderManager.h"

AssetsShaderManager& AssetsShaderManager::getInstance()
{
    static AssetsShaderManager *assetsShaderManager = NULL;

    if (assetsShaderManager == NULL) {
        assetsShaderManager = new AssetsShaderManager();
    }

    return *assetsShaderManager;
}

void AssetsShaderManager::destroy()
{
    AssetsShaderManager *assetsShaderManager = &getInstance();

    if (assetsShaderManager != NULL) {
        delete assetsShaderManager;
    }
}

char* AssetsShaderManager::get(const char *SHADER)
{
    std::unordered_map<std::string, std::string>::const_iterator findIterator = _shaderData->find(SHADER);

    if (findIterator == _shaderData->end()) {
        _shaderData->insert(std::make_pair(SHADER, _assetsManager->readFile(SHADER)));
        LOGI("%s is saved", SHADER);
        findIterator = _shaderData->find(SHADER);
    }

    return (char *) findIterator->second.c_str();
}

AssetsShaderManager::AssetsShaderManager()
        : _assetsManager(&AssetsManager::getInstance()), _shaderData(new std::unordered_map<std::string, std::string>)
{

}
AssetsShaderManager::~AssetsShaderManager()
{
    _shaderData->clear();
    delete _shaderData;
}