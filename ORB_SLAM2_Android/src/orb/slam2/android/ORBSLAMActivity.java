package orb.slam2.android;

import java.io.File;

import orb.slam2.android.nativefunc.OrbNdkHelper;
import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Bitmap.Config;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Toast;

/**
 * ORB Test Activity For DataSetMode
 * 
 * @author buptzhaofang@163.com Mar 24, 2016 4:13:32 PM
 *
 */
public class ORBSLAMActivity extends Activity implements OnClickListener {
	ImageView imgSource, imgDealed;
	Button start, stop;

	String vocPath, calibrationPath, ImgPath;

	static {
		System.loadLibrary("ORB_SLAM2_EXCUTOR");
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		requestWindowFeature(Window.FEATURE_NO_TITLE);// 隐藏标题
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
				WindowManager.LayoutParams.FLAG_FULLSCREEN);// 设置全屏

		setContentView(R.layout.activity_dataset_orb);
		imgSource = (ImageView) findViewById(R.id.img_origin);
		imgDealed = (ImageView) findViewById(R.id.img_dealed);
		start = (Button) findViewById(R.id.start);
		stop = (Button) findViewById(R.id.stop);
		start.setOnClickListener(this);
		stop.setOnClickListener(this);
		vocPath = getIntent().getStringExtra("voc");
		calibrationPath = getIntent().getStringExtra("calibration");
		ImgPath = getIntent().getStringExtra("images");
		if (TextUtils.isEmpty(vocPath) || TextUtils.isEmpty(calibrationPath)) {
			Toast.makeText(this, "null param,return!", Toast.LENGTH_LONG)
					.show();
			finish();
		} else {
			Log.e("========>", "running!");
			new Thread(new Runnable() {

				@Override
				public void run() {
					// TODO Auto-generated method stub
					OrbNdkHelper.initSystemWithParameters(vocPath,
							calibrationPath);
				}
			}).start();
		}

	}

	private Bitmap tmp, resultImg;
	private double timestamp;

	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		switch (v.getId()) {
		case R.id.start:
//			new Thread(new Runnable() {
//
//				@Override
//				public void run() {
					if (!TextUtils.isEmpty(ImgPath)) {
						File dir = new File(ImgPath);
						if (dir.isDirectory()) {
							int i = 0;
							for (File file : dir.listFiles()) {
								if (i < 1) {
									tmp = BitmapFactory.decodeFile(file
											.getAbsolutePath());
									runOnUiThread(new Runnable() {

										@Override
										public void run() {
											// TODO Auto-generated method stub
											imgSource.setImageBitmap(tmp);
										}
									});
									timestamp = Double
											.parseDouble(file
													.getName()
													.substring(
															0,
															file.getName()
																	.length() - 5));
									// TODO Auto-generated method stub
									int w = tmp.getWidth(), h = tmp.getHeight();
									int[] pix = new int[w * h];
									tmp.getPixels(pix, 0, w, 0, 0, w, h);
									Log.e("information==========>",
											"step=======>1");
									int[] resultInt = OrbNdkHelper
											.startCurrentORB(timestamp, pix, w,
													h);
									Log.e("information==========>",
											"step=======>2");
									resultImg = Bitmap.createBitmap(w, h,
											Config.RGB_565);
									Log.e("information==========>",
											"step=======>3");
									resultImg.setPixels(resultInt, 0, w, 0, 0,
											w, h);
									Log.e("information==========>",
											"step=======>4");
									runOnUiThread(new Runnable() {

										@Override
										public void run() {
											// TODO Auto-generated method stub
											imgDealed.setImageBitmap(resultImg);
										}
									});
									Log.e("information==========>",
											resultInt.length + " ");
								}

								i++;
							}

						}
					} else {
						Toast.makeText(ORBSLAMActivity.this, "empty images",
								Toast.LENGTH_LONG).show();
					}
//				}
//			}).start();
			break;
		case R.id.stop:
			break;
		}
	}
}
