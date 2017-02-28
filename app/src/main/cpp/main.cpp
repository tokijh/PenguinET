#include <jni.h>

#include "GameSystem.h"

#include "logger.h"

extern "C" {
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeCreated(JNIEnv*  env);
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeChanged(JNIEnv* env, jobject thiz, jint w, jint h);
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeUpdateGame(JNIEnv* env);
    JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeOnTouchEvent(JNIEnv* env, jobject thiz, jint x, jint y, jint touchFlag);
};

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeCreated(JNIEnv*  env)
{
    LOGI("nativeCreated :: created\n");
    onSurfaceCreate();
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeChanged(JNIEnv* env, jobject thiz, jint w, jint h)
{
    LOGI("nativeChanged :: changed : w = %d, h = %d", w, h);
    onSurfaceChanged(w, h);
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeUpdateGame(JNIEnv* env)
{
    LOGI("nativeUpdateGame :: updated\n");
    updateGameLoop();
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeOnTouchEvent(JNIEnv* env, jobject thiz, jint x, jint y, jint touchFlag)
{
    LOGI("nativeOnTouchEvent :: touched : %d , %d, %d\n", x, y, touchFlag);
    onTouchEvent(x, y, touchFlag);
}
