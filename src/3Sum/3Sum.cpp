#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vec(vector<vector<int> > answers)
{
	for (int i = 0; i < answers.size(); ++i)
	{
		for (int j = 0;  j < answers[i].size(); ++j)
		{
			cout << answers[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > answers;
		sort(num.begin(), num.end());
		for (int i = 0; i < num.size(); ++i)
		{
			int j = i + 1;
			int k = num.size()-1;
			while (k > j)
			{
				if (num[i]+num[j]+num[k]==0)
				{
					vector<int> new_answer;
					new_answer.push_back(num[i]);
					new_answer.push_back(num[j]);
					new_answer.push_back(num[k]);
					answers.push_back(new_answer);
					j++;
				}
				else if (num[i]+num[j]+num[k]<0)
				{
					j++;
				}
				else
				{
					k--;
				}
			}
		}
		sort(answers.begin(),answers.end());
		answers.erase(unique(answers.begin(), answers.end()), answers.end());
		return answers;
	}
};

int main()
{
	int tem[] = {-1, -1, -1, 0, 1, 1, 2, 3};
	vector<int> num(tem, tem+sizeof(tem)/sizeof(int));
	Solution solution;
	vector<vector<int>> answers = solution.threeSum(num);
	print_vec(answers);
}