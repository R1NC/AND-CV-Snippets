//
// Created by rincliu on 2015/12/14.
//

#ifndef __JNI_UTILS_HXX__
#define __JNI_UTILS_HXX__

#include <jni.h>
#include <string>

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
