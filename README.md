### Introduction:

Android (JNI) code snippets of [OpenCV][1].

### Requirements:

* [Android-NDK][2];

* [OpenCV-Android][3];

Why not the [original source][4]? OpenCV-Android offers universal makefiles and prebuilt static libraries, which can save lots of time on solving dependencies and compiling problems.

For more details, refer to the [official docs][5].

### Build for yourself:

Edit `Android.mk`, set `OPENCV_ROOT_PATH` to your own OpenCV-Android's root path:

```shell
LOCAL_PATH := $(call my-dir)
CURRENT_ROOT_PATH := $(LOCAL_PATH)/../../..
OPENCV_ROOT_PATH := $(CURRENT_ROOT_PATH)/../OpenCV-Android
OPENCV_LIBS_PATH := $(OPENCV_ROOT_PATH)/sdk/native/libs
//...
```

[1]: http://opencv.org/
[2]: http://developer.android.com/tools/sdk/ndk/index.html
[3]: http://sourceforge.net/projects/opencvlibrary/files/opencv-android/
[4]: https://github.com/Itseez/opencv
[5]: http://docs.opencv.org/2.4/doc/tutorials/introduction/android_binary_package/dev_with_OCV_on_Android.html
