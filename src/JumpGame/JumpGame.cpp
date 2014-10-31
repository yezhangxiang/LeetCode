#include <iostream>
using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		int can_touch = n-1;
		for (int i = n-2; i >= 0; --i)
		{
			if (A[i]+i>=can_touch)
			{
				can_touch = i;
			}
		}
		return 0==can_touch;
	}
};

int main()
{
	Solution solution;
	int A[]={3,2,1,0,4};
	int n = 5;
	if (solution.canJump(A, n))
	{
		cout << "canJump" << endl;
	}
	else
	{
		cout << "can not" << endl;
	}
}