#include "opencv2/opencv.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        return 1;
    }
    std::string from(argv[1]);

    cv::VideoCapture cap(from);
    cv::namedWindow(from,1);
    while (cap.isOpened()) {
        cv::Mat origin, gray;
        cap >> origin;
        cv::cvtColor(origin, gray, CV_BGR2GRAY );

        // cv::Mat smooth(frame);
        // cv::GaussianBlur(frame, smooth, cv::Size(3, 3), 0, 0);
        cv::Mat edges;
        cv::blur(gray, edges, cv::Size(3,3));

        cv::Canny(edges, edges, 100, 300, 3);

        cv::Mat result;
        result = cv::Scalar::all(0);
        origin.copyTo(result, edges);

        cv::imshow(from, result);
        if(cv::waitKey(30) >= 0)
            break;
    }
}
