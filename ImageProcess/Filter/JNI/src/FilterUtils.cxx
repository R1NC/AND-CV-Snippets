//
// Created by rincliu on 2015/12/14.
//

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <algorithm>

#include "FilterUtils.hxx"

unsigned char* gaussianBlur(const unsigned char* imgData, const unsigned imgWidth, const unsigned imgHeight, unsigned gaussianKernelSize) {
  cv::Mat src = cv::Mat(cv::Size(imgHeight, imgWidth), CV_8UC4);
  cv::Mat dst = src.clone();
  //The width & height of Gaussian-Kernel-Size must be positive and odd.
  gaussianKernelSize = std::max(gaussianKernelSize, (unsigned)1);
  if (gaussianKernelSize % 2 != 1) {
    gaussianKernelSize++;
  }
  cv::Size mGaussianKernelSize = cv::Size(gaussianKernelSize, gaussianKernelSize);
  cv::GaussianBlur(src, dst, mGaussianKernelSize, 0, 0);
  return dst.data;
}
