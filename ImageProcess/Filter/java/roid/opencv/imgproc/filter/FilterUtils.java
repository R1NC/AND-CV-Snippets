//
// Created by rincliu on 2015/12/14.
//
package roid.opencv.imgproc.filter;

import android.graphics.Bitmap;

public class FilterUtils {

  static {
    System.loadLibrary("ImageProcessFilterUtils");
  }

  public static void gaussianBlur(Bitmap bitmap, int gaussianKernelSize) {
    if (bitmap != null && !bitmap.isRecycled()) {
      final int W = bitmap.getWidth(), H = bitmap.getHeight();
      int[] srcPixels = new int[W * H];
      bitmap.getPixels(srcPixels, 0, W, 0, 0, W, H);
      int[] dstPixels = nativeGaussianBlur(srcPixels, W, H, gaussianKernelSize);
      bitmap.setPixels(dstPixels, 0, W, 0, 0, W, H);
    }
  }

  private static native int[] nativeGaussianBlur(int[] imgPixels, int imgWidth, int imgHeight, int gaussianKernelSize);
}
