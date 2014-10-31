#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double pow_MLE(double x, int n) {
		if (0==n)
		{
			return 1;
		}
		if (n < 0)
		{
			n = -n;
			x = 1/x;
		}
		int current = 1;
		vector<double> pd;
		pd.push_back(x);
		while (current<<1 < n)
		{
			x = x*x;
			current = current<<1;
			pd.push_back(x);
		}
		int need = n-current;
		for (auto it = pd.rbegin(); need > 0 && it != pd.rend(); ++it)
		{
			if (current <= need)
			{
				x*=*it;
				need-=current;
			}
			current=current>>1;
		}
		return x;
	}
	double pow_recursion(double x, int n) {
		if (n == 0)
		{
			return 1;
		}
		if (n < 0)
		{
			n = -n;
			x = 1/x;
		}
		return n%2 ? pow(x*x, n>>1)*x : pow(x*x, n>>1);

// 		if (n%2==0)
// 		{
// 			return pow(x*x, n>>1);
// 		}
// 		else
// 		{
// 			return pow(x*x, n>>1)*x;
// 		}
	}
	double pow(double x, int n) {
		if (n == 0)
		{
			return 1;
		}
		if (n < 0)
		{
			n = -n;
			x = 1/x;
		}
		double result = 1;
		while (n > 0)
		{
			if (n&1==1)
			{
				result *= x;
			}
			x *= x;
			n = n >> 1;
		}
		return result;
	}
};

int main()
{
	Solution solution;
	cout << solution.pow(1.0, -2147483648) << endl;
	cout << solution.pow_MLE(1.0, -2147483648) << endl;
	cout << solution.pow_recursion(1.0, -2147483648) << endl;
	cout << solution.pow(1.1, 50) << endl;
	cout << solution.pow_MLE(1.1, 50) << endl;
	cout << solution.pow_recursion(1.1, 50) << endl;
	cout << solution.pow(1.1, -50) << endl;
	cout << solution.pow_MLE(1.1, -50) << endl;
	cout << solution.pow_recursion(1.1, -50) << endl;
}