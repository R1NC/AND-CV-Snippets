//
// Created by rincliu on 2015/12/14.
//

#ifndef __FILTER_UTILS_HXX__
#define __FILTER_UTILS_HXX__

unsigned char* boxFilter(unsigned char* imgPixels, const unsigned imgWidth, const unsigned imgHeight, unsigned kernelSize);

unsigned char* gaussianBlur(unsigned char* imgPixels, const unsigned imgWidth, const unsigned imgHeight, unsigned kernelSize);

#endif
