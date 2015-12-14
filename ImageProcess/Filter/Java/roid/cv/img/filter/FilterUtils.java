//
// Created by rincliu on 2015/12/14.
//

public class FilterUtils {
  public static native nativeGaussianBlur(byte[] imgData, int imgWidth, int imgHeight, int gaussianKernelSize) throws NullPointerException, IllegalArgumentException;
}
