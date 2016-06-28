#ifndef _KNN_H_
#define _KNN_H_

#include "point_cloud.h"
#include "Cloth.h"

class Rasterlization
{

public:
	Rasterlization(){
	}
	~Rasterlization(){}

	double distSquare(double x, double y, double x1, double y1)
	{
		return (x - x1)*(x - x1) + (y - y1)*(y - y1);
	}

	//�Ե��ƽ������ٽ�������Ѱ����Χ�����N����  ����������
	void RasterTerrian(Cloth& cloth, PointCloud &pc, vector<double> &heightVal);

};



#endif