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
		IGenericPair* GetIPair(const string lable) const;
	public:
		PairGroup();
		PairGroup(const PairGroup& src);
		PairGroup(PairGroup&& src) noexcept;
		~PairGroup();
		PairGroup& operator=(PairGroup&& right) noexcept;
		//需输入一个数组作为初始化的条件
		PairGroup(IGenericPair** pairs, unsigned int count);
		template<typename T>
		T& GetPair(string lable) const;
		bool Less(const string& lable, const PairGroup& right) const;
		//两个组逐项比较, 每项取较小者; 假定两者标签与类型相同
		PairGroup GetLess(const PairGroup& another) const;
		//两个组逐项比较, 每项取较大者; 假定两者标签与类型相同
		PairGroup GetGreater(const PairGroup& another) const;
		//两个不同宽度的组相加, 代码假定两个组具有相同的前N项, 最终会得到一个并集.
		PairGroup operator+(const PairGroup& other) const;
		PairGroup operator/(const int& divider) const;
	};
	template<typename T>
	T& PairGroup::GetPair(string lable) const
	{
		for (unsigned int i = 0; i < count; i++)
		{
			if (pairs[i]->GetLable() == lable)
			{
				return ((GenericPair<T>*)pairs[i])->GetValueRef();
			}
		}
		//危险操作: 随便返回点什么东西(暂无更好方案)
		return ((GenericPair<T>*)pairs[0])->GetValueRef();
	}
}