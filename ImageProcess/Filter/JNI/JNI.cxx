//
// Created by rincliu on 2015/12/14.
//

#include <jni.h>

#include "src/FilterUtils.hxx"
#include "../../../Utils/JniUtils.hxx"

#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jbyteArray JNICALL
Java_roid_cv_img_filter_FilterUtils_nativeGaussianBlur
(JNIEnv *env, jclass clazz, jbyteArray imgData, jint imgWidth, jint imgHeight, jint gaussianKernelSize) {
	//Check parameters:
	if (!imgData) {
		jniEnv->ThrowNew(jrefs::java::lang::NullPointerException->jclassRef, "imgData is null!");
		return NULL;
	}
	int length = env->GetArrayLength(imgData);
	if (length == 0) {
		jniEnv->ThrowNew(jrefs::java::lang::IllegalArgumentException->jclassRef, "imgData is empty!");
		return NULL;
	}
	if (imgWidth <= 0 || imgHeight <= 0 || gaussianKernelSize <= 0) {
		jniEnv->ThrowNew(jrefs::java::lang::IllegalArgumentException->jclassRef, "imgWidth & imgHeight & gaussianKernelSize must be positive!");
		return NULL;
	}
	if (gaussianKernelSize % 2 == 0) {
		jniEnv->ThrowNew(jrefs::java::lang::IllegalArgumentException->jclassRef, "gaussianKernelSize must be odd!");
		return NULL;
	}

	unsigned char* src = jByteArrayToChars(env, imgData);
	unsigned char* dst = gaussianBlur(src, imgWidth, imgHeight, gaussianKernelSize);
	return charsToJByteArray(env, dst, length);
}

#ifdef __cplusplus
}
#endif
