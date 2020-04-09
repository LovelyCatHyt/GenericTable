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
		//������һ��������Ϊ��ʼ��������
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