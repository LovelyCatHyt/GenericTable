#pragma once
#include "IGenericPair.h"
#include <string>

using std::string;

namespace GenericTable
{
	//ͨ�õļ�ֵ��
	template<typename T>
	class GenericPair : IGenericPair
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
		virtual bool operator<(const IGenericPair& other)const;
		virtual bool operator>(const IGenericPair& other)const;
		virtual bool operator==(const IGenericPair& other)const;
	};
	
}