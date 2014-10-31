#include <iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (0==n)
		{
			return 0;
		}
		int change = 1;
		int duplicate = 0;
		for (int i = 1; i<n; ++i)
		{
			A[i]!=A[i-1] ? duplicate = 0 : duplicate++;
			if (duplicate < 2)
			{
				A[change] = A[i];
				change++;
			}
		}
		return change;
	}
};

int main()
{
	Solution solution;
	int A[] = {1};
	int n = sizeof(A)/sizeof(int);
	int m = solution.removeDuplicates(A, n);
// 	int m = solution.removeDuplicates(NULL, 0);
	for (int i = 0; i<m; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}