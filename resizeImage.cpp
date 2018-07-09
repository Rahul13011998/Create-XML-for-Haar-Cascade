#include<stdio.h>
#include<iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    cv::Mat img = cv::imread("watch.jpg", cv::IMREAD_GRAYSCALE);
    cv::resize(img,img, cv::Size(50,50));
    cv::imwrite("watchResized2.jpg",img);
    return 0;
}
