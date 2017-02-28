#include <jni.h>

#include <GLES2/gl2.h>

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
    glClearColor(0.4f, 0.4f, 0.4f, 0.4f);
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeChanged(JNIEnv* env, jobject thiz, jint w, jint h)
{
    LOGI("nativeChanged :: changed : w = %d, h = %d", w, h);
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeUpdateGame(JNIEnv* env)
{
    LOGI("nativeUpdateGame :: updated\n");
    glClear(GL_COLOR_BUFFER_BIT);
}

JNIEXPORT void JNICALL Java_com_timejh_penguinet_OpenGLLib_nativeOnTouchEvent(JNIEnv* env, jobject thiz, jint x, jint y, jint touchFlag)
{
    LOGI("nativeOnTouchEvent :: touched : %d , %d, %d\n", x, y, touchFlag);
}
