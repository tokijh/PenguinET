#include "main.h"
#include "manager/AssetsManager.h"

static bool isCreated = false;

extern "C" {
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_onCreated(JNIEnv*  env, jobject obj, jobject storeManager, jobject assetManager);
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_onChanged(JNIEnv* env, jobject thiz, jint w, jint h);
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_onTouch(JNIEnv* env, jobject thiz, jobjectArray touchEvents);
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_step(JNIEnv* env, jobject obj);
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_destroy(JNIEnv* env, jobject obj);
    JNIEXPORT jboolean JNICALL Java_com_timejh_penguinet_OpenGLLib_stop(JNIEnv* env, jobject obj);
};

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_onCreated(JNIEnv*  env, jobject thiz, jobject storeManager, jobject assetManager)
{
    Save::init(env, storeManager);
    AssetsManager::createAssetsManager(env, assetManager);
    onSurfaceCreate();

    isCreated = true;
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_onChanged(JNIEnv* env, jobject thiz, jint w, jint h)
{
    onSurfaceChanged(w, h);
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_step(JNIEnv* env, jobject thiz)
{
    if (isCreated)
        onSurfaceUpdated();
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_onTouch(JNIEnv* env, jobject thiz, jobjectArray touchEvents)
{
    jsize eventsCount = env->GetArrayLength(touchEvents);

    int **touchInfo = (int **) malloc(sizeof(int *) * eventsCount);
    for (int i = 0; i < eventsCount; i++) {
        touchInfo[i] = (int *) malloc(sizeof(int) * 4);
        jintArray event = (jintArray) env->GetObjectArrayElement(touchEvents, i);
        jint *element = env->GetIntArrayElements(event, JNI_FALSE);
        touchInfo[i][0] = element[0];
        touchInfo[i][1] = element[1];
        touchInfo[i][2] = element[2];
        touchInfo[i][3] = element[3];
        env->ReleaseIntArrayElements(event, element, 0);
        delete element;
    }

    onTouchEvent(eventsCount, touchInfo);

    for (int i = 0; i < eventsCount; i++)
        free(touchInfo[i]);
    free(touchInfo);
}

JNIEXPORT jboolean JNICALL Java_com_timejh_penguinet_OpenGLLib_stop(JNIEnv* env, jobject obj)
{
    return false;
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_destroy(JNIEnv* env, jobject obj)
{
    LOGI("Destroy :: Free All Memorry");
}