//
// Created by rincliu on 2015/12/14.
//
package roid.cv.img.filter;

public class FilterUtils {
  public static native byte[] nativeGaussianBlur(byte[] imgData, int imgWidth, int imgHeight, int gaussianKernelSize) throws NullPointerException, IllegalArgumentException;
}
