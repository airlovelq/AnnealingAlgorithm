// AnnealingAlgorithm.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "AnnealingAlgorithm.h"
#include <time.h>



CAnnealingAlgorithm::CAnnealingAlgorithm()
{
}


CAnnealingAlgorithm::~CAnnealingAlgorithm()
{
}

void CAnnealingAlgorithm::Generate()
{
	srand((unsigned int)time(0));
	m_best = func(rnd(0.0, 2 * pi));
	double dE, current;
	int i;
	while (m_dtemperature > m_dtemperaturemin)
	{
		srand((unsigned int)time(0));
		for (i = 0; i<num; i++)
		{
			//用当前时间点初始化随机种子，防止每次运行的结果都相同
			
			
			current = func(rnd(0.0, 2 * pi));
			dE = current - m_best;

			if (dE < 0) //表达移动后得到更优解，则总是接受移动
				m_best = current;
			else
			{
				// 函数exp( dE/T )的取值范围是(0,1) ，dE/T越大，则exp( dE/T )也越大
				if (exp(-dE / (m_dtemperature*k)) > rnd(0.0, 1.0))
					m_best = current;
			}
		}
		m_dtemperature *= m_drate;//降温退火 ，0<r<1 。r越大，降温越慢；r越小，降温越快
		printf("最小值是 %f\n", m_best);
	}
	printf("最小值是 %f\n", m_best);
	
}
