#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
	int jump_1(int A[], int n) {
		vector<int> track(n, 0);

		for(int i=1; i<n; i++){
			int min = n;
			for(int j=0; j<i; j++){
				if(track[j] < min && A[j]+j >= i)
					min = track[j];
			}
			track[i] = min+1;
		}
		return track[n-1];
	}
	int jump(int A[], int n) {
        if (1==n)
            return 0;
		queue<int> temp_que;
		int layer = 0;
		temp_que.push(0);
		temp_que.push(-1);
		while (temp_que.size()>1)
		{
			int current = temp_que.front();
			temp_que.pop();
			if (-1 == current)
			{
				layer++;
				temp_que.push(-1);
                continue;
			}
			if (current+A[current] >= n-1)
			{
				return layer+1;
			}
			for (int i = 1; i <= A[current]; ++i)
			{
				temp_que.push(current+i);
			}
		}
		return layer;
	}
};

int main()
{
	Solution solution;
    //int A[]={2,3,1,1,4};
    //int n = 5;
    //int A[]={3,1,2,1,1,1,4};
    //int n = 7;
     int A[] = {1,1,1,1};
     int n = 4;
    //int A[] = {3,2,1,0,4};
    //int n = 5;
    //int A[]={0};
    //int n = 1;
	cout << solution.jump(A, n) << endl;
}
