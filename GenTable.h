#pragma once
#include <iostream> //Debug
#include <vector>
#include <algorithm>
#include "PairGroup.h"

using std::vector;

namespace GenericTable 
{
	//GenericTable:泛列表, 写这个名是为了和命名空间区分
	class GenTable
	{
	protected:
		//泛键值对组的数组, 下标为0的元素为保留元素
		vector<PairGroup> rows;
	public:
		//复制一个PairGroup进行初始化
		GenTable(const PairGroup& sample);
		PairGroup& operator[](unsigned int index);
		//按照某个标签进行排序; 需保证传入的标签必须是初始化时存在的标签, 否则可能会发生未知错误
		template<typename T>
		void Sort(const string& lable);
		//复制若干行
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