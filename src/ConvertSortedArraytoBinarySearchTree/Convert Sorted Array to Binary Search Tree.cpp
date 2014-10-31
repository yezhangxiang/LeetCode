

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return recursion(num.begin(), num.end());
	}
	TreeNode *sortedArrayToBST_1(vector<int> &num) {
		if (num.size()==0)
		{
			return NULL;
		}
		int current = (int)(num.size()/2);
		TreeNode* current_node = new TreeNode(num[current]);
		if (num.size() > 1)
		{
			current_node->left = sortedArrayToBST_1(vector<int>(num.begin(), num.begin()+current));
			current_node->right = sortedArrayToBST_1(vector<int>(num.begin()+current+1, num.end()));
		}
		return current_node;
	}
private:
	TreeNode *recursion(vector<int>::iterator begin, vector<int>::iterator end) {
		if (end-begin==0)
		{
			return NULL;
		}
		int current = (int)((end-begin)/2);
		TreeNode* current_node = new TreeNode(*(begin+current));
		current_node->left = recursion(begin, begin+current);
		current_node->right = recursion(begin+current+1, end);
		return current_node;
	}
};

int main()
{
	Solution solution;
	vector<int> num;
	for (int i = 0; i < 7; ++i)
	{
		num.push_back(i);
	}
	TreeNode *sort_node = solution.sortedArrayToBST(num);
}