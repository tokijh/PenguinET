//
// Created by 윤중현 on 2017. 3. 2..
//

#include "Save.h"

JavaVM* Save::javaVM = NULL;
jobject Save::saveManager = NULL;
jclass Save::saveManagerClass = NULL;
jmethodID Save::saveBoolId = NULL;
jmethodID Save::loadBoolId = NULL;
jmethodID Save::saveIntId = NULL;
jmethodID Save::loadIntId = NULL;
jmethodID Save::saveFloatId = NULL;
jmethodID Save::loadFloatId = NULL;
jmethodID Save::saveStringId = NULL;
jmethodID Save::loadStringId = NULL;

void Save::init(JNIEnv* env, jobject _saveManager)
{
    LOGI("Save::init");
    if (env->GetJavaVM(&javaVM) != JNI_OK) {
        LOGE("Can not Get JVM");
        return;
    }

    saveManager = env->NewGlobalRef(_saveManager);
    if (!saveManager) {
        LOGE("Can not create NewGlobalRef on saveManager");
        return;
    }
    saveManagerClass = env->GetObjectClass(saveManager);
    if (!saveManagerClass) {
        LOGE("Can not get saveManager class");
        return;
    }

    saveBoolId = env->GetMethodID(saveManagerClass, "saveBoolean", "(Ljava/lang/String;Z)V");
    if (!saveBoolId) {
        LOGE("Can not find method saveBoolean");
        return;
    }

    loadBoolId = env->GetMethodID(saveManagerClass, "loadBoolean", "(Ljava/lang/String;Z)Z");
    if (!loadBoolId) {
        LOGE("Can not find method loadBoolean");
        return;
    }

    saveIntId = env->GetMethodID(saveManagerClass, "saveInt", "(Ljava/lang/String;I)V");
    if (!saveIntId) {
        LOGE("Can not find method saveInt");
        return;
    }

    loadIntId = env->GetMethodID(saveManagerClass, "loadInt", "(Ljava/lang/String;I)I");
    if (!loadIntId) {
        LOGE("Can not find method loadInt");
        return;
    }

    saveFloatId = env->GetMethodID(saveManagerClass, "saveFloat", "(Ljava/lang/String;F)V");
    if (!saveFloatId) {
        LOGE("Can not find method saveFloat");
        return;
    }

    loadFloatId = env->GetMethodID(saveManagerClass, "loadFloat", "(Ljava/lang/String;F)F");
    if (!loadFloatId) {
        LOGE("Can not find method loadFloat");
        return;
    }

    saveStringId = env->GetMethodID(saveManagerClass, "saveString",
                                    "(Ljava/lang/String;Ljava/lang/String;)V");
    if (!saveStringId) {
        LOGE("Can not find method saveString");
        return;
    }

    loadStringId = env->GetMethodID(saveManagerClass, "loadString",
                                    "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    if (!loadStringId) {
        LOGE("Can not find method loadString");
        return;
    }
}

void Save::saveBool(const char* name, bool value)
{
    LOGI("Save::saveBool(%s, %d)", name, value);
    JNIEnv *env = getJNIEnv(javaVM);

    if (!env) {
        LOGE("Can not getJNIEnv");
        return;
    }

    jstring key = env->NewStringUTF(name);
    if (!key) {
        LOGE("Can not create NewStringUTF");
    }

    env->CallVoidMethod(saveManager, saveBoolId, key, value);
}

bool Save::loadBool(const char* name, bool defValue)
{
    LOGI("Save::loadBool(%s, %d)", name, defValue);
    JNIEnv *env = getJNIEnv(javaVM);

    if (!env) {
        LOGE("Can not getJNIEnv");
        return defValue;
    }

    jstring key = env->NewStringUTF(name);
    if (!key) {
        LOGE("Can not create NewStringUTF");
    }

    return env->CallBooleanMethod(saveManager, loadBoolId, key, defValue);
}

