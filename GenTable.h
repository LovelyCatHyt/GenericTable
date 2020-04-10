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
		//����ĳ����ǩ��������; �豣֤����ı�ǩ�����ǳ�ʼ��ʱ���ڵı�ǩ, ������ܻᷢ��δ֪����
		template<typename T>
		void Sort(const string& lable);
		//����������
		void Extend(unsigned int count = 1);
	};
	template<typename T>
	void GenTable::Sort(const string& lable)
	{
		//std::cout << "Before sort()\n";
		std::sort(rows.begin() + 1, rows.end(), [&](const PairGroup& left, const PairGroup& right) {return left.Less<T>(lable, right); });
		//std::cout << "After sort()\n";
	}
}