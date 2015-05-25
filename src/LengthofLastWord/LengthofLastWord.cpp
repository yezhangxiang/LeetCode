#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
		bool start = false;
		int ans = 0;

        for (auto it = s.rbegin(); it != s.rend(); ++it)
		{
			if (!start && *it == ' ')
			{
				continue;
			}
			if (start && *it == ' ')
			{
				break;
			}
			start = true;
			ans++;
		}
		return ans;
    }
};
int main()
{
	Solution solution;
	cout << solution.lengthOfLastWord("hello world   ") << endl;
}