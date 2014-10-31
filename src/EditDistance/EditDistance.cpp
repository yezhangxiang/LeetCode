

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();
		vector<vector<int>> distance(n+1, vector<int>(m+1, 0));
		for (int i = 0; i <= n; ++i)
		{
			distance[i][0] = i;
		}
		for (int j = 0; j <= m; ++j)
		{
			distance[0][j] = j;
		}
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{

				distance[i][j] = min3(distance[i-1][j]+1, distance[i][j-1]+1, word1[i-1] == word2[j-1] ? distance[i-1][j-1] : distance[i-1][j-1]+1);
			}
		}
		return distance[n][m];
	}

	int minDistance_wrong(string word1, string word2) {
		string long_str, short_str;
		if (word2.size()>word1.size())
		{
			long_str = word2;
			short_str = word1;
		} 
		else
		{
			long_str = word1;
			short_str = word2;
		}
		int long_size = long_str.size();
		int short_size = short_str.size();
		int min_distance = long_size;
		for (size_t i = 0; i <= long_size-short_size; ++i)
		{
			string sub_str = long_str.substr(i, short_size);
			int current_distance = 0;
			for (int i = 0; i < short_size; ++i)
			{
				if (sub_str[i]!=short_str[i])
				{
					current_distance++;
				}
			}
			if (current_distance < min_distance)
			{
				min_distance = current_distance;
			}
			if (min_distance == 0)
			{
				return long_size-short_size;
			}
		}
		return min_distance+long_size-short_size;
	}

private:
	int min3(int a, int b, int c)
	{
		int temp = a < b ? a : b;
		return temp < c ? temp : c;
	}
};

int main()
{
	Solution solution;
	cout << solution.minDistance("intention", "execution");
	getchar();
}