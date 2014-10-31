#include <iostream>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
	string minWindow(string S, string T) {
		map<char, int> charNum;
		string minWin;
		size_t lastAll = 0, currentAll = 0;
		for (int i = 0; i < T.length(); ++i)
		{
			charNum[T[i]];
			if (S.find(T[i]) > lastAll)
			{
				lastAll = S.find(T[i]);
			}
			
		}
		for (int i = 0; i <= lastAll; ++i)
		{
			if (charNum.find(S[i])!=charNum.end())
			{
				charNum[S[i]]++;
			}
		}
		for (int i = 0; i < S.length(); ++i)
		{
			if (charNum.find(S[i])!=charNum.end())
			{
				charNum[S[i]]--;
				if (charNum[S[i]] == 0)
				{
					currentAll = S.find(S[i]);
					if (lastAll != string::npos)
					{

					}
				}
			}

		}
		return minWin;
	}
};

int main()
{
	Solution solution;
	string S = "ADOBECODEBANC";
	string T = "ABC";
	cout << solution.minWindow(S, T) << endl;
}