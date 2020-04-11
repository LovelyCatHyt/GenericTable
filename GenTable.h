#pragma once
#include <iostream> //Debug
#include <vector>
#include <algorithm>
#include "PairGroup.h"

using std::vector;

namespace GenericTable 
{
	//GenericTable:���б�, д�������Ϊ�˺������ռ�����
	class GenTable
	{
	protected:
		//����ֵ���������, �±�Ϊ0��Ԫ��Ϊ����Ԫ��
		vector<PairGroup> rows;
	public:
		//����һ��PairGroup���г�ʼ��
		GenTable(const PairGroup& sample);
		PairGroup& operator[](unsigned int index);
		//����ĳ����ǩ��������; �豣֤����ı�ǩ�����ǳ�ʼ��ʱ���ڵı�ǩ, ������ܻᷢ��δ֪����; ����ѡ��Ӵ�С, Ҳ����ѡ���С����
		void Sort(const string& lable, bool lessToGreat = true);
		//��ȡһϵ��ƽ��ֵ;
		PairGroup GetAverages();
		//��ȡһϵ�����ֵ;
		PairGroup GetMaxs();
		//��ȡһϵ����Сֵ;
		PairGroup GetMins();
		//����������
		void Extend(unsigned int count = 1);
	};
}