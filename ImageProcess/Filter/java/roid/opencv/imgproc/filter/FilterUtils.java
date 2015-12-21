//
// Created by rincliu on 2015/12/14.
//
package roid.opencv.imgproc.filter;

import android.graphics.Bitmap;

public class FilterUtils {

  public static Bitmap boxFilter(Bitmap bitmap, final int kernelSize) {
    return processBitmap(bitmap, new PixelsMatrixProcessor() {
      @Override
      public int[] onProcess(int[] srcPixels, int width, int height) {
        return nativeBoxFilter(srcPixels, width, height, kernelSize);
      }
    });
  }

  public static Bitmap gaussianBlur(Bitmap bitmap, final int kernelSize) {
    return processBitmap(bitmap, new PixelsMatrixProcessor() {
      @Override
      public int[] onProcess(int[] srcPixels, int width, int height) {
        return nativeGaussianBlur(srcPixels, width, height, kernelSize);
      }
    });
  }

  private static Bitmap processBitmap(Bitmap bitmap, PixelsMatrixProcessor processor) {
    Bitmap newBitmap = bitmap.copy(Bitmap.Config.ARGB_8888, true);
    if (bitmap != null && !bitmap.isRecycled() && processor != null) {
      final int W = bitmap.getWidth(), H = bitmap.getHeight();
      int[] srcPixels = new int[W * H];
      bitmap.getPixels(srcPixels, 0, W, 0, 0, W, H);
      int[] dstPixels = processor.onProcess(srcPixels, W, H);
      newBitmap.setPixels(dstPixels, 0, W, 0, 0, W, H);
    }
    return newBitmap;
  }

  private interface PixelsMatrixProcessor {
    int[] onProcess(int[] srcPixels, int width, int height);
  }

  static {
    System.loadLibrary("ImageProcessFilterUtils");
  }

  private static native int[] nativeGaussianBlur(int[] imgPixels, int imgWidth, int imgHeight, int kernelSize);

  private static native int[] nativeBoxFilter(int[] imgPixels, int imgWidth, int imgHeight, int kernelSize);
}
