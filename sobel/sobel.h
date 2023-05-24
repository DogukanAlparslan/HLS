#include "hls_video.h"
#include "ap_axi_sdata.h"
#include "hls_stream.h"

#define MAX_WIDTH 512
#define MAX_HEIGHT 512

typedef ap_axiu<32,1,1,1>  side_channels;
typedef hls::stream<side_channels> AXI_STREAM;

typedef hls::Mat<MAX_HEIGHT,MAX_WIDTH, HLS_8UC3> RGB_IMAGE;
typedef hls::Mat<MAX_HEIGHT,MAX_WIDTH, HLS_8UC1> GRAY_IMAGE;
void sobel(AXI_STREAM &dataIn,AXI_STREAM &dataOut,int row,int col);
