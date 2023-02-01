#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
#if 1
    Mat img = imread("D:\\Workspace\\Anaconda\\JupteNotebook\\Demo\\1_result.jpg", 0);
    threshold(img, img, 150, 120, THRESH_BINARY_INV); // to delete some noise
    Mat labels;
    connectedComponents(img, labels, 8, CV_16U);//连通域提取
    Mat maximage = labels == 1;
    maximage.convertTo(maximage, CV_8UC1);
    //找圆的范围，因为后面minEnclosingCircle函数需要输入
    Mat locations;
    findNonZero(maximage, locations);
    Point2f center;
    float radius;
    minEnclosingCircle(locations, center, radius);
    Mat showImag = Mat::ones(img.size(), CV_8UC3);
    circle(showImag, center, radius, Scalar(0, 255, 255), 2);
    //---linear Cart to Polar
    Mat matLinearPolar;
    linearPolar(
        img, matLinearPolar,
        center,
        radius, INTER_CUBIC);
    //log Cart to Polar
    Mat matLogPolar;
    cv::logPolar(
        img,
        matLogPolar,
        center,
        radius / 3,
        INTER_CUBIC
    );
    threshold(matLinearPolar, matLinearPolar, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
    threshold(matLogPolar, matLogPolar, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
    imshow("showImag", showImag);
    imshow("matLinearPolar", matLinearPolar);
    imshow("matLogPolar", matLogPolar);

    waitKey(0);
    return 0;
#endif

#if 0
    Mat img = imread("D:\\Workspace\\Anaconda\\JupteNotebook\\Demo\\2.jpg");
    imshow("JPG", img);
    waitKey(0);
    return 0;
#endif
}