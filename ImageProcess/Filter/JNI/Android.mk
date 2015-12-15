LOCAL_PATH := $(call my-dir)
CURRENT_ROOT_PATH := $(LOCAL_PATH)/../../..
OPENCV_ROOT_PATH := $(CURRENT_ROOT_PATH)/../OpenCV-Android
OPENCV_LIBS_PATH := $(OPENCV_ROOT_PATH)/sdk/native/libs

include $(CLEAR_VARS)

#LOCAL_MODULE := CV_CORE
#LOCAL_SRC_FILES := $(OPENCV_LIBS_PATH)/armeabi/libopencv_core.a
#include $(PREBUILT_STATIC_LIBRARY)

#LOCAL_MODULE := CV_IMGPROC
#LOCAL_SRC_FILES := $(OPENCV_LIBS_PATH)/armeabi/libopencv_imgproc.a
#include $(PREBUILT_STATIC_LIBRARY)

OPENCV_INSTALL_MODULES := on
OPENCV_CAMERA_MODULES := off
OPENCV_LIB_TYPE := SHARED
include $(OPENCV_ROOT_PATH)/sdk/native/jni/OpenCV.mk

LOCAL_MODULE := FilterUtils
LOCAL_C_INCLUDES += \
	$(LOCAL_PATH)/src \
	$(CURRENT_ROOT_PATH)/Utils \
  $(OPENCV_ROOT_PATH)/sdk/native/jni/include
LOCAL_SRC_FILES := \
	JNI.cxx \
	$(CURRENT_ROOT_PATH)/Utils/JniUtils.cxx \
	$(LOCAL_PATH)/src/FilterUtils.cxx
#LOCAL_STATIC_LIBRARIES := \
	CV_CORE \
	CV_IMGPROC
LOCAL_CFLAGS := -std=c++11
LOCAL_LDLIBS := -llog -ldl
include $(BUILD_SHARED_LIBRARY)
