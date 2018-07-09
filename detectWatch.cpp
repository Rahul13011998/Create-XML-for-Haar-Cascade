#include<stdio.h>
#include<iostream>
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace std;

cv::VideoCapture openWebcam() {
    const char* pipe = "autovideosrc device=/dev/video0  ! appsink";
    cv::VideoCapture webcam(pipe);

    if (!webcam.isOpened()) {
        cout << "Connection to a camera failed" << endl;
    }

    return webcam;
}

int detectWatch() {
    cv::Mat frame, grayFrame;
    cv::Size windowSize(1000, 1000);
    cv::namedWindow("Example", cv::WINDOW_NORMAL);
    cv::resizeWindow("Example", windowSize);
    cv::VideoCapture webcam = openWebcam();
    vector<cv::Rect> watch;


    cv::String watchCascadeFile = "watchCascade.xml";
    cv::CascadeClassifier watchCascade;

    if (!watchCascade.load(watchCascadeFile)) {
        cout << "Watch Cascade File Load Error" << endl;
        return -1;
    }

    for (;;) {
        webcam >> frame;
        if (frame.empty()) {
            cout << "Frame Error" << endl;
            return -1;
        }

        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

        watchCascade.detectMultiScale(grayFrame, watch, 1.1, 2, 0, cv::Size(30,30));
        for (size_t i = 0; i < watch.size(); i++) {
            cv::Point center(watch[i].x + watch[i].width*0.5, watch[i].y + watch[i].height*0.5);
            cv::circle(frame, center, watch[i].width*0.5, cv::Scalar(0,0,0), 2, 8, 0);
        }

        cv::imshow("Example", frame);
        if (cv::waitKey(33) > 0) return -1;
    }



}

int main(int argc, char *argv[])
{
    detectWatch();
    return 0;
}

