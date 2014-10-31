#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > answers;
		vector<int> current_answers;
		res(n, k, 0, 0, answers, current_answers);
		return answers;
	}
private:
	void res(int n, int k, int dep, int current, vector<vector<int> > &answers, vector<int> &current_answers)
	{
		if (dep == k)
		{
			answers.push_back(current_answers);
		}
		else
		{
			for (int next = current + 1; next <= n; ++next)
			{
				current_answers.push_back(next);
				res(n, k, dep+1, next, answers, current_answers);
				current_answers.pop_back();
			}
		}
	}
};

int main()
{
	Solution solution;
	vector<vector<int> > answers = solution.combine(15, 3);
	for (int i = 0;  i< answers.size(); ++i)
	{
		for (int j = 0; j < answers[i].size(); ++j)
		{
			cout << answers[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}