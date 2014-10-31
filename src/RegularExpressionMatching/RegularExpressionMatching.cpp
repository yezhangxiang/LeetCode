#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

class Solution {
public:
// 	bool isMatch(const char *s, const char *p) {
// 		const char *last_s = NULL;
// 		const char *last_p = NULL;
// 		while ('\0' != *s || '*' == *p)
// 		{
// 			if (*s == *p || '?' == *p)
// 			{
// 				s++;
// 				p++;
// 				continue;
// 			}
// 			if ('*' == *p)
// 			{
// 				while ('*' == *p)
// 				{
// 					last_p = p;
// 					p++;
// 				}
// 				while ('\0' != *s && (*s != *p && '?' != *p))
// 				{
// 					s++;
// 				}
// 				last_s = s;
// 				continue;
// 			}
// 			if (last_p != NULL)
// 			{
// 				p = last_p;
// 				s = last_s+1;
// 				continue;
// 			}
// 			return false;
// 		}
// 		if ('\0' == *p)
// 		{
// 			return true;
// 		}
// 		return false;
// 	}

	bool isMatch(const char *s, const char *p) {
		int len_s = strlen(s);
		int len_p = strlen(p);
		if (0==len_p*len_s)
		{
			if ('\0' == *s && '\0' == *p)
			{
				return true;
			}
			if ('*' == *(s+1))
			{
				return isMatch(s+2, p);
			}
			if ('*' == *(p+1))
			{
				return isMatch(s, p+2);
			}
			return false;
		}
		bool* last = (bool *)malloc(sizeof(bool) * len_p);
		bool* current = (bool *)malloc(sizeof(bool) * len_p);
		memset(last, true, sizeof(bool) * len_p);
		memset(current, false, sizeof(bool) * len_p);

		for (int i = 0; i < len_s; ++i)
		{
			memset(current, false, sizeof(bool) * len_p);
			if (((last[0] && '*'==s[i]) && (s[i-1] == p[0]||'.'==p[0])) || \
				(0==i && (s[i] == p[0] || s[i] == '.' || p[0] == '.')))
			{
				current[0] = true;
			}
			for (int j = 1; j < len_p; ++j)
			{
				if ((((last[j]||current[j-1]) && '*'==s[i]) && (s[i-1] == p[j]||'.'==p[j]||'.'==s[i-1]||('*'==p[j]&&(s[i-1]==p[j-1]|| s[i-1] == '.' || p[j-1] == '.')))) || \
					(((last[j]||current[j-1]) && '*'==p[j]) && (s[i] == p[j-1]||'.'==s[i]||'.'==p[j-1]||('*'==s[i]&&(s[i-1]==p[j-1]|| s[i-1] == '.' || p[j-1] == '.')))) || \
					(last[j-1] && (s[i] == p[j] || s[i] == '.' || p[j] == '.')))
				{
					current[j] = true;
				}
			}
			bool* tmp = last;
			last = current;
			current = tmp;
		}
		return last[len_p-1];
	}

	bool isMatch_recursion(const char *s, const char *p) {
		if ('\0' == *s && '\0' == *p)	return true;
		if ('*' == *(s+1)) return asteriskMatch(p, s);
		if ('*' == *(p+1)) return asteriskMatch(s, p);
		if (*s == *p || ('.' == *s && '\0' != *p) || ('.' == *p && '\0' != *s)) return isMatch_recursion(++s, ++p);
		return false;
	}
private:
	bool asteriskMatch(const char *s, const char *asterisk)
	{
		while (*s-1 != '\0')
		{
			if (isMatch_recursion(s, asterisk+2))	return true;
			if (*s != *asterisk && '.' != *s)	return false;
			s++;
		}
		return false;
	}
};
void test(Solution solution)
{
	vector<const char *> s_vec;
	vector<const char *> p_vec;
	vector<bool> answer;
	s_vec.push_back("ho");
	p_vec.push_back("ho");
	answer.push_back(true);
	s_vec.push_back("aaa");
	p_vec.push_back("aaaa");
	answer.push_back(true);
	s_vec.push_back("aa");
	p_vec.push_back(".*");
	answer.push_back(true);
	s_vec.push_back("c");
	p_vec.push_back(".");
	answer.push_back(true);
	s_vec.push_back("");
	p_vec.push_back("");
	answer.push_back(true);
	s_vec.push_back("");
	p_vec.push_back("a");
	answer.push_back(false);
	s_vec.push_back("a");
	p_vec.push_back("");
	answer.push_back(false);
	s_vec.push_back("");
	p_vec.push_back("c*");
	answer.push_back(true);
// 	s_vec.push_back("c*");
// 	p_vec.push_back("");
// 	answer.push_back(true);
	s_vec.push_back("aab");
	p_vec.push_back("aa");
	answer.push_back(false);
	s_vec.push_back("aab");
	p_vec.push_back("c*a*b");
	answer.push_back(true);
	s_vec.push_back(".aab");
	p_vec.push_back("c*a*b");
	answer.push_back(true);
	s_vec.push_back(".aab.");
	p_vec.push_back("c*a*b");
	answer.push_back(false);
	s_vec.push_back(".aa*b");
	p_vec.push_back("c*a*b");
	answer.push_back(true);
	s_vec.push_back("aa");
	p_vec.push_back("c*a*");
	answer.push_back(true);
	s_vec.push_back("aab");
	p_vec.push_back("c*a*");
	answer.push_back(false);
	s_vec.push_back("aaaaaab");
	p_vec.push_back("c*a*b");
	answer.push_back(true);
	s_vec.push_back("cccccccaab");
	p_vec.push_back("c*a*b");
	answer.push_back(true);
	s_vec.push_back("aabb");
	p_vec.push_back("c*a*b");
	answer.push_back(false);
	s_vec.push_back("b");
	p_vec.push_back("c*a*b");
	answer.push_back(true);
	for (int i = 0; i < s_vec.size(); ++i)
	{
		// 		const char *s = s_vec[i].c_str();
		// 		const char *p = p_vec[i].c_str();
		const char *s = s_vec[i];
		const char *p = p_vec[i];
		if (solution.isMatch(s, p)==answer[i])
		{
			cout << i << " pass" << endl;
		} 
		else
		{
			// 			cout << s_vec[i].c_str() << " not pass" << endl;
			cout << s_vec[i] << " " << p_vec[i] << " not pass" << endl;
		}
	}
}
int main()
{
	Solution solution;
	clock_t start, end;
// 	start = clock();
// 	test(solution);
// 	end = clock();	
// 	cout << (double)(end - start)/CLOCKS_PER_SEC << endl;
	const char *s = "aaa";
	const char *p = "aaaa";
	if (solution.isMatch(s, p))
	{
		cout << " pass" << endl;
	} 
	else
	{
		cout << " not pass" << endl;
	}
	cout << "Done!" << endl;
	return 0;
}