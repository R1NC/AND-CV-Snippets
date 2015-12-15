//
// Created by rincliu on 2015/12/14.
//

#include <jni.h>

#include "src/FilterUtils.hxx"
#include "../../../Utils/JniUtils.hxx"

#ifdef __cplusplus
extern "C" {
#endif

	JNIEXPORT jbyteArray JNICALL
	Java_roid_opencv_imgproc_filter_FilterUtils_nativeGaussianBlur
	(JNIEnv *env, jclass clazz, jbyteArray imgData, jint imgWidth, jint imgHeight, jint gaussianKernelSize) {
		if (!imgData) {
			throwNullPointerException(env, "imgData is null!");
			return NULL;
		}
		int length = env->GetArrayLength(imgData);
		if (length == 0) {
			throwIllegalArgumentException(env, "imgData is empty!");
			return NULL;
		}
		if (imgWidth <= 0 || imgHeight <= 0 || gaussianKernelSize <= 0) {
			throwIllegalArgumentException(env, "imgWidth & imgHeight & gaussianKernelSize must be positive!");
			return NULL;
		}
		unsigned char* src = jByteArrayToChars(env, imgData);
		unsigned char* dst = gaussianBlur(src, imgWidth, imgHeight, gaussianKernelSize);
		return charsToJByteArray(env, dst, length);
	}

#ifdef __cplusplus
}
#endif
