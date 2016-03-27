/**
 * File: CvVersion.h
 * Project: 
 * Author: Dorian Galvez-Lopez
 * Date: February 3, 2013
 * Description: Checks OpenCV version
 * License: see the LICENSE.txt file
 *
 */

#include <opencv/cv.h>

#if !CV22 && !CV23 && !CV24
  #if CV_MAJOR_VERSION == 2
    #if CV_MINOR_VERSION == 2
      #define CV22 1
    #elif CV_MINOR_VERSION == 3
      #define CV23 1
    #elif CV_MINOR_VERSION == 4
      #define CV24 1
    #endif
  #else
    #define CV30 1
  #endif
#endif


