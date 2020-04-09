#pragma once
#include "IGenericPair.h"
#include <string>

using std::string;

namespace GenericTable
{
	//ͨ�õļ�ֵ��
	template<typename T>
	class GenericPair : public IGenericPair
	{
	protected:
		string lable;
		T value;
	public:
		GenericPair(string lable, T initValue);
		//��ȡ��ǩ��
		string GetLable()const;
		//��ȡ�����ֵ
		T& GetValueRef();
		bool IGenericPair::operator<(const IGenericPair& other)const;
		bool IGenericPair::operator>(const IGenericPair& other)const;
		bool IGenericPair::operator==(const IGenericPair& other)const;
	};
	
	template<typename T>
	T& GenericPair<T>::GetValueRef()
	{
		return value;
	}
}