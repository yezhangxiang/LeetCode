#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		vector<int> way(n+1, 1);
		for (int i = 2; i <= n; ++i)
		{
			way[i] = way[i-1]+way[i-2];
		}
		return way[n];
	}
};

int main()
{
	Solution solution;
	cout << solution.climbStairs(10);
}