//
// Created by rincliu on 2015/12/14.
//

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <algorithm>

#include "FilterUtils.hxx"

//void boxFilter(InputArray src, OutputArray dst, int ddepth, Size ksize, Point anchor=Point(-1,-1), bool normalize=true, int borderType=BORDER_DEFAULT);
unsigned char* boxFilter(unsigned char* imgPixels, const unsigned imgWidth, const unsigned imgHeight, unsigned kernelSize) {
  cv::Mat src(imgHeight, imgWidth, CV_8UC4, imgPixels);
  auto dst = src.clone();
  kernelSize = std::max(kernelSize, (unsigned)1);
  cv::Size ksize(kernelSize, kernelSize);
  int ddepth = -1;//Use src.depth().
  cv::boxFilter(src, dst, ddepth, ksize);
  return dst.data;
}

//void bilateralFilter(InputArray src, OutputArray dst, int d, double sigmaColor, double sigmaSpace, int borderType=BORDER_DEFAULT);
unsigned char* bilateralFilter(unsigned char* imgPixels, const unsigned imgWidth, const unsigned imgHeight, unsigned kernelSize) {
  cv::Mat src(imgHeight, imgWidth, CV_8UC4, imgPixels);
  auto dst = src.clone();
  kernelSize = std::max(kernelSize, (unsigned)1);
  //Large filters (d > 5) are very slow, so it is recommended to use d=5 for real-time applications.
  int d = 5;
  //For simplicity, you can set the 2 sigma values to be the same.
  double sigmaColor = kernelSize, sigmaSpace = kernelSize;
  cv::bilateralFilter(src, dst, d, sigmaColor, sigmaSpace);
  return dst.data;
}

//void GaussianBlur(InputArray src, OutputArray dst, Size ksize, double sigmaX, double sigmaY=0, int borderType=BORDER_DEFAULT);
unsigned char* gaussianBlur(unsigned char* imgPixels, const unsigned imgWidth, const unsigned imgHeight, unsigned kernelSize) {
  cv::Mat src(imgHeight, imgWidth, CV_8UC4, imgPixels);
  auto dst = src.clone();
  //The width & height of Kernel-Size must be positive and odd.
  kernelSize = std::max(kernelSize, (unsigned)1);
  if (kernelSize % 2 != 1) {
    kernelSize++;
  }
  cv::Size ksize(kernelSize, kernelSize);
  //If both sigmas are zeros, they are computed from ksize.width and ksize.height.
  double sigmaX = 0, sigmaY = 0;
  cv::GaussianBlur(src, dst, ksize, sigmaX, sigmaY);
  return dst.data;
}

//void medianBlur(InputArray src, OutputArray dst, int ksize);
unsigned char* medianBlur(unsigned char* imgPixels, const unsigned imgWidth, const unsigned imgHeight, unsigned kernelSize) {
  cv::Mat src(imgHeight, imgWidth, CV_8UC4, imgPixels);
  auto dst = src.clone();
  //The width & height of Kernel-Size must be positive and odd and greater than 1.
  kernelSize = std::max(kernelSize, (unsigned)3);
  if (kernelSize % 2 != 1) {
    kernelSize++;
  }
  cv::medianBlur(src, dst, kernelSize);
  return dst.data;
}
