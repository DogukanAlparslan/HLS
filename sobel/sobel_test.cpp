#include "sobel.h"
#include <hls_opencv.h>
#include <iostream>

int main(){

	//RGB_IMAGE src;
	//RGB_IMAGE dst;
	//AXI_STREAM input;
	//AXI_STREAM output;

	 //src = cv::imread("C:\\Users\\dogukan.alparslan\\Desktop\\lena\\lenargb.tiff");
	//hls::Mat2AXIvideo(src, input);
	//sobel(input,output,src.rows,src.cols);
	//hls::AXIvideo2Mat(output, dst);
	//dst = cv::imwrite("C:\\Users\\dogukan.alparslan\\Desktop\\lena\\HLS_sobel.bmp", dst);


	IplImage* src;
	IplImage* dst;
	AXI_STREAM src_axi,dst_axi;
	src = cvLoadImage("C:\\Users\\dogukan.alparslan\\Desktop\\lena\\lenargb.tiff");
	dst = cvCreateImage(cvGetSize(src),src->depth , src->nChannels );

	IplImage2AXIvideo(src, src_axi);
	sobel(src_axi,dst_axi,src->height, src->width);
	AXIvideo2IplImage(dst_axi, dst);
	cvSaveImage("C:\\Users\\dogukan.alparslan\\Desktop\\lena\\HLS_sobel.bmp", dst);
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	return 0;
}
//cv::imwrite("C:\\Users\\dogukan.alparslan\\Desktop\\lena\\HLS_sobel.bmp", dst);
