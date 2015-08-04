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

Mat croppedImage(Mat rgb); // Cropping function

int main( int argc, char** argv ){

    
Mat img = imread("/Users/wathiqabumaali/Downloads/Plant/img1.jpg");
Mat cropped;
string name = "_cropped";

imread(argv[1], CV_LOAD_IMAGE_COLOR); // Read the file

if(img.empty())                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
    }

    namedWindow( "Display window", CV_WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", img );                   // Show the image inside it.
    cropped = croppedImage(img);
    namedWindow("Cropped",WINDOW_NORMAL);
    imshow("Cropped", cropped);

waitKey(0);                                          // Wait for a keystroke in the window
return 0;

}

Mat croppedImage(Mat src){

Mat cropped;
cropped = src;
IplImage* img; // Source image
IplImage* cropImg; // Croped image destination
CvRect cropRect = cvRect(10, 12, 100, 300); //ROI in image
cvSetImageROI(img, cropRect);
cvCopy(img, cropImg, NULL); // copies only crop region
cvResetImageROI(img);
return cropped;

}