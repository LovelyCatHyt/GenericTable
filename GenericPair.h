#pragma once
#include "IGenericPair.h"
#include <string>

using std::string;

namespace GenericTable
{
	//通用的键值对
	template<typename T>
	class GenericPair : public IGenericPair
	{
	protected:
		string lable;
		T value;
	public:
		GenericPair(string lable, T initValue);
		//获取标签名
		string GetLable()const;
		//获取储存的值
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