#include <iostream>
#include "PairGroup.h"
#include "GenericPair.cpp"

using std::string;
using std::cout;
using namespace GenericTable;

int main()
{
	IGenericPair* pairs[] = { new GenericPair<int>("Test",114514), new GenericPair<float>("Another",2.5) };
	PairGroup newGroup(pairs, 2);
	int& test = newGroup.GetPair<int>("Test");
	cout << test<<'\n';
	test = 2333;
	cout << newGroup.GetPair<int>("Test");
}