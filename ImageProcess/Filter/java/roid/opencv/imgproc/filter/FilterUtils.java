//
// Created by rincliu on 2015/12/14.
//
package roid.opencv.imgproc.filter;

public class FilterUtils {

  static {
    System.loadLibrary("ImageProcessFilterUtils");
  }

  public static native byte[] nativeGaussianBlur(byte[] imgData, int imgWidth, int imgHeight, int gaussianKernelSize) throws NullPointerException, IllegalArgumentException;
}
