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

Mat image = imread("/Users/wathiqabumaali/Downloads/Plant/img3.jpg");
Mat subImg = image(Range(0, 5184), Range(690, 3075));
//(100, 900) (145,580)
//Mat croppedImage;
//Mat("/Users/wathiqabumaali/Downloads/Plant/img1.jpg", myRoi).copyTo(croppedImage)

imread(argv[1], CV_LOAD_IMAGE_COLOR); // Read the file

if(image.empty())                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
    }

namedWindow( "Original image", CV_WINDOW_AUTOSIZE ); // Create a window for display.
imshow( "Original image", image );      // Show the image inside it.
imshow( "Cropped image", subImg),
waitKey(0);                                          // Wait for a keystroke in the window
return 0;

}

