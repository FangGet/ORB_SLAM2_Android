**This Project is out of date**

This project is an Android version for ORB_SLAM2 based on Raul Mur-Artal's opensource project: [ORB_SLAM2](https://github.com/raulmur/ORB_SLAM2 "ORB_SLAM2").

Author: **Frank**

**If anyone would like to only have a test on it, please visit:[ORB_SLAM2_Android_APK](http://fir.im/uzdx "ORB_SLAM@_Android_APK");**

1.Dependency
-------------



 - Eclipse with ADT and android-ndk-r11;
 - OpenCV4Android2.4.9,download here:[opencv4android 2.4.9](http://opencv.org/downloads.html "opencv");
 - All necessary dependencies required by ORB_SLAM2 except pangolin(I removed pangolin and rewrited opengl part for android);
 
2.Build Project 
-------------


To build ORB_SLAM2_Android, you can simply import cloned project into eclipse and import opencv2.4.9forAndroid library into Eclipse. Then set it as ORB's library project(it may have been setted already).Run ndk-build and library will be generated into ***libs*** directory. After all this, your work tree will be like this:

![这里写图片描述](http://img.blog.csdn.net/20160404211617003)

To convert it into Android Studio, you need to create a new AS project and add core code as a module of it while opencv library will also be a module.

3.Using Instruction
-------------------


 1. if you want to test camera mode, please make sure you have installed corresponding version of opencvForAndroid library into your phone and it has been opened;
 2. open the apk. There are two parts for ORB,namely dataset-mode and camera-mode:
![这里写图片描述](http://img.blog.csdn.net/20160404214323857)
 3. select dataset-mode and select corresponding files for test(you have to pull ORBvoc.txt/TUMX.yaml/dataset to you external storage), ps:there is a button named select special for  directory select;
 ![这里写图片描述](http://img.blog.csdn.net/20160404214355482)
 ![这里写图片描述](http://img.blog.csdn.net/20160404214410014)
 4. finish and start SLAM,then voc will be loaded, this may take about one minute(depend on your phone) and system will run automaticlly after initiate step finished;
![这里写图片描述](http://img.blog.csdn.net/20160404214441514)
 5. camera-mode is nearly the same as dataset mode;

4.Something else
----------------

 1. you can change size of camera preview in res/activity_camera _orb.xml;
 2. there is some bug with the demonstrate of camera pose, if anyone want to fix it, they can modify ***MapDrawer::DrawCurrentCamera()*** in ***jni/ORB_SLAM2/src/MapDrawer.cc***
 3. some dependencies inside ***jni/Thirdparty*** may be excess and can be removed. I have never checked for it;

5.Ending
--------
If you have any questions, feel free to contact me [fangasfrank@gmail.com](mailto://fangasfrank@gmail.com "frank")

