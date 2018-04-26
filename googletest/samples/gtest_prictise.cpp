#include "gtest/gtest.h"
#include <stack>
#include <limits>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

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



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//	Output : 7 -> 0 -> 8
//	Explanation : 342 + 465 = 807.

class SolutionAdd_Two_Numbers {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *Node1 = l1;
		ListNode *Node2 = l2;
		ListNode *NewNode = new ListNode(0);
		ListNode *TempNode = NewNode;
		bool bflag = false;
		int Data = 0;
		while (Node1 || Node2)
		{
			int Data1 = 0;
			int Data2 = 0;
			if (Node1)
				Data1 = Node1->val;
			if (Node2)
				Data2 = Node2->val;
			Data = Data1 + Data2;
			if (bflag)
				Data++;
			if (Data > 9)
				bflag = true;
			else
				bflag = false;

			TempNode->val = Data % 10;

			TempNode->next = new ListNode(0);

			TempNode = TempNode->next;
			if (Node1)
			{
				Node1 = Node1->next;
			}

			if (Node2)
			{
				Node2 = Node2->next;
			}
		}
		if (bflag)
			TempNode->val = Data;
		return NewNode;
	}
};

TEST(Leetcode, Add_Two_Numbers)
{
	SolutionAdd_Two_Numbers su;
	su.addTwoNumbers(NULL, NULL);
}

class Solution_lengthOfLongestSubstring {
public:
	int lengthOfLongestSubstring1(string s) {
		set<char> setdata;		
		int nlen = s.length();
		int max = 0;
		int i = 0;
		int j = 0;
		// try to extend the range [i, j]
		while(i < nlen && j < nlen)
		{
			if (setdata.find(s[j]) != setdata.end())
			{
				setdata.erase(s[i++]);
			}
			else
			{
				setdata.insert(s[j++]);
				max = max > j - i ? max : j - i;
			}
		}
		return max;
	}
	int lengthOfLongestSubstring2(string s) {
		int nlen = s.length();
		int max = 0;
		map<char, int> mapdata;
		for (int j = 0, i = 0; j < nlen; j++)
		{
			if (mapdata.find(s[j]) != mapdata.end())
			{
				i = MAX(mapdata[s[j]], j);
			}
			mapdata[s[j]] = j + 1;
			max = MAX(max, j - i + 1);
				
		}
		return max;
	}
};

TEST(Leetcode, lengthOfLongestSubstring)
{
	Solution_lengthOfLongestSubstring su;

	EXPECT_EQ(su.lengthOfLongestSubstring1("abcabcbb"), 3);
	EXPECT_EQ(su.lengthOfLongestSubstring1("bbbbb"), 1);
	EXPECT_EQ(su.lengthOfLongestSubstring1("pwwkew"), 3);
	EXPECT_EQ(su.lengthOfLongestSubstring1("aab"), 2);

	EXPECT_EQ(su.lengthOfLongestSubstring2("abcabcbb"), 3);
	EXPECT_EQ(su.lengthOfLongestSubstring2("bbbbb"), 1);
	EXPECT_EQ(su.lengthOfLongestSubstring2("pwwkew"), 3);
	EXPECT_EQ(su.lengthOfLongestSubstring2("aab"), 2);

}

class CTString
{
public:
	CTString():m_pbuf(NULL), m_nLen(0){}
	CTString(char *buf, int len)
	{
		m_nLen = len;
		m_pbuf = new char[len + 1];
		if (m_pbuf)
		{
			memset(m_pbuf, 0, len + 1);
			strcpy(m_pbuf, buf);
		}
	}
	CTString(const CTString& str)
	{
		m_pbuf = new char[str.m_nLen + 1];
		if (m_pbuf)
		{
			memset(m_pbuf, 0, str.m_nLen + 1);
			strcpy(m_pbuf, str.m_pbuf);
		}
	}
	/*
	void operator=(const CTString &str)
	{
		if (&str == this)
		{
			return;
		}
		if (m_pbuf)
		{
			delete[]m_pbuf;
			m_nLen = 0;
		}
		m_pbuf = new char[str.m_nLen + 1];
		if (m_pbuf)
		{
			memset(m_pbuf, 0, str.m_nLen + 1);
			strcpy(m_pbuf, str.m_pbuf);
		}
	}
	*/
	CTString & operator=(const CTString &str)
	{
		if (&str == this)
		{
			return *this;
		}
		if (m_pbuf)
		{
			delete[]m_pbuf;
			m_nLen = 0;
		}
		m_pbuf = new char[str.m_nLen + 1];
		if (m_pbuf)
		{
			memset(m_pbuf, 0, str.m_nLen + 1);
			strcpy(m_pbuf, str.m_pbuf);
		}
		return *this;
	}
private:
	char *m_pbuf;
	int m_nLen;
};

