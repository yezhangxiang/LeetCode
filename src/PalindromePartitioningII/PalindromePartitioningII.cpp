/*
	Given a string s, partition s such that every substring of the partition is a palindrome.

	Return the minimum cuts needed for a palindrome partitioning of s.

	For example, given s = "aab",
	Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		if(s.empty()) return 0;
		int n = s.length();
		vector<vector<bool>> pal(n,vector<bool>(n,false));
		vector<int> dp(n);
		for (int i = 0; i < n;++i)
		{
			dp[i] = i>1 ? dp[i-1]+1 : i;
			pal[i][i] = true;
			for (int j = 0; j < i; j++)
			{
				if(s[i]==s[j] && (i-j<2 || pal[j+1][i-1]))
				{
					pal[j][i]=true;
					if (0 == j)
					{
						dp[i] = 0;
					}
					else if (dp[j-1]+1 < dp[i])
					{
						dp[i] = dp[j-1]+1;
					}
				}
			}
		}
		return dp[n-1];
	}

	int minCut_2(string s)
	{
		vector<int> dp;
		for (unsigned int i = 1; i <= s.length();++i)
		{
			if (is_palindrome(s.substr(0, i)))
			{
				dp.push_back(0);
				continue;
			}
			else
			{
				dp.push_back(i-1);
			}

			for (unsigned int j = 1; j < i; j++)
			{
				string current_substr = s.substr(j, i-j);
				if (is_palindrome(current_substr))
				{
					if (dp[i-1] > dp[j-1]+1)
					{
						dp[i-1] = dp[j-1]+1;
					} 
				}
			}
		}
		return dp[s.length()-1];
	}
    int minCut_1(string s) {
		queue<node> node_queue;
		unsigned int current = 0;
		node first_node = {0, 0, 0};
		node_queue.push(first_node);
		while(node_queue.size())
		{
			node current_check = node_queue.front();
			node_queue.pop();
			string current_substr = s.substr(current_check.curret_position, current_check.sub);
			if (is_palindrome(current_substr))
			{
				unsigned int new_current = current_check.curret_position+current_check.sub;
				if (new_current == s.length())
				{
					return current_check.layer;
				}
				else
				{
					for (unsigned int i = s.length()-new_current; i >= 1; --i)
					{
						node sub_node = {new_current, i, current_check.layer+1};
						node_queue.push(sub_node);
					}
				}
			}
		}
		return -1;
    }

private:
	struct node
	{
		unsigned int curret_position;
		unsigned int sub;
		int layer;
	};
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
};

int main()
{
	Solution a;
// 	int min_cut = a.minCut("aabaa");
// 	int min_cut = a.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi");
// 	int min_cut = a.minCut("fifgbeajcacehiicccfe");
	int min_cut = a.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	cout << min_cut;
	system("pause");
	return 1;
}
