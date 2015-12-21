//
// Created by rincliu on 2015/12/14.
//

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <algorithm>

#include "FilterUtils.hxx"

unsigned char* boxFilter(unsigned char* imgPixels, const unsigned imgWidth, const unsigned imgHeight, unsigned kernelSize) {
  cv::Mat src(imgHeight, imgWidth, CV_8UC4, imgPixels, cv::Mat::AUTO_STEP);
  cv::Mat dst = src.clone();
  kernelSize = std::max(kernelSize, (unsigned)1);
  cv::Size mKernelSize(kernelSize, kernelSize);
  cv::boxFilter(src, dst, -1, mKernelSize);
  return dst.data;
}

unsigned char* gaussianBlur(unsigned char* imgPixels, const unsigned imgWidth, const unsigned imgHeight, unsigned kernelSize) {
  cv::Mat src(imgHeight, imgWidth, CV_8UC4, imgPixels, cv::Mat::AUTO_STEP);
  cv::Mat dst = src.clone();
  //The width & height of Gaussian-Kernel-Size must be positive and odd.
  kernelSize = std::max(kernelSize, (unsigned)1);
  if (kernelSize % 2 != 1) {
    kernelSize++;
  }
  cv::Size mKernelSize(kernelSize, kernelSize);
  cv::GaussianBlur(src, dst, mKernelSize, 0, 0);
  return dst.data;
}
