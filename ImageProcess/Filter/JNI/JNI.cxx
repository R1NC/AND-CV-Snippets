//
// Created by rincliu on 2015/12/14.
//
#include <jni.h>
#include <functional>

#include "src/FilterUtils.hxx"
#include "../../../Utils/JniUtils.hxx"

#ifdef __cplusplus
extern "C" {
#endif

	jboolean checkFilterParameters(JNIEnv *env, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize);

	jintArray processPixels(JNIEnv *env, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize, std::function<unsigned char*(unsigned char*, jint, jint, jint)> processFunc);

	JNIEXPORT jintArray JNICALL
	Java_roid_opencv_imgproc_filter_FilterUtils_nativeBoxFilter
	(JNIEnv *env, jclass clazz, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize) {
		if (checkFilterParameters(env, imgPixels, imgWidth, imgHeight, kernelSize) == JNI_FALSE) {
			return NULL;
		}
		auto processFunc = [](unsigned char* imgPixelsChars, jint imgWidth, jint imgHeight, jint kernelSize) -> unsigned char* {
			return boxFilter(imgPixelsChars, imgWidth, imgHeight, kernelSize);
		};
		return processPixels(env, imgPixels, imgWidth, imgHeight, kernelSize, processFunc);
	}

	JNIEXPORT jintArray JNICALL
	Java_roid_opencv_imgproc_filter_FilterUtils_nativeBilateralFilter
	(JNIEnv *env, jclass clazz, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize) {
		if (checkFilterParameters(env, imgPixels, imgWidth, imgHeight, kernelSize) == JNI_FALSE) {
			return NULL;
		}
		auto processFunc = [](unsigned char* imgPixelsChars, jint imgWidth, jint imgHeight, jint kernelSize) -> unsigned char* {
			return bilateralFilter(imgPixelsChars, imgWidth, imgHeight, kernelSize);
		};
		return processPixels(env, imgPixels, imgWidth, imgHeight, kernelSize, processFunc);
	}

	JNIEXPORT jintArray JNICALL
	Java_roid_opencv_imgproc_filter_FilterUtils_nativeGaussianBlur
	(JNIEnv *env, jclass clazz, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize) {
		if (checkFilterParameters(env, imgPixels, imgWidth, imgHeight, kernelSize) == JNI_FALSE) {
			return NULL;
		}
		auto processFunc = [](unsigned char* imgPixelsChars, jint imgWidth, jint imgHeight, jint kernelSize) -> unsigned char* {
			return gaussianBlur(imgPixelsChars, imgWidth, imgHeight, kernelSize);
		};
		return processPixels(env, imgPixels, imgWidth, imgHeight, kernelSize, processFunc);
	}

	JNIEXPORT jintArray JNICALL
	Java_roid_opencv_imgproc_filter_FilterUtils_nativeMedianBlur
	(JNIEnv *env, jclass clazz, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize) {
		if (checkFilterParameters(env, imgPixels, imgWidth, imgHeight, kernelSize) == JNI_FALSE) {
			return NULL;
		}
		auto processFunc = [](unsigned char* imgPixelsChars, jint imgWidth, jint imgHeight, jint kernelSize) -> unsigned char* {
			return medianBlur(imgPixelsChars, imgWidth, imgHeight, kernelSize);
		};
		return processPixels(env, imgPixels, imgWidth, imgHeight, kernelSize, processFunc);
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

	jintArray processPixels(JNIEnv *env, jintArray imgPixels, jint imgWidth, jint imgHeight, jint kernelSize, std::function<unsigned char*(unsigned char*, jint, jint, jint)> processFunc) {
		int* imgPixelsInts = env->GetIntArrayElements(imgPixels, 0);
		unsigned char* dst = processFunc((unsigned char*)imgPixelsInts, imgWidth, imgHeight, kernelSize);
		jintArray res = charsToJIntArray(env, dst, env->GetArrayLength(imgPixels));
		// `imgPixelsInts` comes from JNI, so it cannot be freed with `delete[]`;
		env->ReleaseIntArrayElements(imgPixels, imgPixelsInts, 0);
		delete[] dst;
		return res;
	}

#ifdef __cplusplus
}
#endif