TEST(Leetcode, TestCopy)
{
	CTString a("1111", 4);
	CTString b;
	CTString c;
	a = a;
	//c = b = a;  如果赋值函数返回的不是引用 这种表达式不能使用。
	c = b = a;
	int bb;
}

class Solution_findMedianSortedArrays {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double ret = 0.0f;
		int i = 0;
		int size1 = nums1.size();
		int j = 0;
		int size2 = nums2.size();
		vector<int> VesRes;
		while (i < size1 && j <size2)
		{
			if (nums1[i] <= nums2[j])
			{
				VesRes.push_back(nums1[i++]);
			}
			else
			{
				VesRes.push_back(nums2[j++]);
			}
		}
		while (i < size1)
		{
			VesRes.push_back(nums1[i++]);
		}
		while (j < size2)
		{
			VesRes.push_back(nums2[j++]);
		}
		int nVesSize = VesRes.size();
		if (nVesSize % 2 == 0)
		{
			ret = (VesRes[nVesSize / 2] + VesRes[nVesSize / 2 - 1]) / 2.0f;
		}
		else
		{
			ret = VesRes[nVesSize / 2];
		}
		return ret;
	}
};

TEST(Leetcode, findMedianSortedArrays)
{
	int arr1[] = { 1, 2 };
	int arr2[] = { 3, 4 };
	vector<int> VecArr1(arr1, arr1 + sizeof(arr1) / sizeof(int));
	vector<int> VecArr2(arr2, arr2 + sizeof(arr2) / sizeof(int));

	Solution_findMedianSortedArrays su;
	EXPECT_EQ(su.findMedianSortedArrays(VecArr1, VecArr2), 2.5);
}


class Solution_longestPalindrome {
public:
	string longestPalindrome(string s) {
		int begin = 0;
		int end = 0;
		string maxstr;
		for (int i = 0; i < s.length(); i++)
		{
			int len1 = GetPalindrome(s, i, i);
			int len2 = GetPalindrome(s, i, i + 1);
			if (len1 > len2)
			{
				begin = i - len1 / 2;
				end = i + len1 / 2;
			}
			else
			{
				begin = i - (len2 / 2 - 1);
				end = i + (len2 / 2 );
			}
			if (begin < 0)
				continue;
			string tmpstr = s.substr(begin, end - begin + 1);
			if (maxstr.length() < tmpstr.length())
				maxstr = tmpstr;
		}
		return maxstr;
	}
	int GetPalindrome(string& s, int L, int R)
	{
		int l = L;
		int r = R;
		while (l >= 0 && r < s.length() && s[l] == s[r])
		{
			l--;
			r++;
		}
		return r - l - 1;
	}
};
TEST(Leetcode, longestPalindrome)
{
	Solution_longestPalindrome su;
	cout << su.longestPalindrome("cbbd") << endl;
}


class Solution_Zig {
public:
    string convert(string s, int numRows) {
    	string out;
       string *sZig = new string[numRows];
				int nRow = 0;
				int nIndex = 0;
       for(int i = 0; i < s.length(); i++)
       {
       	
       	sZig[nRow].push_back(s[i]);
       	if(numRows == 1)
       		continue;
       	if(nRow == 0)
       	{
       		nIndex = 1;		
       	}
       	if(nRow == numRows - 1)
       	{
       		nIndex = -1;
       	}
       	nRow += nIndex;    		
       } 
       for(int i = 0; i < numRows; i++)
       {
       		out.append(sZig[i]);
       	
       }
       	delete []sZig;
       return out;
    }
};

