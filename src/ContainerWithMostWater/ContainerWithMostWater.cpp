#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
		int i = 0, j = height.size()-1, area = 0;
		while (j > i)
		{
			int h, length = j - i;
			if (height[i] < height[j])
			{
				h = height[i];
				i++;
			}
			else
			{
				h = height[j];
				j--;
			}
			int tmpArea = h * length;
			if (tmpArea > area)
			{
				area = tmpArea;
			}
		}
		return area;
	}
    int maxArea2(vector<int>& height) {
		int area = 0;
        for (int i = 0; i < height.size(); ++i)
        {
			int leftLength=0, rightLenth = 0;
			for (int j = 0; j < i; ++j)
			{
				if (height[j] >= height[i])
				{
					leftLength = i-j;
					break;
				}
			}
			for (int j = height.size()-1; j > i; --j)
			{
				if (height[j] >= height[i])
				{
					rightLenth = j-i;
					break;
				}
			}
			int length = leftLength > rightLenth ?leftLength : rightLenth;
			if (length * height[i] >area)
			{
				area = length *height[i];
			}
        }
		return area;
    }
};

int main()
{
	Solution solution;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> height(a, a+8);
	cout << solution.maxArea2(height) << endl;
}