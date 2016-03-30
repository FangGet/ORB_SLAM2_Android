package orb.slam2.android.nativefunc;

/**
 *
 * @author buptzhaofang@163.com Mar 26, 2016 8:48:13 PM
 *
 */
public class OrbNdkHelper {
	
	/**
	 * jni中初始化SLAM系统
	 * @param VOCPath
	 * @param calibrationPath
	 */
	public static native void initSystemWithParameters(String VOCPath,String calibrationPath);
	
	public static native int[] startCurrentORB(double curTimeStamp,int[] data,int w,int h);
}
