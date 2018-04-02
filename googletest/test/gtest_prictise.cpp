#include "gtest/gtest.h"
#include <stack>

using namespace std;

class Reverse_Polish_Notation {
public:
	int evalRPN(vector<string>& tokens)
	{
		string oper = tokens.back();
		tokens.pop_back();
		if (oper != "+" && oper != "-" && oper != "*" && oper != "/")
		{
			return atoi(oper.c_str());
		}
		int second = evalRPN(tokens);
		int first = evalRPN(tokens);
		if (oper == "+") return first + second;
		if (oper == "-") return first - second;
		if (oper == "*") return first * second;
		if (oper == "/") return first / second;
		return 0;
	}
};

//["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

TEST(Leetcode, Reverse_Polish_Notation)
{
	vector<string> tokens;
	tokens.push_back("3");
	tokens.push_back("-4");
	tokens.push_back("+");

	Reverse_Polish_Notation su;
	cout << "value is :" << su.evalRPN(tokens) << endl;
}

class Longest_Valid_Parentheses {
public:
	int longestValidParentheses1(string s)
	{
		int nlen = s.length();
		int max = 0;
		int ntemp = 0;;
		stack<int> intStack;
		intStack.push(-1);
		for (int i = 0; i < nlen; i++)
		{
			if (s[i] == '(')
				intStack.push(i);
			else
			{
	
				intStack.pop();
				if (intStack.empty())
				{
					intStack.push(i);
				}
				else
				{
					ntemp = intStack.top();
					ntemp = i - ntemp;
					max = max > ntemp ? max : ntemp;
				}
			}
		}
		return max;
	}
	int longestValidParentheses2(string s)
	{
		int nleft = 0;
		int nright = 0;
		int max = 0;
		int nlen = s.length();
		for (int i = 0; i < nlen; i++)
		{
			if (s[i] == '(')
				nleft++;
			else
				nright++;
		
			if (nleft == nright)
				max = max > nleft * 2 ? max : nleft * 2;
			else if(nright >= nleft)
				nright = nleft = 0;
		}
		nright = nleft = 0;
		for (int i = nlen - 1; i >= 0; i--)
		{
			if (s[i] == ')')
				nright++;
			else
				nleft++;
		
			if (nleft == nright)
				max = max > nleft * 2 ? max : nleft * 2;
			else if(nleft >= nright)
				nleft = nright = 0;
		}
		return max;
	}
};

TEST(Leetcode, Longest_Valid_Parentheses)
{
	Longest_Valid_Parentheses lvp;
	cout << lvp.longestValidParentheses1(")()())()()(") << endl;
	cout << lvp.longestValidParentheses2(")()())()()(") << endl;

}

class SolutiontwoSum {
public:
	vector<int> twoSum1(vector<int>& nums, int target) {
		map<int, int>MapSum;
		map<int, int>::iterator Mapiter;
		vector<int> VecRes;
		int nSize = nums.size();
		for (size_t i = 0; i < nSize; i++)
		{
			MapSum[nums[i]] = i;
		}

		for (size_t i = 0; i < nSize; i++)
		{
			int ntemp = target - nums[i];
			Mapiter = MapSum.find(ntemp);
			if (Mapiter != MapSum.end() && MapSum[ntemp] != i)
			{
				VecRes.push_back(i);
				VecRes.push_back(MapSum[ntemp]);
				return VecRes;
			}
		}
		return VecRes;
	}
	vector<int> twoSum2(vector<int>& nums, int target) {
		vector<int> VecRes;
		map<int, int>MapNum;
		int nSize = nums.size();
		for (int i = 0; i < nSize; i++)
		{
			int ntemp = target - nums[i];
			if (MapNum.find(ntemp) != MapNum.end() && i != MapNum[ntemp])
			{
				VecRes.push_back(i);
				VecRes.push_back(MapNum[ntemp]);
			}
			MapNum[nums[i]] = i;
		}
		return VecRes;
	}
};

//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return[0, 1].

TEST(Leetcode, twoSum)
{
	int Array[] = { -1, -2, -3, -4, -5 };
	vector<int> VecNum(Array, Array + 5);

	SolutiontwoSum su;
	//vector<int> res = su.twoSum1(VecNum, -8);
	vector<int> res = su.twoSum2(VecNum, -8);
	cout << res[0]<< endl;
	cout << res[1] << endl;
}