TEST(Leetcode, Zig)
{
	Solution_Zig su;
	EXPECT_EQ(su.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
}


class Solution_reverse {
public:
    int reverse(int x) {
        long long nres = 0;
        char c;
        while(x)
        {
        	long long ntemp = nres * 10 + x % 10;
        	x /= 10;
        	nres = ntemp;
        }
  			if(nres < numeric_limits<int>::min() || nres > numeric_limits<int>::max())
  				return 0;
        return nres;
    }
};

TEST(Leetcode, reverse)
{
	Solution_reverse su;
	//EXPECT_EQ(su.reverse(123),321);
	//EXPECT_EQ(su.reverse(-123),-321);
	EXPECT_EQ(su.reverse(120),21);
	EXPECT_EQ(su.reverse(1534236469),0);
}

class Solution_myAtoi {
public:
    int myAtoi(string str) {    	
			int intmax = numeric_limits<int>::max();
			int intmin = numeric_limits<int>::min();
			int nret = 1;
			long long num = 0;
			int firstnum = str.find_first_not_of(' ');
			if(str[firstnum] == '+' || str[firstnum] == '-')
			{
				nret = str[firstnum++] == '+' ? 1 : -1;
			}
			while(firstnum < str.length())
			{
				if(str[firstnum] >= '0' && str[firstnum] <= '9')
				{
						num = num * 10 + (str[firstnum] - '0');
						if(num * nret > intmax) return intmax;
						if(num * nret < intmin) return intmin;
				}	
				firstnum++;
			}
			return num * nret;
    }
};

TEST(Leetcode, myAtoi)
{
	Solution_myAtoi su;
	//EXPECT_EQ(su.myAtoi("42"), 42);
	//EXPECT_EQ(su.myAtoi("    -42"), -42);
	//EXPECT_EQ(su.myAtoi("4193 with words"), 4193);
	//EXPECT_EQ(su.myAtoi("words with 4193"), 4193);
	EXPECT_EQ(su.myAtoi("-91283472332"), -2147483648);
}

class Solution_isPalindrome {
public:
    bool isPalindrome(int x) {
    	char buf[16] = {0};
    	sprintf(buf,"%d", x);
      string str(buf);
      int l = 0;
      int r = str.length()-1;
      while(l <= r)
      {
      	if(str[l++] != str[r--])
      		return false;	
      }
      return true;
    }
};

TEST(Leetcode, isPalindrome)
{
	Solution_isPalindrome su;
	EXPECT_TRUE(su.isPalindrome(121));
	EXPECT_FALSE(su.isPalindrome(-121));
	EXPECT_FALSE(su.isPalindrome(10));
}



class Solution_maxArea {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max = 0;
        while(l < r)
        {
        		int temp = (r - l) * MIN(height[r], height[l]);
        		max = MAX(temp, max);
        		if(height[l] > height[r])
        			r--;
        		else
        			l++;
        }
        return max;
    }
};

TEST(Leetcode, maxArea)
{
	Solution_maxArea su;
	int array[] = {2,3,4,5,18,17,6};
	vector<int> vecArray(array, array + 7);
	EXPECT_EQ(su.maxArea(vecArray), 17);
}
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
class Solution_romanToInt {
public:
    int romanToInt(string s) {
        vector<int> Array ;
        for(int i = 0; i < s.length(); i++)
        {
        	if(s[i] == 'I')
        		Array.push_back(1);
        	if(s[i] == 'V')
        		Array.push_back(5);
        	if(s[i] == 'X')
        		Array.push_back(10);
        	if(s[i] == 'L')
        		Array.push_back(50);
        	if(s[i] == 'C')
        		Array.push_back(100);
        	if(s[i] == 'D')
        		Array.push_back(500);
        	if(s[i] == 'M')
        		Array.push_back(1000);
        }
        int sum = 0;
        for(int i = 0; i < Array.size() - 1; i++)
        {
        	if(Array[i] < Array[i + 1])
        		sum -= Array[i];
        	else
        		sum += Array[i];
        }
        return sum += Array[Array.size() - 1];
    }
};

class Solution_longestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int nVecSize = strs.size();
        if(nVecSize == 0)
        	return "";
        int nIndex = 0;
        bool bflag = false;
        for(int n = 0; n < strs[0].length(); n++)
        {
        	bflag = true;
	        for(int i = 1; i < nVecSize; i++)
	        {
	        	if(strs[i][n] != strs[0][n])
		   			{
	            bflag = false;
		   				break;
		   			}
	        }
          if(bflag)
	   				nIndex++;
          if(!bflag)
            return string(strs[0], 0, nIndex);
	      }
	      return string(strs[0], 0, nIndex);
    }
};
//["flower","flow","flight"]

TEST(Leetcode, longestCommonPrefix)
{
	Solution_longestCommonPrefix su;
	vector<string> vecStr;
	vecStr.push_back("flower");
	vecStr.push_back("flow");
	vecStr.push_back("flight");
	EXPECT_STREQ(su.longestCommonPrefix(vecStr).c_str(), "fl");
}