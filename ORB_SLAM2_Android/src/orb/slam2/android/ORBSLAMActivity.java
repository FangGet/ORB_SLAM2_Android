package orb.slam2.android;

import android.app.Activity;
import android.os.Bundle;
import android.view.WindowManager;

/**
 *
 * @author buptzhaofang@163.com Mar 24, 2016 4:13:32 PM
 *
 */
public class ORBSLAMActivity extends Activity{

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
		          WindowManager.LayoutParams.FLAG_FULLSCREEN);//设置全屏
	}
}