void Save::saveInt(const char* name, int value)
{
    LOGI("Save::saveInt(%s, %d)", name, value);
    JNIEnv *env = getJNIEnv(javaVM);

    if (!env) {
        LOGE("Can not getJNIEnv");
        return;
    }

    jstring key = env->NewStringUTF(name);
    if (!key) {
        LOGE("Can not create NewStringUTF");
    }

    env->CallVoidMethod(saveManager, saveIntId, key, value);
}

int Save::loadInt(const char* name, int defValue)
{
    LOGI("Save::loadInt(%s, %d)", name, defValue);
    JNIEnv *env = getJNIEnv(javaVM);

    if (!env) {
        LOGE("Can not getJNIEnv");
        return defValue;
    }

    jstring key = env->NewStringUTF(name);
    if (!key) {
        LOGE("Can not create NewStringUTF");
    }

    return env->CallIntMethod(saveManager, loadIntId, key, defValue);
}

void Save::saveFloat(const char* name, float value)
{
    LOGI("Save::saveFloat(%s, %f)", name, value);
    JNIEnv *env = getJNIEnv(javaVM);

    if (!env) {
        LOGE("Can not getJNIEnv");
        return;
    }

    jstring key = env->NewStringUTF(name);
    if (!key) {
        LOGE("Can not create NewStringUTF");
    }

    env->CallVoidMethod(saveManager, saveFloatId, key, value);
}

float Save::loadFloat(const char* name, float defValue)
{
    LOGI("Save::loadFloat(%s, %f)", name, defValue);
    JNIEnv *env = getJNIEnv(javaVM);

    if (!env) {
        LOGE("Can not getJNIEnv");
        return defValue;
    }

    jstring key = env->NewStringUTF(name);
    if (!key) {
        LOGE("Can not create NewStringUTF");
    }

    return env->CallFloatMethod(saveManager, loadFloatId, key, defValue);
}

void Save::saveString(const char* name, const char* value)
{
    LOGI("Save::saveString(%s, %s)", name, value);
    JNIEnv *env = getJNIEnv(javaVM);

    if (!env) {
        LOGE("Can not getJNIEnv");
        return;
    }

    jstring key = env->NewStringUTF(name);
    if (!key) {
        LOGE("Can not create NewStringUTF");
    }


    jstring jValue = env->NewStringUTF(value);
    if (!jValue) {
        LOGE("Can not create NewStringUTF");
    }
    env->CallVoidMethod(saveManager, saveStringId, key, jValue);
}

/**
 * @return C-style 0-terminated string, that should be released by caller with "operator delete[]" or defValue
 */

char* Save::loadString(const char* name, char* defValue)
{
    LOGI("Save::loadString(%s, %s)", name, defValue);
    JNIEnv *env = getJNIEnv(javaVM);

    if (!env) {
        LOGE("Can not getJNIEnv");
        return defValue;
    }

    jstring key = env->NewStringUTF(name);
    if (!key) {
        LOGE("Can not create NewStringUTF for name");
    }

    jstring jDefValue = env->NewStringUTF(defValue);
    if (!jDefValue) {
        LOGE("Can not create NewStringUTF for defValue");
    }

    jobject obj = env->CallObjectMethod(saveManager, loadStringId, key, jDefValue);
    const char *chars = env->GetStringUTFChars((jstring) obj, NULL);
    int length = env->GetStringUTFLength((jstring) obj);
    char *result = new char[length + 1];
    strcpy(result, chars);
    result[length] = '\0';

    env->ReleaseStringUTFChars((jstring) obj, chars);
    LOGI("Save: loadedString: [%s]", result);

    return result;
}

JNIEnv* Save::getJNIEnv(JavaVM* jvm)
{
    JavaVMAttachArgs args;
    args.version = JNI_VERSION_1_6;
    args.name = "PacmanNativeThread";
    args.group = NULL;
    JNIEnv *result;
    if (jvm->AttachCurrentThread(&result, &args) != JNI_OK) {
        result = NULL;
    }
    return result;
}