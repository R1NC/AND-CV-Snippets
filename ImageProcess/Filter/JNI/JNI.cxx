//
// Created by rincliu on 2015/12/14.
//
#include <jni.h>

#include "src/FilterUtils.hxx"
#include "../../../Utils/JniUtils.hxx"

#ifdef __cplusplus
extern "C" {
#endif

	jboolean checkFilterParameters(JNIEnv *env, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize);

	JNIEXPORT jintArray JNICALL
	Java_roid_opencv_imgproc_filter_FilterUtils_nativeBoxFilter
	(JNIEnv *env, jclass clazz, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize) {
		if (checkFilterParameters(env, imgPixels, imgWidth, imgHeight, kernelSize) == JNI_FALSE) {
			return NULL;
		}
		unsigned char* src = jIntArrayToChars(env, imgPixels);
		unsigned char* dst = boxFilter(src, imgWidth, imgHeight, kernelSize);
		return charsToJIntArray(env, dst, env->GetArrayLength(imgPixels));
	}

	JNIEXPORT jintArray JNICALL
	Java_roid_opencv_imgproc_filter_FilterUtils_nativeGaussianBlur
	(JNIEnv *env, jclass clazz, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize) {
		if (checkFilterParameters(env, imgPixels, imgWidth, imgHeight, kernelSize) == JNI_FALSE) {
			return NULL;
		}
		unsigned char* src = jIntArrayToChars(env, imgPixels);
		unsigned char* dst = gaussianBlur(src, imgWidth, imgHeight, kernelSize);
		return charsToJIntArray(env, dst, env->GetArrayLength(imgPixels));
	}

	jboolean checkFilterParameters(JNIEnv *env, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize) {
		if (!imgPixels) {
			throwNullPointerException(env, "imgPixels is null!");
			return JNI_FALSE;
		}
		if (env->GetArrayLength(imgPixels) == 0) {
			throwIllegalArgumentException(env, "imgPixels is empty!");
			return JNI_FALSE;
		}
		if (imgWidth <= 0 || imgHeight <= 0 || kernelSize <= 0) {
			throwIllegalArgumentException(env, "imgWidth & imgHeight & kernelSize must be positive!");
			return JNI_FALSE;
		}
		return JNI_TRUE;
	}

#ifdef __cplusplus
}
#endif
