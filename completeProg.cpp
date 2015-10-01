//Authors: Kevin Wang, David Lin, Alwathiqubellah Abumaali
//Summer of 2015 Research Project, Research Grad Student and supervisor: Viviana Medina
//UC Davis
/*
* This script takes in a directory of images as a parameter, reads the images, and analyzes them for 
* amount of "green" in them. This is for analyzing the various bean genotypes for effectiveness in 
* growing in different conditions. 
*/

#include <opencv2/opencv.hpp>
#include <iostream>
#include <string> 
#include <fstream>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
using namespace cv;
using namespace std;

/**Global variables***********/
int SQUARE_DIM = 3;                     //number of pixels on one edge of this box to be analyzed
string ALT_IMG_DIR = "alteredImages";   //directory for alternate images to be stored
string IMG_NAMES = "imgNames.txt";      //file for all image file names
string IMG_ANALYS = "ImgAnalysVal.csv"; //file for analyzed images in csv
/**Functions***********/
Mat threshold_RGB( Mat src, double &shadow, double &sun, double &prct);
void fileLooper(string directory, string fileName);				//Creates txt file of filenames
void mainLoop(ifstream& fs, ofstream& of, string directory);

/*****************************************************************************************************/
/*****************************************************************************************************/
int main(int argc, char** argv){ //command line argument: directory of images to be anlayzed

    /**** INITIALIZATION OF VARS AND CHECKING PROGRAM******/
    if ( argc != 2 ){
        cout << "usage: DisplayImage.out. Not enough Arguments";
        return -1;
    }
    //Create file with image names
    fileLooper(argv[1],IMG_NAMES);
    
    //Create file stream variables.
    string directory = argv[1];
    ifstream fs((directory + '/' + IMG_NAMES).c_str());
    ofstream of((directory + '/' + IMG_ANALYS).c_str());
    
    //Loops through the files in the directory. 
    // cout << "mainLoop" << endl;
    mainLoop(fs, of, directory);
    return 0;
}

/*****************************************************************************************************/
/*****************************************************************************************************/
void mainLoop(ifstream& fs, ofstream& of, string directory){
    string temp, altname;
    of << directory << endl;
    of << "FileName," << "Shadowed Leaves," << "Leaves in Sunlight," << "Total leaf" << endl;
    while( getline(fs, temp) ){
        double percent, shadow, sun;
        Mat img, altered;
        altname = directory + '/' + ALT_IMG_DIR + '/' + temp;
        temp = directory + '/' + temp;
        img = imread( temp, CV_LOAD_IMAGE_COLOR);
        if(!img.data){
            cout << temp << "ERR" << endl;
            of << temp << "ERR" << ',' << "ERR" << ',' << "ERR" << endl;
        }
        else{//5184, 690, 3075
            if(img.size().height > img.size().width){
                cout << temp;
                altered = threshold_RGB(img(Range(0, img.size().height),    
                                            Range( (int)(0.199652778*img.size().width), (int)(0.889756944*img.size().width))), 
                                        shadow, sun, percent);

                of << temp << ',' << shadow << ',' << sun << ',' << percent << endl;
                cout << /*temp <<*/ " " << img.size().height << "x" << (int)(0.889756944*img.size().width)-(int)(0.199652778*img.size().width) << endl;
                imwrite(altname, altered); 
            }
            else if(img.size().height < img.size().width){
                cout << temp;
                altered = threshold_RGB(img(Range( (int)(0.199652778*img.size().height), (int)(0.889756944*img.size().height)),
                                            Range(0, img.size().width)), 
                                        shadow, sun, percent);
                of << temp << ',' << shadow << ',' << sun << ',' << percent << endl;
                cout << /*temp <<*/ " " << (int)(0.889756944*img.size().height)-(int)(0.199652778*img.size().height) << "x" << img.size().width<<endl;
                imwrite(altname, altered);
            }
        }
    }
}
/*****************************************************************************************************/
/*****************************************************************************************************/
Mat threshold_RGB( Mat src, double &shadow, double &sun, double &prct){
	Mat rgbChannels[3], red, green, blue, altered;
	int sunLeaf = 0, shadowLeaf = 0, NUM_BOXES = src.rows*src.cols/(SQUARE_DIM*SQUARE_DIM);
	split(src,rgbChannels); //2: red, 1: green, 0: blue
	red = rgbChannels[2]; green = rgbChannels[1]; blue = rgbChannels[0];
	altered = src;
	
	/******Loops through entire image in SQUARE_DIM x SQUARE_DIM boxes, analyzing the colors in them **************/
	for(int row = SQUARE_DIM; row <= src.rows; row+=SQUARE_DIM){
		for(int col = SQUARE_DIM; col <= src.cols; col+=SQUARE_DIM){

			Scalar srcMeans, srcStdDv;
			meanStdDev(src(Range(row-SQUARE_DIM,row),Range(col-SQUARE_DIM,col)), srcMeans,srcStdDv);

			if(srcMeans[1]>srcMeans[2] && srcMeans[1]>srcMeans[0] ){ //leaf
				if(srcMeans[1]<65){ //leaf in shadow
					shadowLeaf++;
					altered(Range(row-SQUARE_DIM,row),Range(col-SQUARE_DIM,col)).setTo(Scalar(50,120,50));
				}
				else if(srcMeans[1]-srcMeans[2]>15 && srcMeans[1]-srcMeans[0] > 30){ //leaf in direct sunlight
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
	shadow=	(double)(shadowLeaf)/NUM_BOXES;
	sun =	(double)(sunLeaf)/NUM_BOXES;
	prct =  (double)(shadowLeaf+sunLeaf)/NUM_BOXES;	
    return altered;
}
/*****************************************************************************************************/
/*****************************************************************************************************/
void fileLooper(string directory, string fileName){
	DIR *dir = NULL;
    struct dirent *pent = NULL;
    // string jpg = ".jpg";		
    ofstream of((directory + '/' + fileName).c_str());
    dir = opendir(directory.c_str());
    if(dir == NULL){
    	cout << "directory could not be initialized" << endl;
    }

    while((pent = readdir(dir)))
    {
    	if(pent == NULL)
    	{
    		cout << "directory struct could not be initialized catch" << endl;
    		break;
    	}
    	bool flag = true;
    	string temp = pent->d_name;
    	if( temp.length() > 4 && (temp.substr(temp.length()-4, 4)==".jpg" || temp.substr(temp.length()-4,4) == ".JPG") ){
    		of << temp << endl;
    	}
    }
    closedir(dir);
    mkdir((directory+'/'+ALT_IMG_DIR).c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}