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

	void GenTable::Extend(unsigned int count)
	{
		for (unsigned int i = 0; i < count; i++) rows.push_back(rows[0]);
	}
}
