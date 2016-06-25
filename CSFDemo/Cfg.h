#ifndef _CFG_H_
#define _CFG_H_
#include <iostream>  
#include <string>  
#include <fstream> 
using namespace std;

class Cfg
{
public:
	bool readConfigFile(const char * cfgfilepath, const string & key, string & value)
	{
		fstream cfgFile;
		cfgFile.open(cfgfilepath);//���ļ�      
		if (!cfgFile.is_open())
		{
			cout << "can not open cfg file!" << endl;
			return false;
		}
		char tmp[1000];
		while (!cfgFile.eof())//ѭ����ȡÿһ��  
		{
			cfgFile.getline(tmp, 1000);//ÿ�ж�ȡǰ1000���ַ���1000��Ӧ���㹻��  
			string line(tmp);
			size_t pos = line.find('=');//�ҵ�ÿ�еġ�=����λ�ã�֮ǰ��key֮����value  
			if (pos == string::npos) return false;
			string tmpKey = line.substr(0, pos);//ȡ=��֮ǰ  
			if (key == tmpKey)
			{
				value = line.substr(pos + 1);//ȡ=��֮��  
				return true;
			}
		}
		return false;
	}
};


#endif