#pragma once
# include <string>

class VerificationStrategy{
public:
	virtual std::string verify(std::string mes) = 0;
};

using namespace std;
class PrefixStrategy : public VerificationStrategy
{
	public:
	string verify(string mes)
	{
		string output = "";
		for (int i = 0 ; i < 3 ; i ++)
		{
			output += mes[i];
		}
		return output;
	}
};

class IntervalStrategy : public VerificationStrategy
{
	public:
	string verify(string mes)
	{
		string output = "";
		for (int i = 0 ; i < mes.length() ; i ++)
		{
			if (i%2 == 0)
			{
				output += mes[i];
			}
		}
		return output;
	}
};