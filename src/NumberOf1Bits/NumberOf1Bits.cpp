#include <iostream>
#include <stdint.h>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (n & 0x01)
            {
                ans++;
            }
            n = n >> 1;
        }
        return ans;
    }
};
int main()
{
	Solution solution;
	uint32_t n = 11;
	cout << solution.hammingWeight(n) << endl;
}