#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		for (auto it = digits.rbegin(); it!=digits.rend(); ++it)
		{
			if (9!=*it)
			{
				(*it)++;
				return digits;
			}
			*it = 0;
		}
		digits[0] = 1;
		digits.push_back(0);
		return digits;
	}
};

int main()
{
	Solution solution;
	vector<int> digits;
	digits.push_back(9);
	digits.push_back(9);
	digits.push_back(9);
	solution.plusOne(digits);
	for (int i = 0; i< digits.size(); ++i)
	{
		cout << digits[i];
	}
	cout << endl;
	getchar();
}