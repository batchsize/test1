#include <iostream>
#include "opencv2/opencv.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include<json/json.h>
using namespace std;
using namespace cv;

string readFileIntoString(char * filename)  
{  
	ifstream ifile(filename);  
	ostringstream buf;  
	char ch;  
	while(buf&&ifile.get(ch))  
	buf.put(ch);  
	return buf.str();  
}  
int main() {
	string str;  
	str=readFileIntoString("../data/boxes.json"); 
	Json::Reader  reader;
	Json::Value   value;
	int a[2], b[2];
// print "box_b"
	if(reader.parse(str,value))
	{
		if(!value["boxes"].isNull())
		{
			for (int i = 0; i < value["boxes"].size(); ++i) {
				Json::Value value1  = value["boxes"][i];
				string str = value1["name"].asString() ;
				string str1 = "box_b";
				if (strcmp(str.c_str(), str1.c_str()) != 0) {
					Json::Value vv = value1["rectangle"]["left_top"];
					Json::Value vv2 = value1["rectangle"]["right_bottom"];
					for (int i = 0; i < vv.size(); ++i) {
						a[i] = vv[i].asInt();
						b[i] = vv2[i].asInt();
					}
					cout << value1["rectangle"]["left_top"] << endl;
					cout << value1["rectangle"]["right_bottom"] << endl;
				}
			}	
		}
	}

// copy to roi
	Mat img1 = imread("../data/yao.jpg");
	Mat img2 = imread("../data/img.jpg");
	cv::Rect roi = cv::Rect(a[0], a[1], b[0] - a[0] + 1, b[1] - a[1] + 1); 
	cout << roi.x << " " << roi.width;
	resize(img1, img1, Size(roi.width, roi.height));	
	img1.copyTo(img2(roi));
	imshow("test", img2);
	waitKey(0);

    return 0;
}