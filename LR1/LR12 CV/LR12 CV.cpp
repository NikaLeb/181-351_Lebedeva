// LR13  Curl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

#include <stdio.h>
#include <iostream>
#include <vector>

/*#include <opencv2\opencv.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2\imgcodecs.hpp>
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\objdetect.hpp>
//#include <opencv2\highgui\highgui_winrt.hpp>

int main()
{
	/* Инициализация */
	/*cv::CascadeClassifier face_cascade;
	cv::Mat image = cv::imread("group1.jpg");
	cv::Mat groupFaces = cv::Mat(image.rows, image.cols, CV_8UC4);
	cv::cvtColor(image, groupFaces, cv::COLOR_BGR2BGRA);
	//cv::winrt_initContainer(cvContainer);
	cv::imshow(std::string("Window 1"), groupFaces);

	if (!face_cascade.load("haarcascade_frontalface_alt.xml")) {
		std::cout << "Couldn't load face detector" << std::endl;
	}

	/* Обнаружение */
	/*if (!groupFaces.empty()) {
		std::vector<cv::Rect> facesColl;
		cv::Mat frame_gray;

		cvtColor(groupFaces, frame_gray, cv::COLOR_BGR2GRAY);
		cv::equalizeHist(frame_gray, frame_gray);

		// Detect faces
		face_cascade.detectMultiScale(frame_gray,
			facesColl,
			1.1, 2,
			0 | cv::CASCADE_SCALE_IMAGE,
			cv::Size(1, 1));
		for (unsigned int i = 0; i < facesColl.size(); i++)
		{
			auto face = facesColl[i];
			cv::rectangle(groupFaces, face, cv::Scalar(0, 255, 255), 5);
		}

		cv::imshow(std::string("Window 2"), groupFaces);
	}
	else {
		std::cout << "Initialize image before processing" << std::endl;
	}

	cv::waitKey();
	return 0;
}
*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
