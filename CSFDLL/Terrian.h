#ifndef _TERRIAN_H_
#define _TERRIAN_H_

#include <string>
#include <vector>
#include <iostream>
#include<iomanip>
#include <fstream>
using namespace std;

#include "point_cloud.h"

class Terrian
{
public:
	PointCloud pc; //����
	vector<double> cube;//  ��Χ���е��Ƶ�����������
	double off_avg_x, off_avg_z;//�Զ�shift�㷨

	Terrian(PointCloud &pc);
	~Terrian();

	//������Ƶ����ֵ����Сֵ
	double getMin(int direction);
	double getMax(int direction);

	//������Ƶ����Χ������
	void bound_box();

	//�����Ʊ��浽�ļ�
	void saveToFile(LASPoint offset, string path = "");
};


#endif