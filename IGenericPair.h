#pragma once
#include <string>
#include <utility>

using std::string;
namespace GenericTable
{
	//����ֵ�Խӿ�
	class IGenericPair
	{
	public:
		virtual string GetLable()const = 0;
		virtual IGenericPair* CopyNew() = 0;
		//virtual IGenericPair operator=(const IGenericPair& src) = 0;
		virtual bool operator<(const IGenericPair& other)const = 0;
		virtual bool operator>(const IGenericPair& other)const = 0;
		virtual bool operator==(const IGenericPair& other)const = 0;
	};
}