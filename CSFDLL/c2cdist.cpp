#include "c2cdist.h"
#include <cmath>


void c2cdist::calCloud2CloudDist(Cloth& cloth, csf::PointCloud &pc, std::vector<int>& groundIndexes, std::vector<int>& offGroundIndexes)
{
	groundIndexes.resize(0);
	offGroundIndexes.resize(0);
	//�ҵ�ÿ�������״�㵽����ֱ�ӵľ��룬�øþ�����ֵ���Ե��ƽ��з���
	//˫���Բ�ֵ
	for (int i = 0; i < pc.size(); i++)
	{
		double pc_x = pc[i].x;
		double pc_z = pc[i].z;
		//���������벼�ϵ����Ͻ��������
		double deltaX = pc_x - cloth.origin_pos.f[0];
		double deltaZ = pc_z - cloth.origin_pos.f[2];
		//�õ���������ڲ���С�������Ͻǵ����� �����ĸ��ǵ�ֱ�Ϊ0 1 2 3 ˳ʱ����
		int col0 = int(deltaX / cloth.step_x);
		int row0 = int(deltaZ / cloth.step_y);
		int col1 = col0 + 1;
		int row1 = row0;
		int col2 = col0 + 1;
		int row2 = row0 + 1;
		int col3 = col0;
		int row3 = row0 + 1;
		//�����������Ͻǽ�������ϵ���������һ����[0,1]
		double subdeltaX = (deltaX - col0*cloth.step_x) / cloth.step_x;
		double subdeltaZ = (deltaZ - row0*cloth.step_y) / cloth.step_y;
		//cout << subdeltaX << " " << subdeltaZ << endl;
		//˫���Բ�ֵ
		//f(x,y)=f(0,0)(1-x)(1-y)+f(0,1)(1-x)y+f(1,1)xy+f(1,0)x(1-y)
		double fxy = cloth.getParticle(col0, row0)->pos.f[1]*(1 - subdeltaX)*(1 - subdeltaZ)
			+ cloth.getParticle(col3, row3)->pos.f[1] * (1 - subdeltaX)*subdeltaZ
			+ cloth.getParticle(col2, row2)->pos.f[1] * subdeltaX*subdeltaZ
			+ cloth.getParticle(col1, row1)->pos.f[1] * subdeltaX*(1 - subdeltaZ);
		float height_var = fxy - pc[i].y;
		if (std::fabs(height_var) < class_treshold)
		{
			groundIndexes.push_back(i);
		}
		else
		{
			offGroundIndexes.push_back(i);
		}

	}
}