//
// Created by 윤중현 on 2017. 3. 2..
//

#ifndef PENGUINET_SAVE_H
#define PENGUINET_SAVE_H

//#include <stdlib.h>
//#include <stdio.h>
#include "main.h"

/**
 * 내용을 저장, 로드하기위한 클래스
 *
 * Test 방법
 *
 * int a = Save::loadInt("testInt", 0) + 1;
    Save::saveInt("testInt", a);
    LOGI("SaveTest :: int test : %d", a);
 */

class Save {

private:
    static JavaVM *javaVM;
    static jobject saveManager;
    static jclass saveManagerClass;
    static jmethodID saveBoolId;
    static jmethodID loadBoolId;
    static jmethodID saveIntId;
    static jmethodID loadIntId;
    static jmethodID saveFloatId;
    static jmethodID loadFloatId;
    static jmethodID saveStringId;
    static jmethodID loadStringId;

    static JNIEnv *getJNIEnv(JavaVM *jvm);

public:
    static void init(JNIEnv *env, jobject _storeManager);

    static void saveBool(const char *name, bool value);

    static bool loadBool(const char *name, bool defValue);

    static void saveInt(const char *name, int value);

    static int loadInt(const char *name, int defValue);

    static void saveFloat(const char *name, float value);

    static float loadFloat(const char *name, float defValue);

    static void saveString(const char *name, const char *value);

    static char *loadString(const char *name, char *defValue);

};


#endif //PENGUINET_SAVE_H
