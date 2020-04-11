#include <iostream>
#include "GenTable.h"

using std::string;
using std::cout;
using namespace GenericTable;



int main()
{
	IGenericPair* pairs[] = { new GenericPair<string>("Test","test"), new GenericPair<float>("Another",2.5) };
	PairGroup sampleGroup(pairs, 2);
	GenTable table(sampleGroup);
	table.Extend(5);
	table[0].GetPair<float>("Another") = 0;
	table[1].GetPair<float>("Another") = 3.5;
	table[2].GetPair<float>("Another") = 2;
	table[3].GetPair<float>("Another") = -8;
	table[4].GetPair<float>("Another") = 4;
	table.Sort("Another");
	for (int i = 0; i < 5; i++)
		cout << table[i].GetPair<float>("Another") << '\n';
	PairGroup temp = table.GetMins();
	cout << temp.GetPair<float>("Another") << '\n';
}