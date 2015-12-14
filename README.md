### Introduction

Android (JNI) code snippets of [OpenCV][1].

### Requirements

* [Android-NDK][2];

* [OpenCV4Android][3];

Why not [the original source][4]? OpenCV4Android offers universal makefiles and prebuilt static libraries, which can save lots of time on solving dependencies and compiling problems.

### Build

Edit `Android.mk`, set `OPENCV_ROOT_PATH` to your own OpenCV4Android's root path:

```shell
LOCAL_PATH := $(call my-dir)
CURRENT_ROOT_PATH := $(LOCAL_PATH)/../../..
OPENCV_ROOT_PATH := $(CURRENT_ROOT_PATH)/../OpenCV-android-sdk
OPENCV_LIBS_PATH := $(OPENCV_ROOT_PATH)/sdk/native/libs
//...
```

[1]: http://opencv.org/
[2]: http://developer.android.com/tools/sdk/ndk/index.html
[3]: http://sourceforge.net/projects/opencvlibrary/files/opencv-android/
[4]: https://github.com/Itseez/opencv
