/*Given an input string, reverse the string word by word.

	For example,
	Given s = "the sky is blue",
	return "blue is sky the".*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;
class Solution {
public:
	void reverseWords(string &s) {
		stack<string> temp;
		bool in_word = false;
		if (s.c_str()[0]!=' ')
		{
			in_word = true;
		}
		auto word_bigen = s.begin();
		auto word_end = s.begin();
		for (auto it = s.begin(); it != s.end(); ++it)
		{
			if (' ' == *it)
			{
				if (in_word)
				{
					word_end = it;
					in_word = false;
					string new_word(word_bigen, word_end);
					temp.push(new_word);
				}
			}
			else
			{
				if (in_word == false)
				{
					word_bigen = it;
					in_word = true;
				}
			}
		}
		if (in_word)
		{
			word_end = s.end();
			in_word = false;
			string new_word(word_bigen, word_end);
			temp.push(new_word);
		}
		s.clear();
		while (temp.size())
		{
			s+=temp.top();
			temp.pop();
			if (temp.size() >= 1)
			{
				s+=" ";
			}
		}
	}
};


int main()
{
	Solution solution;
	string s = "    the     sky is blue     ";
	solution.reverseWords(s);
	cout << s;
}