#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		map<int, int> num2index;
		int n = numbers.size();
		vector<int> indexs(2, 0);
		for (int i = 0; i < n; ++i)
		{
			int current = numbers[i];
			if (num2index.find(current<<1)==num2index.end())
			{
				num2index[current<<1] = i+1;
			}
			else
			{
				num2index[(current<<1)+1] = i+1;
			}
		}
		for (auto it = num2index.begin(); it != num2index.end(); ++it)
		{
			int current = (it->first)>>1;
			int left = target - current;
			if (left!=current && num2index.find(left<<1) != num2index.end())
			{
				indexs[0] = it->second;
				indexs[1] = num2index[left<<1];
				break;
			}
			if (left == current && num2index.find(left<<1) != num2index.end())
			{
				if (it->second != num2index[left<<1])
				{
					indexs[0] = it->second;
					indexs[1] = num2index[left<<1];
				}
				else
				{
					indexs[0] = it->second;
					indexs[1] = num2index[(left<<1)+1];
				}
				break;
			}
		}
		if (indexs[1]<indexs[0])
		{
			int tmp = indexs[0];
			indexs[0] = indexs[1];
			indexs[1] = tmp;
		}

		return indexs;
	}
};

int main()
{
	int tmp[] = {-1, 4, -1, 0};
	int target = -2;
	vector<int> numbers (tmp, tmp + sizeof(tmp) / sizeof(int) );
	Solution solution;
	vector<int> sum = solution.twoSum(numbers, target);
	cout << sum[0] << " " << sum[1] << endl;
}
