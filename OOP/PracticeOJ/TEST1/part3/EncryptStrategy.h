#pragma once
# include <string>

class EncryptStrategy{
public:
	virtual std::string encode(std::string mes) = 0;
};

using namespace std;
class InsertStrategy : public EncryptStrategy
{
	string encode(string mes)
	{
		string output = "";
		for (char x : mes)
		{
			output += x;
			output += '#';
		}
		return output;
	}
};

class InvertStrategy : public EncryptStrategy
{
	string encode(string mes)
	{
		string output = "";
		for (int i = mes.length()-1 ; i >=0 ; i--)
		{
			output += mes[i];
		}
		return output;
	}
};

