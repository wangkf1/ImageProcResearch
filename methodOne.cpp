#include <opencv2/opencv.hpp>
#include <iostream>
#include <string> 
#include <cmath>
using namespace cv;
using namespace std;
//Global variables
int SQUARE_DIM = 3;


//Functions
Mat threshold_RGB( Mat rgb);
double calcSSTR(Scalar arr, int n);
double calcSSE(Scalar means, Scalar stddevs, int n);

int main(int argc, char** argv){
    if ( argc != 2 )
    {
        cout << "usage: DisplayImage.out <Image_Path>\n";
        return -1;
    }
    
    Mat img, altered;
    String name = "_altered";
    name.append(argv[1]);
    
    img = imread( argv[1], 1);
    if(!img.data){
        cout << "No img data" << endl;
        return -1;
    }
    
	namedWindow( "Original", WINDOW_NORMAL );
	imshow( "Original", img );
	altered = threshold_RGB(img);
    namedWindow("Altered",WINDOW_NORMAL);
    imshow("Altered", altered);
	imwrite(name, altered);
    while(true)
  	{
    	int c;
    	c = waitKey( 20 );
    	if( (char)c == 27 )
      		break;
  	}
    return 0;
}

Mat threshold_RGB(Mat src){
	Mat rgbChannels[3], red, green, blue, altered;
	int sunLeaf = 0, shadowLeaf = 0, NUM_BOXES = src.rows*src.cols/(SQUARE_DIM*SQUARE_DIM);

	split(src,rgbChannels); //2: red, 1: green, 0: blue
	red = rgbChannels[2]; green = rgbChannels[1]; blue = rgbChannels[0];
	altered = src;
	
	for(int row = SQUARE_DIM; row <= src.rows; row+=SQUARE_DIM){
		for(int col = SQUARE_DIM; col <= src.cols; col+=SQUARE_DIM){

			Scalar srcMeans, srcStdDv;
			meanStdDev(src(Range(row-SQUARE_DIM,row),Range(col-SQUARE_DIM,col)), srcMeans,srcStdDv);

			if(srcMeans[1]>srcMeans[2] && srcMeans[1]>srcMeans[0]){ //leaf
				if(srcMeans[1]<65){
					shadowLeaf++;
					altered(Range(row-SQUARE_DIM,row),Range(col-SQUARE_DIM,col)).setTo(Scalar(50,120,50));
				}
				else if(srcMeans[1]-srcMeans[2]>15 && srcMeans[1]-srcMeans[0] > 30){
					sunLeaf++;
					altered(Range(row-SQUARE_DIM,row),Range(col-SQUARE_DIM,col)).setTo(Scalar(0,255,0));
				}
			}
			else if(srcMeans[2]>srcMeans[1] && srcMeans[1]>srcMeans[0]){
				altered(Range(row-SQUARE_DIM,row),Range(col-SQUARE_DIM,col)).setTo(255);
			}
			else{
				altered(Range(row-SQUARE_DIM,row),Range(col-SQUARE_DIM,col)).setTo(Scalar(0,0,255));
			}
		}
	}
	cout << "Shadow: " << shadowLeaf << " Sun leaf: " << sunLeaf << " Total: " << NUM_BOXES << endl;
	cout << "Total percentage: " << (double)(shadowLeaf+sunLeaf)/NUM_BOXES << endl;
	return altered;
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