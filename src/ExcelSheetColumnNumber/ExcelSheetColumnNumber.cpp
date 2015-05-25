#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
		int ans = 0;
		for (auto it = s.begin(); it != s.end(); ++it)
		{
			ans *= 26;
			ans += (*it-'A'+1);
		}
        return ans;
    }
};

int main()
{
	Solution solution;
	cout << solution.titleToNumber("Z") << endl;
}