#ifndef _KNN_H_
#define _KNN_H_

#include "point_cloud.h"
#include "Cloth.h"

class Rasterlization
{
public:
	int N;
public:
	Rasterlization(int N=1){
		this->N = N;
	}
	~Rasterlization(){}

	//�Ե��ƽ������ٽ�������Ѱ����Χ�����N����  ����������
	void RasterTerrian(Cloth cloth, PointCloud &pc, vector<double> &heightVal);

};



#endif