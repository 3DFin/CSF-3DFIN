#ifndef _KNN_H_
#define _KNN_H_

#include "point_cloud.h"
#include "Cloth.h"

#define SQUARE_DIST(x1,y1,x2,y2) (((x1)-(x2))*((x1)-(x2))+((y1)-(y2))*((y1)-(y2)))

class Rasterlization
{

public:
	Rasterlization(){
	}
	~Rasterlization(){}

	//�Ե��ƽ������ٽ�������Ѱ����Χ�����N����  ����������
	void RasterTerrian(Cloth& cloth, wl::PointCloud &pc, vector<double> &heightVal);

};



#endif