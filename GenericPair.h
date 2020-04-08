#pragma once
#include "IGenericPair.h"
#include <string>

using std::string;

namespace GenericTable
{
	//通用的键值对
	template<typename T>
	class GenericPair : IGenericPair
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
		virtual bool operator<(const IGenericPair& other)const;
		virtual bool operator>(const IGenericPair& other)const;
		virtual bool operator==(const IGenericPair& other)const;
	};
	
}