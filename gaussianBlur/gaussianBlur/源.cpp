#include <opencv2/opencv.hpp>

void example(const cv::Mat & image)
{
	//创建一些窗口显示输入，和输出图片

	cv::namedWindow("Example-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example-out", cv::WINDOW_AUTOSIZE);

	//显示输入窗口
	cv::imshow("Example-in", image);

	//创建一个平滑处理过程
	cv::Mat out;
	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

	cv::imshow("Example-out", out);
	cv::waitKey(0);
}
int main(int argc,char** argv)
{
	cv::Mat img = cv::imread(argv[1], -1);
	if (img.empty())  //防止内存泄漏
		return -1;
	example(img);
	return 0;
}
