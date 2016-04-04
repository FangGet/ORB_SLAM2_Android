package orb.slam2.android;


import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity implements OnClickListener{
	Button datasetMode,cameraMode;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);//隐藏标题
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
          WindowManager.LayoutParams.FLAG_FULLSCREEN);//设置全屏
        setContentView(R.layout.activity_main);
        datasetMode=(Button)findViewById(R.id.dataset_mode);
        cameraMode=(Button)findViewById(R.id.camera_mode);
        datasetMode.setOnClickListener(this);
        cameraMode.setOnClickListener(this);
    }

	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		switch(v.getId()){
		case R.id.dataset_mode:
			startActivity(new Intent(MainActivity.this,DataSetModeActivity.class));
			break;
		case R.id.camera_mode:
			//Toast.makeText(MainActivity.this, "on the way...", Toast.LENGTH_LONG).show();
			startActivity(new Intent(MainActivity.this,CameraModeActivity.class));
			break;
		}
	}
}
