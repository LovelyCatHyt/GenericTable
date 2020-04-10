#include <iostream> //Debug
#include "PairGroup.h"

namespace GenericTable 
{
	PairGroup::PairGroup()
	{
		pairs = nullptr;
		count = 0;
	}
	PairGroup::PairGroup(const PairGroup& src)
	{
		count = src.count;
		pairs = new IGenericPair * [count + 1];
		for (unsigned int i = 0; i < count; i++)
		{
			pairs[i] = src.pairs[i]->CopyNew();
		}
	}
	PairGroup::PairGroup(PairGroup&& src) noexcept
	{
		count = src.count;
		pairs = src.pairs;
		src.pairs = nullptr;
	}
	PairGroup::~PairGroup()
	{
		if (pairs == nullptr) return;
		for (int i = 0; i < count; i++)
		{
			delete pairs[i];
		}
		pairs = nullptr;
	}
	PairGroup& PairGroup::operator=(PairGroup&& right) noexcept
	{
		count = right.count;
		pairs = right.pairs;
		right.pairs = nullptr;
		return *this;
	}
	PairGroup::PairGroup(IGenericPair** pairs, unsigned int count) : pairs(pairs),count(count)
	{
		//TODO//Maybe nothing to do?
	}
}