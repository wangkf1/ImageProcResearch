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

    int offset_x = 129;
    int offset_y = 129;

    Rect roi;
    roi.x = offset_x;
    roi.y = offset_y;
    roi.width = img.size().width - (offset_x * 2);
    roi.width = img.size().width - (offset_y * 2);

    Mat crop = img(roi);
    imshow("crop" , crop);

    waitKey(0);                                          // Wait for a keystroke in the window

    return 0;

}
