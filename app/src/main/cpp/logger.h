//
// Created by 윤중현 on 2017. 2. 28..
//

#ifndef PENGUINET_LOGGER_H
#define PENGUINET_LOGGER_H

#include <android/log.h>

bool debug = true;

#define  LOG_TAG    "mainJNI"
#define  LOGI(...)  if(debug)__android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  if(debug)__android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


#endif //PENGUINET_LOGGER_H
