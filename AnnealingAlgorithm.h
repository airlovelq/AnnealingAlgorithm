#pragma once
#include <random>
#ifdef EXPORT
#define EXORIM _declspec(dllexport)
#else
#define EXORIM _declspec(dllimport)
#endif
#define pi 3.141592653


//����ָ����Χ�ڵ����������
double rnd(double dbLow, double dbUpper)
{
	double dbTemp = (double)rand() / ((double)RAND_MAX);
	return dbLow + dbTemp*(dbUpper - dbLow);
}
double func(double x)//Ŀ�꺯��
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

	int num = 80000; //��������
	double k = 0.1;    //����
	double m_drate = 0.9; //���ڿ��ƽ��µĿ���
	double m_dtemperature = 20000; //ϵͳ���¶ȣ�ϵͳ��ʼӦ��Ҫ����һ�����µ�״̬
	double m_dtemperaturemin = 0.2;//�¶ȵ����ޣ����¶�T�ﵽT_min����ֹͣ����
	double m_best;
};
