#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
	string convert(string s, int nRows) {
		if (1==nRows)
		{
			return s;
		}
		int cycle = 2*nRows-2;
		string answer;
		for (int row = 0; row < nRows; ++row)
		{
			for (int i = row, j = cycle-row; i < s.length() || j < s.length(); i+=cycle, j+=cycle)
			{
				answer+=s[i];
				if (row != nRows-1 && row != 0 && j < s.length())
				{
					answer+=s[j];
				}
			}
		}
		return answer;
	}
};
int main()
{
	Solution solution;
	string s = "PAYPALISHIRING";
	string answer = solution.convert(s, 150);
	cout << answer << endl;
	if (s.length()!= answer.length())
	{
		cout << "wrong!" << endl;
	}
}