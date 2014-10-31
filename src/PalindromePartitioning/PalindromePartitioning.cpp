// 
//  Given a string s, partition s such that every substring of the partition is a palindrome.
// 
// 	Return all possible palindrome partitioning of s.
// 
// 	For example, given s = "aab",
// 	Return
// 
// 	[
// 		["aa","b"],
// 		["a","a","b"]
// 	]

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> all_answer;
		vector<string> answer;
		backtracking(s, 0, all_answer, answer);
		return all_answer;
    }

	void print(vector<vector<string>> all_answer)
	{
		for (auto it = all_answer.begin(); it != all_answer.end(); it++)
		{
			for (auto it2 = it->begin(); it2 != it->end(); it2++)
			{
				cout << *it2 << " ";
			}
			cout << endl;
		}
	}
private:
	bool is_palindrome(string s)
	{
		unsigned int i = 0;
		string::iterator it = s.begin();
		string::reverse_iterator it2 = s.rbegin();
		while (i < s.length()/2 && it != s.end())
		{
			if (*it != *it2)
			{
				return false;
			}
			++i;
			++it;
			++it2;
		}
		return true;
	}
	void backtracking(string s, unsigned int current, vector<vector<string>> &all_answer, vector<string> &answer)
	{
		if (current == s.length())
		{
			all_answer.push_back(answer);
			return;
		}
		else
		{
			for (unsigned int i = 1; i <= s.length()-current; ++i)
			{
				string current_str = s.substr(current, i);
				if (is_palindrome(current_str))
				{
					answer.push_back(current_str);
					backtracking(s, current+i, all_answer, answer);
					answer.pop_back();	//backtracking
				}
			}
		}
	}
};

int main()
{
	Solution a;
    vector<vector<string>> all_answer = a.partition("bbaaababababaabaaa");
	a.print(all_answer);
	system("pause");
	return 1;
}
