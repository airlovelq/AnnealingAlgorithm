// AnnealingAlgorithm.cpp : ���� DLL Ӧ�ó���ĵ���������
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
			//�õ�ǰʱ����ʼ��������ӣ���ֹÿ�����еĽ������ͬ
			
			
			current = func(rnd(0.0, 2 * pi));
			dE = current - m_best;

			if (dE < 0) //����ƶ���õ����Ž⣬�����ǽ����ƶ�
				m_best = current;
			else
			{
				// ����exp( dE/T )��ȡֵ��Χ��(0,1) ��dE/TԽ����exp( dE/T )ҲԽ��
				if (exp(-dE / (m_dtemperature*k)) > rnd(0.0, 1.0))
					m_best = current;
			}
		}
		m_dtemperature *= m_drate;//�����˻� ��0<r<1 ��rԽ�󣬽���Խ����rԽС������Խ��
		printf("��Сֵ�� %f\n", m_best);
	}
	printf("��Сֵ�� %f\n", m_best);
	
}
