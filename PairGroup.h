#pragma once
#include "GenericPair.h"

namespace GenericTable
{
	//��������Ԫ�ص����
	class PairGroup
	{
		//ָ��һ��IGenericPairָ�������ָ��
		IGenericPair **pairs;
		//Ԫ�ظ���
		unsigned int count;
	public:
		PairGroup();
		PairGroup(const PairGroup& src);
		PairGroup(PairGroup&& src) noexcept;
		~PairGroup();
		PairGroup& operator=(PairGroup&& right) noexcept;
		//������һ��������Ϊ��ʼ��������
		PairGroup(IGenericPair** pairs, unsigned int count);
		template<typename T>
		T& GetPair(string lable) const;
		template<typename T>
		bool Less(const string& lable, const PairGroup& right) const;
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
		//Σ�ղ���: ��㷵�ص�ʲô����(���޸��÷���)
		return ((GenericPair<T>*)pairs[0])->GetValueRef();
	}
	template<typename T>
	bool PairGroup::Less(const string& lable, const PairGroup& right) const
	{
		return GetPair<T>(lable) > right.GetPair<T>(lable);
	}
}