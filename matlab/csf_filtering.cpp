
// SimpleDLLTest.cpp : �������̨Ӧ�ó������ڵ㡣
#include <mex.h>
#include <vector>
#include <string>
#include "CSF.h" 
using namespace std;
#pragma comment(lib, "CSF.lib")

//input: pointcloud riginess isSlopSmooth cloth_resolution 
void csf_filtering(double* points
	,int rigidness
	, bool isSmooth
	, double cloth_resolution
	,int rows,std::vector<int>& groundIndex
	,std::vector<int>& nongroundIndex
	,int& groundRows
	,int& nongroundRows
	)
{
	#define A(i,j) points[i+j*rows]

	CSF csf;
	//step 1 read point cloud from N*3 array

	csf.setPointCloud(points,rows);

	//��ע����ʵ��ʹ�ù����У������������������ṩ�����ú���Ϊ
	//csf.setPointCloud(pc);//pcΪPointCloud��

	//step 2 ���ò���
	csf.params.bSloopSmooth = isSmooth;
	csf.params.class_threshold = 0.5;
	csf.params.cloth_resolution = cloth_resolution;
	csf.params.interations = 500;
	csf.params.rigidness = rigidness ;
	csf.params.time_step = 0.65;

	//step3 ִ���˲�,result�д�����ǵ��������� 
	csf.do_filtering(groundIndex,nongroundIndex);
	groundRows = groundIndex.size();
	nongroundRows = nongroundIndex.size();
	// double *groundPoints = new double[3*groundIndex.size()];
	// double *nongroundPoints = new double[3*nongroundIndex.size()];
	// wl::PointCloud & pc = csf.getPointCloud(); 
	// groundRows = groundIndex.size();
	// nongroundRows = nongroundIndex.size();
	// for(int i=0;i<groundRows;i++)
	// {
	// 	groundPoints[i] = pc[groundIndex[i]].x;
	// 	groundPoints[groundRows+i] = pc[groundIndex[i]].z;
	// 	groundPoints[groundRows*2+i] = -pc[groundIndex[i]].y;
	// }

	// for(int i=0;i<nongroundRows;i++)
	// {
	// 	nongroundPoints[i] = pc[nongroundIndex[i]].x;
	// 	nongroundPoints[nongroundRows+i] = pc[nongroundIndex[i]].z;
	// 	nongroundPoints[nongroundRows*2+i] = -pc[nongroundIndex[i]].y;
	// }


	//csf.savePoints(groundIndex);
	//mexPrintf("OK, Done!\n");
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	double *points = mxGetPr(prhs[0]);
	double resolution = mxGetScalar(prhs[3]);
	bool isSmooth =  mxIsLogicalScalarTrue(prhs[2]);
	int rigidness = (int)mxGetScalar(prhs[1]);

	int rows = mxGetM(prhs[0]);
	std::vector<int> groundIndex,nongroundIndex;
	int groundRows,nongroundRows;
	csf_filtering(points,rigidness,isSmooth,resolution,rows,groundIndex, nongroundIndex,groundRows,nongroundRows);
	plhs[0] = mxCreateNumericMatrix(groundRows,1, mxINT32_CLASS, mxREAL);
	plhs[1] = mxCreateNumericMatrix(nongroundRows,1, mxINT32_CLASS, mxREAL);

	int* outputgroundMatrix = (int *)mxGetData(plhs[0]);
	int* outputnongroundMatrix = (int *)mxGetData(plhs[1]); 
	for(int i=0;i<groundIndex.size();i++)
		outputgroundMatrix[i] = groundIndex[i]+1;
	for(int i=0;i<nongroundIndex.size();i++)
		outputnongroundMatrix[i] = nongroundIndex[i]+1;

    // Read in the data
    // for (int col=0; col < 3; col++) {
    //     for (int row=0; row < groundRows; row++) {
    //         outputgroundMatrix[row + col*groundRows] = outputBuff[col][row];
    //     }
    // }

}


