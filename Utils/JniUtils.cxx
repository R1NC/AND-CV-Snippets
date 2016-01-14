//
// Created by rincliu on 2015/12/14.
//

#include "JniUtils.hxx"

unsigned char* jIntArrayToChars(JNIEnv *env, jintArray jarray) {
  /*
  int length = env->GetArrayLength(jarray);
  unsigned char* chars = new unsigned char[length];
  env->GetIntArrayRegion(jarray, 0, length, reinterpret_cast<jint*>(chars));
  return chars;
  */
  return (unsigned char*)env->GetIntArrayElements(jarray, 0);
}

jintArray charsToJIntArray(JNIEnv *env, unsigned char* chars, int length) {
  jintArray array = env->NewIntArray(length);
  env->SetIntArrayRegion(array, 0, length, reinterpret_cast<jint*>(chars));
  return array;
}

std::string jStringToStdString(JNIEnv* env, jstring jstr) {
  const char *utf = env->GetStringUTFChars(jstr, 0);
  char *nativeStr = strdup(utf);
  env->ReleaseStringUTFChars(jstr, utf);
  return std::string(nativeStr);
}

void throwNullPointerException(JNIEnv* env, const char * msg) {
  jclass clazz = env->FindClass("java/lang/NullPointerException");
  env->ThrowNew(clazz, msg);
  env->DeleteLocalRef(clazz);
}

void throwIllegalArgumentException(JNIEnv* env, const char * msg) {
  jclass clazz = env->FindClass("java/lang/IllegalArgumentException");
  env->ThrowNew(clazz, msg);
  env->DeleteLocalRef(clazz);
}
