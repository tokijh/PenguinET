#include "main.h"

extern "C" {
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeCreated(JNIEnv*  env, jobject obj, jobject storeManager);
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeChanged(JNIEnv* env, jobject thiz, jint w, jint h);
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeUpdated(JNIEnv* env, jobject obj);
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeOnTouchEvent(JNIEnv* env, jobject thiz, jobjectArray touchEvents);
};

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeCreated(JNIEnv*  env, jobject thiz, jobject storeManager)
{
    Save::init(env, storeManager);
    onSurfaceCreate();
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeChanged(JNIEnv* env, jobject thiz, jint w, jint h)
{
    onSurfaceChanged(w, h);
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeUpdated(JNIEnv* env, jobject thiz)
{
    onSurfaceUpdated();
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeOnTouchEvent(JNIEnv* env, jobject thiz, jobjectArray touchEvents)
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

    for(int i=0;i<eventsCount;i++)
        free(touchInfo[i]);
    free(touchInfo);
}
