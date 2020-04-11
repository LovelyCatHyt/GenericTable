#include <iostream> //Debug
#include "PairGroup.h"

namespace GenericTable 
{
	IGenericPair* PairGroup::GetIPair(const string lable) const
	{
		for (int i = 0; i < count; i++)
		{
			if (lable == pairs[i]->GetLable())
			{
				return pairs[i];
			}
		}
		return nullptr;
	}
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
		for (unsigned int i = 0; i < count; i++)
		{
			delete pairs[i];//如果pairs是null, 这里就不可访问然后抛异常了.
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
	PairGroup PairGroup::operator+(const PairGroup& other) const
	{
		PairGroup temp(*this);
		int column = 0;
		while (column < count || column < other.count)
		{
			if (column >= count)
			{
				temp.pairs[column] = other.pairs[column]->CopyNew();
			}else if (column >= other.count)
			{
				temp.pairs[column] = pairs[column]->CopyNew();
			}else
			{
				temp.pairs[column] = *pairs[column] + *other.pairs[column];
			}
			
			column++;
		}
		return temp;
	}
	PairGroup PairGroup::operator/(const int& divider) const
	{
		PairGroup temp(*this);
		for (int i = 0; i < count; i++)
		{
			temp.pairs[i] = *temp.pairs[i] / divider;
		}
		return temp;
	}
	bool PairGroup::Less(const string& lable, const PairGroup& right) const
	{
		//Debug
		/*std::cout << (GetPair<float>("Another")) << '<' << (right.GetPair<float>("Another")) << ": " << (GetIPair(lable) < right.GetIPair(lable));
		std::cout << "  Correct: " << ((GetPair<float>("Another")) < (right.GetPair<float>("Another"))) << '\n';*/
		return *GetIPair(lable) < *right.GetIPair(lable);
	}
	PairGroup PairGroup::GetLess(const PairGroup& another) const
	{
		PairGroup temp(*this);
		int i = 0;
		while (i < count)
		{
			temp.pairs[i] = *pairs[i] < *another.pairs[i] ? pairs[i]->CopyNew() : another.pairs[i]->CopyNew();
			i++;
		}
		return std::move(temp);
	}
	PairGroup PairGroup::GetGreater(const PairGroup& another) const
	{
		PairGroup temp(*this);
		int i = 0;
		while (i < count)
		{
			temp.pairs[i] = *pairs[i] < *another.pairs[i] ? another.pairs[i]->CopyNew() : pairs[i]->CopyNew();
			i++;
		}
		return std::move(temp);
	}
}