#include <iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (0==n)
		{
			return 0;
		}
		int *change = A+1;
		for (int i = 1; i<n; ++i)
		{
			if (A[i]!=A[i-1])
			{
				if (change!=(A+i))
				{
					*change = A[i];
				}
				change++;
			}
		}
		return change-A;
	}
};

int main()
{
	Solution solution;
	int A[] = {1,1,2,2,2,3,3,4,5,6,6,6,7,7,8};
	int n = sizeof(A)/sizeof(int);
// 	int m = solution.removeDuplicates(A, n);
	int m = solution.removeDuplicates(NULL, 0);
	for (int i = 0; i<m; ++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}