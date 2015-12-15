//
// Created by rincliu on 2015/12/14.
//

#ifndef __JNI_UTILS_HXX__
#define __JNI_UTILS_HXX__

#include <jni.h>
#include <string>
#include <android/log.h>

#define logV(tag, ...) __android_log_print(ANDROID_LOG_VERBOSE, tag, __VA_ARGS__)
#define logD(tag, ...) __android_log_print(ANDROID_LOG_DEBUG, tag, __VA_ARGS__)
#define logI(tag, ...) __android_log_print(ANDROID_LOG_INFO, tag, __VA_ARGS__)
#define logW(tag, ...) __android_log_print(ANDROID_LOG_WARN, tag, __VA_ARGS__)
#define logE(tag, ...) __android_log_print(ANDROID_LOG_ERROR, tag, __VA_ARGS__)


unsigned char* jByteArrayToChars(JNIEnv *env, jbyteArray array);

jbyteArray charsToJByteArray(JNIEnv *env, unsigned char* chars, int len);

std::string jStringToStdString(JNIEnv* env, jstring jstr);

void throwNullPointerException(JNIEnv* env, const char * msg);

void throwIllegalArgumentException(JNIEnv* env, const char * msg);

namespace jrefs {
  namespace java {
    namespace lang {
      struct jclass_NullPointerException {
        jclass_NullPointerException(JNIEnv* env);
        jclass jclassRef;
      };
      extern jclass_NullPointerException* NullPointerException;

      struct jclass_IllegalArgumentException {
        jclass_IllegalArgumentException(JNIEnv* env);
        jclass jclassRef;
      };
      extern jclass_IllegalArgumentException* IllegalArgumentException;
    }
  }
}

#endif
