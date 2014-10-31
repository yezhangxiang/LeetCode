#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0')
		{
			return 0;
		}
		int last = 1, befor_last = 1;
		for (int i = 1; i < s.size(); ++i)
		{
			int current;
			if (s[i] == '0' && (s[i-1] =='0' || (s[i-1] >= '3')))
			{
				return 0;
			}
			else if (s[i] == '0')
			{
				current = befor_last;
			}
			else if (s[i-1] =='0')
			{
				current = last;
			}
			else if ((s[i-1]-'0')*10+s[i]-'0'<=26)
			{
				current = last + befor_last;
			}
			else
			{
				current = last;
			}
			befor_last = last;
			last = current;
		}
		return last;
	}
};

int main()
{
	Solution solution;
	cout << solution.numDecodings("0") << "Expected" << 0 << endl;
	cout << solution.numDecodings("10") << "Expected" << 1 << endl;
	cout << solution.numDecodings("101") << "Expected" << 1 << endl;
	cout << solution.numDecodings("1010") << "Expected" << 1 << endl;
	cout << solution.numDecodings("230") << "Expected" << 0 << endl;
	cout << solution.numDecodings("17") << "Expected" << 2 << endl;
	cout << solution.numDecodings("27") << "Expected" << 1 << endl;
}