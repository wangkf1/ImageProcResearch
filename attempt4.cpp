#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv ){

Mat image = imread(argv[1], 1); // Read the file
Mat croppedImage = image(Range(0, 50), Range(0, 100));

if(image.empty())                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
    }

	namedWindow( "Original", WINDOW_NORMAL );
	imshow( "Original", image );

    namedWindow("Altered",WINDOW_NORMAL);
    imshow("Altered", croppedImage);

	while(true)
  	{
    	int c;
    	c = waitKey( 20 );
    	if( (char)c == 27 )
      		break;
  	}                                         // Wait for a keystroke in the window
return 0;

}

