//
// Created by rincliu on 2015/12/14.
//

#ifndef __JNI_UTILS_HXX__
#define __JNI_UTILS_HXX__

#include <jni.h>
#include <string>
#include <android/log.h>

#define ENABLE_ANDROID_LOG

#ifdef ENABLE_ANDROID_LOG
#define ALogV(tag, ...) __android_log_print(ANDROID_LOG_VERBOSE, tag, __VA_ARGS__)
#define ALogD(tag, ...) __android_log_print(ANDROID_LOG_DEBUG, tag, __VA_ARGS__)
#define ALogI(tag, ...) __android_log_print(ANDROID_LOG_INFO, tag, __VA_ARGS__)
#define ALogW(tag, ...) __android_log_print(ANDROID_LOG_WARN, tag, __VA_ARGS__)
#define ALogE(tag, ...) __android_log_print(ANDROID_LOG_ERROR, tag, __VA_ARGS__)
#else
#define ALogV(tag, ...)
#define ALogD(tag, ...)
#define ALogI(tag, ...)
#define ALogW(tag, ...)
#define ALogE(tag, ...)
#endif

jintArray charsToJIntArray(JNIEnv *env, unsigned char* chars, int length);

std::string jStringToStdString(JNIEnv* env, jstring jstr);

void throwNullPointerException(JNIEnv* env, const char * msg);

void throwIllegalArgumentException(JNIEnv* env, const char * msg);

#endif
