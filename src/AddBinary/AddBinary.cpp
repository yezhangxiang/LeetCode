#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int i_a = 0, i_b = 0, carry_bit = 0;
		string sum;
		for (int i = a.length()-1, j = b.length()-1; i >= 0 || j>=0 || carry_bit > 0; --i, --j)
		{
			i_a = i>=0 ? (a[i] == '0' ? 0 : 1) : 0;
			i_b = j>=0 ? (b[j] == '0' ? 0 : 1) : 0;
			int sum_bit = i_a+i_b+carry_bit;
			sum=(sum_bit%2 ? "1" : "0")+sum;
			carry_bit = sum_bit/2;
		}
		return sum;
	}
};

int main()
{
	Solution solution;
	cout << solution.addBinary("11011", "");
}