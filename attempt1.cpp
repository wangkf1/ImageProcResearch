#include <opencv2/opencv.hpp>
#include <iostream>
#include <string> 
#include <cmath>
#include <iostream>
#include <dirent.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h> 
#include <opencv/highgui.h>
#include <opencv2/imgproc/imgproc.hpp> 
#include <iostream>

using namespace cv;
using namespace std;


int main( int argc, char** argv ){

    
    Mat img = imread("/Users/wathiqabumaali/Downloads/Plant/img1.jpg");
    imread(argv[1], CV_LOAD_IMAGE_COLOR); // Read the file

    if(img.empty())                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
    }

   cvSetImageROI(img, cvRect(0, 0, 500, 500));
   tmp = cvCreateImage(cvGetSize(img), img -> depth, img -> nChannels):
   cvCopy(img, tmp, NULL);
   cvResetImageROI(img);
   img = cvCloneImage(tmp);
   cout << "Orig dimensions afer crop \n" , tmp -> width, tmp -> height);

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;

}


