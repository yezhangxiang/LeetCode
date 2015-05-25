#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<char> st;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
			switch (*it)
			{
			case ')':
				if (st.empty() || st.top()!='(')
				{
					return false;
				}
				st.pop();
				break;
			case ']':
				if (st.empty() || st.top()!='[')
				{
					return false;
				}
				st.pop();
				break;
			case '}':
				if (st.empty() || st.top()!='{')
				{
					return false;
				}
				st.pop();
				break;
			case '(':
			case '[':
			case '{':
				st.push(*it);
				break;
			default:
				return false;
			}
        }
		return st.empty();
    }
};

int main()
{
	Solution solution;
	if (solution.isValid("[][](){}{}[[]]"))
	{
		cout << "valid" << endl;
	}
	else
	{
		cout << "invalid" << endl;
	}
}