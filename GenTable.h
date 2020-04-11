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
		//按照某个标签进行排序; 需保证传入的标签必须是初始化时存在的标签, 否则可能会发生未知错误; 可以选择从大到小, 也可以选择从小到大
		void Sort(const string& lable, bool lessToGreat = true);
		//获取一系列平均值;
		PairGroup GetAverages();
		//获取一系列最大值;
		PairGroup GetMaxs();
		//获取一系列最小值;
		PairGroup GetMins();
		//复制若干行
		void Extend(unsigned int count = 1);
	};
}