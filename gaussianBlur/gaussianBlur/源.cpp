#include <opencv2/opencv.hpp>

void example(const cv::Mat & image)
{
	//����һЩ������ʾ���룬�����ͼƬ

	cv::namedWindow("Example-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example-out", cv::WINDOW_AUTOSIZE);

	//��ʾ���봰��
	cv::imshow("Example-in", image);

	//����һ��ƽ���������
	cv::Mat out;
	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

	cv::imshow("Example-out", out);
	cv::waitKey(0);
}
int main(int argc,char** argv)
{
	cv::Mat img = cv::imread(argv[1], -1);
	if (img.empty())  //��ֹ�ڴ�й©
		return -1;
	example(img);
	return 0;
}
