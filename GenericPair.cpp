#pragma once
#include "GenericPair.h"

namespace GenericTable
{
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
		return value > ((GenericPair<T>*)& other)->value;
	}

	template<typename T>
	bool GenericPair<T>::operator==(const IGenericPair& other) const
	{
		return value == ((GenericPair<T>*)& other)->value;
	}
}