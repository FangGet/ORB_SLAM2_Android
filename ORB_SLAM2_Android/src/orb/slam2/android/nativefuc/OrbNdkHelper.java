package orb.slam2.android.nativefuc;

/**
 *
 * @author buptzhaofang@163.com Mar 26, 2016 8:48:13 PM
 *
 */
public class OrbNdkHelper {
	
	/**
	 * jni中初始化SLAM系统
	 */
	public static native void initSystem();
	
	public static native int[] startCurrentORB();
}
