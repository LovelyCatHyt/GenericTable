#pragma once
#include "GenericPair.h"

namespace GenericTable
{
	//储存若干元素的组合
	class PairGroup
	{
		//指向一个IGenericPair指针数组的指针
		IGenericPair **pairs;
		//元素个数
		unsigned int count;
	public:
		//需输入一个数组作为初始化的条件
		PairGroup(IGenericPair** pairs, unsigned int count);
		template<typename T>
		T& GetPair(string lable);
	};
	template<typename T>
	T& GenericTable::PairGroup::GetPair(string lable)
	{
		for (int i = 0; i < count; i++)
		{
			if (pairs[i]->GetLable() == lable)
			{
				return ((GenericPair<T>*)pairs[i])->GetValueRef();
			}
		}
	}
}