#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		string last = "1";
		string current;
		for (int i = 1; i < n; ++i)
		{
			int same=1;
			for (auto it = last.begin(); it!=last.end(); ++it)
			{
				if (it+1 != last.end() && *it==*(it+1))
				{
					same++;
				}
				else
				{
					current.push_back(same+'0');
					current.push_back(*it);
					same = 1;
				}
			}
			last = current;
			current.clear();
		}
		return last;
	}
};
int main()
{
	Solution solution;
	cout << solution.countAndSay(1) << endl;
	cout << solution.countAndSay(2) << endl;
	cout << solution.countAndSay(3) << endl;
	cout << solution.countAndSay(4) << endl;
}