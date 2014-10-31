#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> answer;
		if (matrix.empty())
		{
			return answer;
		}
		int m = matrix.size()-1, n = matrix[0].size();
		int direction = 0;
		int distance = n, i = 0, j = -1;
		while (distance > 0)
		{
			int current_direction = direction % 4;
			int delta_x = (2-current_direction) % 2;
			int delta_y = (1-current_direction) % 2;
			distance = current_direction % 2 ? m-- : n--;
			direction++;
			for (int step = 0; step < distance; step++)
			{
				answer.push_back(matrix[i+=delta_x][j += delta_y]);
			}
		}
		return answer;
	}
};

void createMatrix(vector<vector<int> > &matrix, int m, int n)
{
	
	for (int i = 0; i < m; ++i)
	{
		vector<int> tmp;
		for (int j = 0; j < n; ++j)
		{
			tmp.push_back(j+i*n+1);
			cout << j+i*n+1 << " ";

		}
		matrix.push_back(tmp);
		cout << endl;
	}
}
int main()
{
	vector<vector<int> > matrix;
	vector<int> tmp;
// 	matrix.push_back(tmp);
	createMatrix(matrix, 3, 3);
	Solution solution;
	vector<int> result = solution.spiralOrder(matrix);

	cout<< "sprialOrder***********************" <<endl;
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
}