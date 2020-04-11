#include <algorithm>
#include "GenTable.h"

namespace GenericTable
{
	GenTable::GenTable(const PairGroup& sample):rows(0)
	{
		rows.push_back(sample);
	}

	PairGroup& GenTable::operator[](unsigned int index)
	{
		return rows[index + 1];
	}

	PairGroup GenTable::GetAverages()
	{
		if (rows.size() > 1)
		{
			PairGroup temp(rows[1]);
			//注意跳过第一个
			for (auto row = rows.begin() + 2; row != rows.end(); row++)
			{
				temp = temp + *row;
			}
			temp = temp / (rows.size() - 1);
			return temp;
		}
		else
		{
			return PairGroup();
		}
	}

	PairGroup GenTable::GetMaxs()
	{
		if (rows.size() > 1)
		{
			PairGroup temp(rows[1]);
			//注意跳过第一个
			for (auto row = rows.begin() + 2; row != rows.end(); row++)
			{
				temp = temp.GetGreater(*row);
			}
			return temp;
		}
		else
		{
			return PairGroup();
		}
	}

	PairGroup GenTable::GetMins()
	{
		if (rows.size() > 1)
		{
			PairGroup temp(rows[1]);
			//注意跳过第一个
			for (auto row = rows.begin() + 2; row != rows.end(); row++)
			{
				temp = temp.GetLess(*row);
			}
			return temp;
		}
		else
		{
			return PairGroup();
		}
	}

	void GenTable::Sort(const string& lable, bool lessToGreat)
	{
		//std::cout << "Before sort()\n";
		if (lessToGreat)
			std::sort(rows.begin() + 1, rows.end(), [&](const PairGroup& left, const PairGroup& right) {return left.Less(lable, right); });
		else
			std::sort(rows.begin() + 1, rows.end(), [&](const PairGroup& left, const PairGroup& right) {return !left.Less(lable, right); });
		//std::cout << "After sort()\n";
	}

	void GenTable::Extend(unsigned int count)
	{
		for (unsigned int i = 0; i < count; i++) rows.push_back(rows[0]);
	}
}
