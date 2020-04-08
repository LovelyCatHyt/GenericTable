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
	T& GenericPair<T>::GetValueRef()
	{
		return value;
	}
	template<typename T>
	bool GenericPair<T>::operator<(const IGenericPair& other) const
	{
		return value < other.value;
	}
	template<typename T>
	bool GenericPair<T>::operator>(const IGenericPair& other) const
	{
		return value > other.value;
	}
	template<typename T>
	bool GenericPair<T>::operator==(const IGenericPair& other) const
	{
		return value == other.value;
	}
}