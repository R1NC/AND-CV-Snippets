//
// Created by rincliu on 2015/12/14.
//

#include "JniUtils.hxx"

#include <assert.h>

unsigned char* jByteArrayToChars(JNIEnv *env, jbyteArray jarray) {
  int length = env->GetArrayLength(jarray);
  unsigned char* chars = new unsigned char[length];
  env->GetByteArrayRegion(jarray, 0, length, reinterpret_cast<jbyte*>(chars));
  return chars;
}

jbyteArray charsToJByteArray(JNIEnv *env, unsigned char* chars, int length) {
  jbyteArray array = env->NewByteArray(length);
  env->SetByteArrayRegion(array, 0, length, reinterpret_cast<jbyte*>(chars));
  return array;
}

std::string jStringToStdString(JNIEnv* env, jstring jstr) {
  const char *utf = env->GetStringUTFChars(jstr, 0);
	char *nativeStr = strdup(utf);
	env->ReleaseStringUTFChars(jstr, utf);
	return std::string(nativeStr);
}

void throwNullPointerException(JNIEnv* env, const char * msg) {
  env->ThrowNew(jrefs::java::lang::NullPointerException->jclassRef, msg);
}

void throwIllegalArgumentException(JNIEnv* env, const char * msg) {
  env->ThrowNew(jrefs::java::lang::IllegalArgumentException->jclassRef, msg);
}

namespace jrefs {
  namespace java {
    namespace lang {
      jclass_NullPointerException::jclass_NullPointerException(JNIEnv* env) {
        jclass tmpClass = env->FindClass("java/lang/NullPointerException");
        jclassRef = (jclass)env->NewGlobalRef(tmpClass);
        assert(!jclassRef);
      }
      jclass_NullPointerException* NullPointerException = 0;

      jclass_IllegalArgumentException::jclass_IllegalArgumentException(JNIEnv* env) {
        jclass tmpClass = env->FindClass("java/lang/IllegalArgumentException");
        jclassRef = (jclass)env->NewGlobalRef(tmpClass);
        assert(!jclassRef);
      }
      jclass_IllegalArgumentException* IllegalArgumentException = 0;
    }
  }
}
