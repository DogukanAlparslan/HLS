#include "sobel.h"

void sobel(AXI_STREAM &dataIn,AXI_STREAM &dataOut,int row,int col){
//#pragma HLS INTERFACE ap_ctrl_none port=return
#pragma HLS INTERFACE s_axilite port=col bundle=control
#pragma HLS INTERFACE s_axilite port=row bundle=control
#pragma HLS INTERFACE axis register both port=dataOut
#pragma HLS INTERFACE axis register both port=dataIn

RGB_IMAGE img_0(row,col);
GRAY_IMAGE img_1(row,col);
GRAY_IMAGE img_1_a(row,col);
GRAY_IMAGE img_1_b(row,col);
GRAY_IMAGE img_2(row,col);
GRAY_IMAGE img_3(row,col);
GRAY_IMAGE img_4(row,col);
RGB_IMAGE img_5(row,col);


#pragma HLS DATAFLOW
hls::AXIvideo2Mat(dataIn, img_0);
hls::CvtColor<HLS_BGR2GRAY>(img_0, img_1);
hls::Duplicate(img_1, img_1_a, img_1_b);
hls::Sobel<1,0,3>(img_1_a, img_2);
hls::Sobel<0,1,3>(img_1_b, img_3);
hls::AddWeighted(img_2, 0.5, img_3, 0.5, 0.0, img_4);
hls::CvtColor<HLS_GRAY2RGB>(img_4,img_5);
hls::Mat2AXIvideo(img_5, dataOut)	;


}
