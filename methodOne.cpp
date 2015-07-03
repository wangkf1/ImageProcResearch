#include <opencv2/opencv.hpp>
#include <iostream>
#include <string> 
#include <cmath>
using namespace cv;
using namespace std;

void threshold_RGB( Mat rgb);
double calcSSTR(Scalar arr, int n);
double calcSSE(Scalar means, Scalar stddevs, int n);

int main(int argc, char** argv){
    if ( argc != 2 )
    {
        cout << "usage: DisplayImage.out <Image_Path>\n";
        return -1;
    }
    
    Mat img;
    img = imread( argv[1], 1);
    if(!img.data){
        cout << "No img data" << endl;
        return -1;
    }
    
	namedWindow( "window_name", WINDOW_NORMAL );
	imshow( "window_name", img );
    threshold_RGB(img);

    while(true)
  	{
    	int c;
    	c = waitKey( 20 );
    	if( (char)c == 27 )
      		break;
  	}
    return 0;
}
void threshold_RGB(Mat src){
	Mat rgbChannels[3];
	split(src,rgbChannels); //2: red, 1: green, 0: blue
	Mat red = rgbChannels[2], green = rgbChannels[1], blue = rgbChannels[0];
	int leafCount = 0, NUM_BOXES = src.rows*src.cols/81;
	for(int row = 9; row < src.rows; row+=9){

		for(int col = 9; col < src.cols; col+=9){
			Scalar  srcMeans, srcStdDv;
			// double sstr, sse, ssto,mstr,mse,fRatio,FCRIT = 7.110447;

			meanStdDev(src(Range(row-9,row),Range(col-9,col)), srcMeans,srcStdDv);
			cout << srcMeans;
			if((srcMeans[1]-srcMeans[2]) > 25 && srcMeans[1] - srcMeans[0] > 40 && srcMeans[1]>srcMeans[2] && srcMeans[2] > srcMeans[0]){
				cout << "	LEAF" << endl;
				leafCount++;
			}
			else
				cout << endl;
		}
	}
	cout << leafCount << endl;
	cout << "Total percentage: " << (double)leafCount/NUM_BOXES << endl;
}
//for constant sample sizes across factor levels only
double calcSSTR(Scalar means, int n){
	double meanTotal = 0, sum = 0;
	for(int i = 0; i < 3; i++){
		meanTotal += means[i];
	}
	meanTotal = meanTotal/3;
	for(int j = 0; j < 3; j++){					//the sum of:
		sum += n*pow((means[j] - meanTotal),2);	//n*(mean of yj - total mean)
	}
	return sum;
}
double calcSSE(Scalar means, Scalar stddevs, int n){
	double sum = 0;
	for(int i = 0; i < 3; i++){ 				//the sum for all factor levels (i=3) of:
		sum += pow(stddevs[i],2)*n;				//n*(variance of xi) = n*sum of (yij - yi) = 
	}
	return sum;
}