#pragma once
#include <random>
#ifdef EXPORT
#define EXORIM _declspec(dllexport)
#else
#define EXORIM _declspec(dllimport)
#endif
#define pi 3.141592653


//返回指定范围内的随机浮点数
double rnd(double dbLow, double dbUpper)
{
	double dbTemp = (double)rand() / ((double)RAND_MAX);
	return dbLow + dbTemp*(dbUpper - dbLow);
}
double func(double x)//目标函数
{
	return 7 * sin(6 * x) + 6 * cos(5 * x);
}


class EXORIM CAnnealingAlgorithm
{
public:
	CAnnealingAlgorithm();
	virtual ~CAnnealingAlgorithm();

public:
	void Generate();

protected:

	int num = 80000; //迭代次数
	double k = 0.1;    //常数
	double m_drate = 0.9; //用于控制降温的快慢
	double m_dtemperature = 20000; //系统的温度，系统初始应该要处于一个高温的状态
	double m_dtemperaturemin = 0.2;//温度的下限，若温度T达到T_min，则停止搜索
	double m_best;
};
