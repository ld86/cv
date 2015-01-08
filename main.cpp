#include "opencv2/opencv.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        return 1;
    }
    std::string from(argv[1]);

    cv::VideoCapture cap(from);
    cv::namedWindow(from,1);
    while (cap.isOpened()) {
        cv::Mat frame;
        cap >> frame;
        cv::imshow(from, frame);
        if(cv::waitKey(30) >= 0)
            break;
    }
}
