//
// Created by rincliu on 2015/12/14.
//

#include "JniUtils.hxx"

unsigned char* jByteArrayToChars(JNIEnv *env, jbyteArray jarray) {
  int length = env->GetArrayLength(jarray);
  unsigned char* chars = new unsigned char[length];
  env->GetByteArrayRegion (jarray, 0, length, reinterpret_cast<jbyte*>(chars));
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
