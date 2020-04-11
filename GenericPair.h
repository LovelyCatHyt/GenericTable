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
		IGenericPair* CopyNew();
		//virtual IGenericPair operator=(const IGenericPair& src);
		bool IGenericPair::operator<(const IGenericPair& other)const;
		bool IGenericPair::operator>(const IGenericPair& other)const;
		bool IGenericPair::operator==(const IGenericPair& other)const;
		IGenericPair* operator+(const IGenericPair& other)const;
		//��ʵ�������Ӧ��������ʱ��������, ��Ҫдһ���ػ�ģ��ר�Ŵ�������.
		IGenericPair* operator/(const int& divider)const;
	};
	
	template<typename T>
	T& GenericPair<T>::GetValueRef()
	{
		return value;
	}

	template<typename T>
	inline IGenericPair* GenericPair<T>::CopyNew()
	{
		return new GenericPair<T>(lable, value);
	}

	template<typename T>
	inline IGenericPair* GenericPair<T>::operator+(const IGenericPair& other) const
	{
		return new GenericPair<T>(lable, value + ((GenericPair<T>*) & other)->value);
	}

	template<>
	inline IGenericPair* GenericTable::GenericPair<string>::operator/(const int& divider) const
	{
		return new GenericPair<string>(lable, value);
	}

	template<typename T>
	inline IGenericPair* GenericPair<T>::operator/(const int& divider) const
	{
		return new GenericPair<T>(lable, value / divider);
	}

	//template<typename T>
	//inline IGenericPair GenericPair<T>::operator=(const IGenericPair& src)
	//{
	//	lable = src.GetLable();
	//	value = ((GenericPair<T>*) & src)->value;
	//	return *this;
	//}

	template<typename T>
	GenericPair<T>::GenericPair(string lable, T initValue) : lable(lable), value(initValue)
	{
	}
	template<typename T>
	string GenericPair<T>::GetLable()const
	{
		return lable;
	}

	template<typename T>
	bool GenericPair<T>::operator<(const IGenericPair& other) const
	{
		return value < ((GenericPair<T>*)& other)->value;
	}

	template<typename T>
	bool GenericPair<T>::operator>(const IGenericPair& other) const
	{
		return value > ((GenericPair<T>*) & other)->value;
	}

	template<typename T>
	bool GenericPair<T>::operator==(const IGenericPair& other) const
	{
		return value == ((GenericPair<T>*) & other)->value;
	}
}