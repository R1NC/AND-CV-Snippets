//
// Created by rincliu on 2015/12/14.
//
#include <jni.h>

#include "src/FilterUtils.hxx"
#include "../../../Utils/JniUtils.hxx"

#ifdef __cplusplus
extern "C" {
#endif

	JNIEXPORT jintArray JNICALL
	Java_roid_opencv_imgproc_filter_FilterUtils_nativeGaussianBlur
	(JNIEnv *env, jclass clazz, jintArray imgPixels, jint imgWidth, jint imgHeight, jint gaussianKernelSize) {
		if (!imgPixels) {
			throwNullPointerException(env, "imgPixels is null!");
			return NULL;
		}
		int length = env->GetArrayLength(imgPixels);
		if (length == 0) {
			throwIllegalArgumentException(env, "imgPixels is empty!");
			return NULL;
		}
		if (imgWidth <= 0 || imgHeight <= 0 || gaussianKernelSize <= 0) {
			throwIllegalArgumentException(env, "imgWidth & imgHeight & gaussianKernelSize must be positive!");
			return NULL;
		}
		unsigned char* src = jIntArrayToChars(env, imgPixels);
		unsigned char* dst = gaussianBlur(src, imgWidth, imgHeight, gaussianKernelSize);
		return charsToJIntArray(env, dst, length);
	}

#ifdef __cplusplus
}
#endif
