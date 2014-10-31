#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	bool isNumber(const char *s) {
		bool dot = false;
		bool e = false;
		if (*s=='\0')
		{
			return false;
		}
		while (*s == ' ')
		{
			s++;
		}
		if (*s == '+' || *s == '-')
		{
			s++;
		}
		while (*s != '\0' && *s != ' ')
		{
			if (*s-'0'<10 && *s-'0' >= 0)
			{
				s++;
			}
			else if (*s == '.' && !dot)
			{
				dot = true;
				s++;
			}
			else if (*s == 'e' && !e)
			{
				dot = true;
				e = true;
				s++;
			}
			else
			{
				return false;
			}
		}
		while (*s == ' ')
		{
			s++;
		}
		if (*s == '\0')
		{
			return true;
		}
		return false;
	}
};

int main()
{
	Solution solution;
	vector<string> test;
	test.push_back("0.1");
	test.push_back("e");
	test.push_back(".e");
	test.push_back("0e");
	test.push_back("12e");
	test.push_back("   0.1  ");
	test.push_back("   0.1 12 ");
	test.push_back("+0.1");
	test.push_back("000.2");
	test.push_back("aa");
	test.push_back("");
	test.push_back("2e10");
	test.push_back("2q10");
	test.push_back("2.23e10");
	test.push_back("2.23e1.0121");
	for (int i = 0; i < test.size(); ++i)
	{
		if (solution.isNumber(test[i].c_str()))
		{
			cout << test[i] << "is number!" << endl;
		}
		else
		{
			cout << test[i] << "is not number!" << endl;
		}
	}
}