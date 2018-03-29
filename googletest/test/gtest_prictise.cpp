#include "gtest/gtest.h"
#include <stack>

using namespace std;

class Solution {
public:
	//int evalRPN(vector<string>& tokens)
	//{
	//	string s = tokens.back(); tokens.pop_back();
	//	if (s != "+" && s != "-" && s != "*" && s != "/") return stoi(s);

	//	int r2 = evalRPN(tokens), r1 = evalRPN(tokens);

	//	if (s == "+") return r1 + r2;
	//	if (s == "-") return r1 - r2;
	//	if (s == "*") return r1 * r2;
	//	if (s == "/") return r1 / r2;
	//}
	int evalRPN(vector<string>& tokens) {
		dvalue = 0;
		int nVecSize = tokens.size();
		if (!nVecSize && IsOpertor(tokens[0]))
		{
			return -999999;
		}
		for (int i = 0; i < nVecSize; i++)
		{
			string tmp = tokens[i];
			if (!IsOpertor(tmp))
			{
				strStack.push(tmp);
			}
			else
			{
				second = atoi(strStack.top().c_str());
				strStack.pop();
				first = atoi(strStack.top().c_str());
				strStack.pop();
				dvalue = GetValue(first, second, tmp);
				
				char buf[16] = { 0 };
				sprintf(buf,"%d", dvalue);
				string svalue(buf);
				strStack.push(svalue);
			}
		}

		return dvalue;
	}
private:
	string GetHigher(string left, string right)
	{
		if (left == "*" || left == "/")
			return left;
		else
			return right;
	}
	bool IsOpertor(string str)
	{
		if (str == "+" || str == "-" || str == "*" || str == "/")
		{
			return true;
		}
		return false;
	}
	double GetValue(double first, double second, string oper)
	{
		if (oper == "+")
			return first + second;
		else if (oper == "-")
			return first - second;
		else if (oper == "*")
			return first * second;
		else if (oper == "/")
			return first / second;
	}
	stack<string> strStack;
	int first;
	int second;
	int dvalue;
};

//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

TEST(CPrictise, Reverse_Polish_Notation)
{
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");

	Solution su;

	cout<<"value is :"<<su.evalRPN(tokens)<<endl;
	tokens.clear();
	tokens.push_back("4");
	tokens.push_back("13");
	tokens.push_back("5");
	tokens.push_back("/");
	tokens.push_back("+");
	cout << "value is :" << su.evalRPN(tokens) << endl;
}
