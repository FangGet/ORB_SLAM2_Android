package orb.slam2.android;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import orb.slam2.android.nativefunc.OrbNdkHelper;

import org.opencv.android.BaseLoaderCallback;
import org.opencv.android.CameraBridgeViewBase;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewFrame;
import org.opencv.android.CameraBridgeViewBase.CvCameraViewListener2;
import org.opencv.android.LoaderCallbackInterface;
import org.opencv.android.OpenCVLoader;
import org.opencv.core.Mat;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.Bitmap.Config;
import android.opengl.GLSurfaceView;
import android.opengl.GLSurfaceView.Renderer;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SurfaceView;
import android.view.Window;
import android.view.WindowManager;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Toast;

/**
 * ORB Test Activity For DataSetMode
 * 
 * @author buptzhaofang@163.com Mar 24, 2016 4:13:32 PM
 *
 */
public class ORBSLAMForCameraActivity extends Activity implements
		Renderer,CvCameraViewListener2   {
	
	private static final String TAG = "OCVSample::Activity";
	ImageView imgDealed;
	
	LinearLayout linear;
	
	String vocPath, calibrationPath;

	private static final int INIT_FINISHED=0x00010001;
	
	private CameraBridgeViewBase mOpenCvCameraView;
	private boolean              mIsJavaCamera = true;
	private MenuItem             mItemSwitchCamera = null;

	private final int CONTEXT_CLIENT_VERSION = 3;
	private GLSurfaceView mGLSurfaceView;
	
	long addr;
	int w,h;
	boolean isSLAMRunning=true;

	private BaseLoaderCallback mLoaderCallback = new BaseLoaderCallback(this) {
        @Override
        public void onManagerConnected(int status) {
            switch (status) {
                case LoaderCallbackInterface.SUCCESS:
                {
                    Log.i(TAG, "OpenCV loaded successfully");
                    mOpenCvCameraView.enableView();
                } break;
                default:
                {
                    super.onManagerConnected(status);
                } break;
            }
        }
    };
	
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
		getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

		setContentView(R.layout.activity_camera_orb);
		
		imgDealed = (ImageView) findViewById(R.id.img_dealed);
		
		if (mIsJavaCamera)
            mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.tutorial1_activity_java_surface_view);
        else
            mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.tutorial1_activity_native_surface_view);
        mOpenCvCameraView.setVisibility(SurfaceView.VISIBLE);
        mOpenCvCameraView.setCvCameraViewListener(this);

		mGLSurfaceView = new GLSurfaceView(this);
		linear = (LinearLayout) findViewById(R.id.surfaceLinear);
			//mGLSurfaceView.setEGLContextClientVersion(CONTEXT_CLIENT_VERSION);
		mGLSurfaceView.setRenderer(this);
		linear.addView(mGLSurfaceView, new LinearLayout.LayoutParams(
				LinearLayout.LayoutParams.MATCH_PARENT,
				LinearLayout.LayoutParams.MATCH_PARENT));
		
		vocPath = getIntent().getStringExtra("voc");
		calibrationPath = getIntent().getStringExtra("calibration");
		if (TextUtils.isEmpty(vocPath) || TextUtils.isEmpty(calibrationPath)) {
			Toast.makeText(this, "null param,return!", Toast.LENGTH_LONG)
					.show();
			finish();
		} else {
			Toast.makeText(ORBSLAMForCameraActivity.this, "init has been started!",
					Toast.LENGTH_LONG).show();
			new Thread(new Runnable() {

				@Override
				public void run() {
					// TODO Auto-generated method stub
					OrbNdkHelper.initSystemWithParameters(vocPath,
							calibrationPath);
							Log.e("information==========>",
									"init has been finished!");
							myHandler.sendEmptyMessage(INIT_FINISHED);
				}
			}).start();
		}
	}
	
	Handler myHandler = new Handler() {  
        public void handleMessage(Message msg) {   
             switch (msg.what) {   
                  case INIT_FINISHED:   
                	  Toast.makeText(ORBSLAMForCameraActivity.this,
								"init has been finished!",
								Toast.LENGTH_LONG).show();
          			new Thread(new Runnable() {

        				@Override
        				public void run() {
        					while(isSLAMRunning){
        						timestamp = (double)System.currentTimeMillis()/1000.0;
            					// TODO Auto-generated method stub
            					int[] resultInt = OrbNdkHelper.startCurrentORBForCamera(timestamp, addr, w, h);
            					resultImg = Bitmap.createBitmap(w, h,
            										Config.RGB_565);
            					resultImg.setPixels(resultInt, 0, w, 0, 0, w, h);
            					runOnUiThread(new Runnable() {
            						@Override
            						public void run() {
            							// TODO Auto-generated method stub
            							imgDealed.setImageBitmap(resultImg);
            						}
            					});
        					}
        				}
        			}).start();
                       break;   
             }   
             super.handleMessage(msg);   
        }   
   };

	private Bitmap tmp, resultImg;
	private double timestamp;

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		// TODO Auto-generated method stub
		//OrbNdkHelper.readShaderFile(mAssetMgr);
		OrbNdkHelper.glesInit();
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		// TODO Auto-generated method stub
		OrbNdkHelper.glesResize(width, height);
	}

	@Override
	public void onDrawFrame(GL10 gl) {
		// TODO Auto-generated method stub
		OrbNdkHelper.glesRender();
	}

	@Override
	protected void onResume() {
		// TODO Auto-generated method stub
		super.onResume();
		mGLSurfaceView.onResume();
		
		OpenCVLoader.initAsync(OpenCVLoader.OPENCV_VERSION_2_4_3, this, mLoaderCallback);
	}

	
	
	@Override
	protected void onStart() {
		// TODO Auto-generated method stub
		super.onStart();
	}

	@Override
	protected void onPause() {
		// TODO Auto-generated method stub
		super.onPause();
		mGLSurfaceView.onPause();
		
		if (mOpenCvCameraView != null)
            mOpenCvCameraView.disableView();
	}
	
	public void onDestroy() {
        super.onDestroy();
        if (mOpenCvCameraView != null)
            mOpenCvCameraView.disableView();
    }
	@Override
    public boolean onCreateOptionsMenu(Menu menu) {
        Log.i(TAG, "called onCreateOptionsMenu");
        mItemSwitchCamera = menu.add("stop SLAM");
        return true;
    }

	 @Override
	    public boolean onOptionsItemSelected(MenuItem item) {
	        String toastMesage = new String();
	        Log.i(TAG, "called onOptionsItemSelected; selected item: " + item);

	        if (item == mItemSwitchCamera) {
	        	isSLAMRunning=false;
//	            mOpenCvCameraView.setVisibility(SurfaceView.GONE);
//	            mIsJavaCamera = !mIsJavaCamera;
//
//	            if (mIsJavaCamera) {
//	                mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.tutorial1_activity_java_surface_view);
//	                toastMesage = "Java Camera";
//	            } else {
//	                mOpenCvCameraView = (CameraBridgeViewBase) findViewById(R.id.tutorial1_activity_native_surface_view);
//	                toastMesage = "Native Camera";
//	            }
//
//	            mOpenCvCameraView.setVisibility(SurfaceView.VISIBLE);
//	            mOpenCvCameraView.setCvCameraViewListener(this);
//	            mOpenCvCameraView.enableView();
//	            Toast toast = Toast.makeText(this, toastMesage, Toast.LENGTH_LONG);
//	            toast.show();
	        }

	        return true;
	    }

	    public void onCameraViewStarted(int width, int height) {
	    }

	    public void onCameraViewStopped() {
	    }

	    public Mat onCameraFrame(CvCameraViewFrame inputFrame) {
	    	Mat im=inputFrame.rgba();
	    	synchronized (im) {
	    		addr=im.getNativeObjAddr();
			}
	    	
	    	w=im.cols();
	    	h=im.rows();
	        return inputFrame.rgba();
	    }
}
