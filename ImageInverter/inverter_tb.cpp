#include "inverter_tb.h"

#define rowSize 512
#define colSize 512
#define imageSize (rowSize*colSize)

char image[rowSize][colSize];

int main(){

	cv::Mat rgb_data;
	cv::Mat gray_data;
	hls::Mat<rowSize,colSize,HLS_8UC1> dst;
	hls::stream<imgIn> dataIn,dataOut;
	imgIn input,output;

	rgb_data = cv::imread("C:\\Users\\dogukan.alparslan\\Desktop\\lena\\lenargb.tiff");
	cv::cvtColor(rgb_data, gray_data, CV_BGR2GRAY);
	cv::Mat imgCvOut(cv::Size(gray_data.cols,gray_data.rows),CV_8UC1,image,cv::Mat::AUTO_STEP);
	printf("Image Row = %d , Image Col = %d, Image Size = %d\n",gray_data.rows,gray_data.cols);

	for(int i = 0; i<gray_data.rows; i++ ){
		for(int j = 0; j<gray_data.cols; j++ ){
			input.data = gray_data.at<unsigned char>(i,j);
			input.keep = 1; input.strb = 1;

			dataIn << input;
		}
	}

	inverter(dataIn,dataOut,imageSize);
	for(int i = 0; i<gray_data.rows; i++ ){
			for(int j = 0; j<gray_data.cols; j++ ){
				dataOut.read(output);

				image[i][j] = output.data;
			}
		}
	saveImage("C:\\Users\\dogukan.alparslan\\Desktop\\lena\\lena_inverter.bmp", imgCvOut);

	/*
	// IplImage Usage read and write image

	IplImage* src;
	IplImage* dst;
	hls::stream<imgIn> dataIn,dataOut;
	printf("Loading Image..\n");
	src = cvLoadImage("C:\\Users\\dogukan.alparslan\\Desktop\\lena\\lena_gray.bmp");
	printf("Image Row = %d , Image Col = %d, Image channel = %d\n",src->height,src->width,src->nChannels);
	dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
	IplImage2AXIvideo(src, dataIn);
	inverter(dataIn,dataOut,imageSize);
	AXIvideo2IplImage(dataOut, dst);
	cvSaveImage("C:\\Users\\dogukan.alparslan\\Desktop\\lena\\lena_inverter.bmp", dst);
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	 */
	return 0;
}
