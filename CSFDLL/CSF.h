//cloth simulation filter for airborne lidar filtering
#ifndef _CSF_H_
#define _CSF_H_

#include "point_cloud.h"
#include <iostream>
using namespace wl;


#pragma once;

//�ú������dll��Ŀ�ڲ�ʹ��__declspec(dllexport)����
//��dll��Ŀ�ⲿʹ��ʱ����__declspec(dllimport)����
//��DLL_IMPLEMENT��CSF.cpp�ж���
#ifdef DLL_IMPLEMENT  
#define DLL_API __declspec(dllexport)  
#else  
#define DLL_API __declspec(dllimport)  
#endif

class DLL_API  CSF
{
public:
	CSF();
	~CSF();

	//���õ������� ��vector������� 
	void setPointCloud(vector< LASPoint > points);
	//���ļ���ȡ���� ��Ҫ���ڲ���
	void readPointsFromFile(string filename);
	//�������㵽�ļ� ������
	void saveGroundPoints(vector<int> grp, string path = "");


	//get size of pointcloud
	size_t size(){return point_cloud.size();}


	//�����е�PointCloud������
	void setPointCloud(PointCloud &pc);

	//ִ���˲����� �õ���������PointCloud �е����
	vector<int> do_filtering();


private:
	 class __declspec (dllexport) wl::PointCloud point_cloud;

public:

	struct{
		//perameters
		//���ٽ������ǵĵ�����һ������Ϊ1
		int k_nearest_points;

		//�Ƿ���б��º���
		bool bSloopSmooth;
		//ʱ�䲽��
		double time_step;

		//������ֵ
		double class_threshold;

		//���ϸ�����С
		double cloth_resolution;

		//����Ӳ�Ȳ���
		int rigidness;

		//��������
		int interations;
	}params;
};

#endif