#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	bool isInterleave_queue(string s1, string s2, string s3) {
		int len1 = s1.length(), len2 = s2.length(), len3=s3.length();
		if (len1+len2!=len3)
		{
			return false;
		}
		queue<pair<int, int>> node;
		node.push(pair<int, int>(-1, -1));
		pair<int, int> last_node;
		int count = 0;
		while (!node.empty())
		{
			count++;
			int i = node.front().first;
			int j = node.front().second;
			cout << i << " " << j << endl;
			if (i == len1-1 && j == len2-1)
			{
				cout << "count: " << count <<endl;
				return true;
			}
			node.pop();
			if (i+1 < len1 && i+j+2 < len3 && s1[i+1]==s3[i+j+2])
			{
				node.push(pair<int, int>(i+1, j));
			}
			if (j+1 < len2 && i+j+2 < len3 && s2[j+1]==s3[i+j+2])
			{
				node.push(pair<int, int>(i, j+1));
			}

		}
		cout << "count: " << count <<endl;
		return false;
	}
	bool isInterleave_stack(string s1, string s2, string s3) {
		int len1 = s1.length(), len2 = s2.length(), len3=s3.length();
		if (len1+len2!=len3)
		{
			return false;
		}
		stack<pair<int, int>> node;
		node.push(pair<int, int>(-1, -1));
		pair<int, int> last_node;
		int count = 0;
		while (!node.empty())
		{
			count++;
			int i = node.top().first;
			int j = node.top().second;
			cout << i << " " << j << endl;
			if (i == len1-1 && j == len2-1)
			{
				cout << "count: " << count <<endl;
				return true;
			}
			node.pop();
			if (i+1 < len1 && i+j+2 < len3 && s1[i+1]==s3[i+j+2])
			{
				node.push(pair<int, int>(i+1, j));
			}
			if (j+1 < len2 && i+j+2 < len3 && s2[j+1]==s3[i+j+2])
			{
				node.push(pair<int, int>(i, j+1));
			}

		}
		cout << "count: " << count <<endl;
		return false;
	}

	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.length(), len2 = s2.length(), len3=s3.length();
		if (len1+len2!=len3)
		{
			return false;
		}
		stack<pair<int, int>> node;
		set<pair<int, int>> passed;
		node.push(pair<int, int>(-1, -1));
		pair<int, int> last_node;
		int count = 0;
		while (!node.empty())
		{
			count++;
			int i = node.top().first;
			int j = node.top().second;
			passed.insert(pair<int, int>(i, j));
			if (i == len1-1 && j == len2-1)
			{
				return true;
			}
			node.pop();
			if (i+1 < len1 && i+j+2 < len3 && s1[i+1]==s3[i+j+2] && passed.find(pair<int, int>(i+1, j)) == passed.end())
			{
				node.push(pair<int, int>(i+1, j));
			}
			if (j+1 < len2 && i+j+2 < len3 && s2[j+1]==s3[i+j+2] && passed.find(pair<int, int>(i, j+1)) == passed.end())
			{
				node.push(pair<int, int>(i, j+1));
			}
		}
		return false;
	}
	bool isInterleave_dp(string s1, string s2, string s3) {
		int len1 = s1.length(), len2 = s2.length(), len3=s3.length();
		if (len1+len2!=len3)
		{
			return false;
		}
		vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
		dp[0][0] = true;
		for (int i = -1; i < len1; ++i)
		{
			for (int j = -1;  j < len2; ++j)
			{
				if (dp[i+1][j+1]==true)
				{
					if (i+1 < len1 && i+j+2 < len3 && s1[i+1]==s3[i+j+2])
					{
						dp[i+2][j+1] = true;
					}
					if (j+1 < len2 && i+j+2 < len3 && s2[j+1]==s3[i+j+2])
					{
						dp[i+1][j+2] = true;
					}
				}
			}
		}
		for (int i = -1; i < len1; ++i)
		{
			for (int j = -1;  j < len2; ++j)
			{
				cout << dp[i+1][j+1] << " ";
			}
			cout << endl;
		}
		cout << endl;

		return dp[len1][len2];
	}
	bool isInterleave_res(string s1, string s2, string s3) {
		if ((s1.empty() && s2.empty() && s3.empty()) || \
			(!s1.empty() && !s3.empty() && s3[0] == s1[0] && isInterleave_res(s1.substr(1, s1.length()-1), s2, s3.substr(1, s3.length()-1))) || \
			(!s2.empty() && !s3.empty() && s3[0] == s2[0] && isInterleave_res(s1, s2.substr(1, s2.length()-1), s3.substr(1, s3.length()-1))) )
		{
			return true;
		}
		return false;
	}
};

int main()
{
	Solution solution;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	cout << (solution.isInterleave(s1, s2, s3) ? "pass" : "not pass") << endl;
	cout << (solution.isInterleave_dp(s1, s2, s3) ? "pass" : "not pass") << endl;
	s3 = "aadbbbaccc";
	cout << (solution.isInterleave(s1, s2, s3) ? "pass" : "not pass") << endl;
	cout << (solution.isInterleave_stack(s1, s2, s3) ? "pass" : "not pass") << endl;
	cout << (solution.isInterleave_dp(s1, s2, s3) ? "pass" : "not pass") << endl;
// 	s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
// 	s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
// 	s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";
// 	cout << (solution.isInterleave(s1, s2, s3) ? "pass" : "not pass") << endl;
// // 	cout << (solution.isInterleave_dp(s1, s2, s3) ? "pass" : "not pass") << endl;
// 	s1 = "";
// 	s2 = "";
// 	s3 = "";
// 	cout << (solution.isInterleave(s1, s2, s3) ? "pass" : "not pass") << endl;
// 	s1 = "";
// 	s2 = "";
// 	s3 = "aa";
// 	cout << (solution.isInterleave(s1, s2, s3) ? "pass" : "not pass") << endl;
// 	s1 = "";
// 	s2 = "aa";
// 	s3 = "aa";
// 	cout << (solution.isInterleave(s1, s2, s3) ? "pass" : "not pass") << endl;
}