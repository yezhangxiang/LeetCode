#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1=="0" || num2=="0")
		{
			return "0";
		}
		int len1 = num1.length();
		int len2 = num2.length();
		int mul_len = len1+len2-1;
		int mod = 0;
		string result;
		for (int i = 0; i < mul_len; ++i)
		{
			int mul_i = mod;

			for (int j = 0; j <= i; ++j)
			{
				if (len1-j-1 >= 0 && len2-i+j-1 >= 0)
				{
					mul_i += (num1[len1-j-1]-'0')*(num2[len2-i+j-1]-'0');
				}
			}
			mod = mul_i/10;
			mul_i%=10;
			result.insert( result.begin(), '0'+mul_i );
		}
		if (mod > 0)
		{
			result.insert( result.begin(), '0'+mod );
		}
		return result;
	}
};

int main()
{
	Solution solution;
	string num1 = "246543214654651435145241654654531321231564787465";
	string num2 = "5413213241564874654132132156456135461561321321231";
	cout << solution.multiply(num1, num2) << endl;
}