#ifndef XYZ_READER_H_
#define XYZ_READER_H_

#include <string>
#include <vector>
using namespace std;

#include "point_cloud.h"

//��fname�ļ��ж�ȡ���ƣ����������ݴ洢��pointcloud��
void read_xyz(string fname, csf::PointCloud &pointcloud);


#endif