
#include "inverter.h"
#include "stdio.h"
#include "hls_video.h"
#include "hls_opencv.h"

void inverter(hls::stream<imgIn> &dataIn,hls::stream<imgIn> &dataOut,u32 size);

void saveImage(const std::string path, cv::InputArray inArr)
{
double xmin;
double xmax;
cv::minMaxIdx(inArr, &xmin, &xmax);
cv::Mat adjMap;
cv::convertScaleAbs(inArr, adjMap, 255 / xmax);
cv::imwrite(path,adjMap);
}
