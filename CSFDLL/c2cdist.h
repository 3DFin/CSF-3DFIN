#ifndef _C2CDIST_H_
#define _C2CDIST_H_


#include "Cloth.h"
#include "point_cloud.h"

//������������֮��ľ���

class c2cdist
{
public:
	c2cdist(double threshold):class_treshold(threshold){}
	~c2cdist(){}
public:
	void calCloud2CloudDist(Cloth& cloth, csf::PointCloud &pc, std::vector<int>& groundIndexes, std::vector<int> &offGroundIndexes);
private:
	double class_treshold;//
};



#endif