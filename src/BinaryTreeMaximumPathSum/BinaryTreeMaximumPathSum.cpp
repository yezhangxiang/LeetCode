#include <iostream>
using namespace std;

/**
 * Definition for binary tree

 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxPathSum(TreeNode *root) {
		if (root==NULL)
		{
			return 0;
		}
		int max_path=INT_MIN;
		int max_left = 0, max_right = 0;
		maxPathNode(root, max_left, max_right, max_path);
		return max_path;
	}
private:
	int maxPathNode(TreeNode *current, int &max_left, int &max_right, int &max_path)
	{
		int left_max_left=0, left_max_right=0;
		int right_max_left=0, right_max_right=0;
		max_right = max_left = current->val;
		if (current->left)
		{
			maxPathNode(current->left, left_max_left, left_max_right, max_path);
			max_left += max(current->left->val, max(left_max_left, left_max_right));
		}
		if (current->right)
		{
			maxPathNode(current->right, right_max_left, right_max_right, max_path);
			max_right += max(current->right->val, max(right_max_left, right_max_right));
		}
		int max_current =	max(left_max_left, max(left_max_right,0)) + \
			max(right_max_left, max(right_max_right,0)) + current->val;
		max_path = max(max_current, max_path);
		return max_current;
	}
	int max(int foo, int bar)
	{
		return foo > bar ? foo : bar;
	}
};

int main()
{
	TreeNode *pNode1 = new TreeNode(9);
	TreeNode *pNode2 = new TreeNode(6);
	TreeNode *pNode3 = new TreeNode(-3);
	TreeNode *pNode4 = new TreeNode(-6);
	TreeNode *pNode5 = new TreeNode(2);
	TreeNode *pNode6 = new TreeNode(2);
	TreeNode *pNode7 = new TreeNode(-6);
	TreeNode *pNode8 = new TreeNode(-6);
	TreeNode *pNode9 = new TreeNode(-6);

	pNode1->left = pNode2;
	pNode1->right = pNode3;
	pNode3->left = pNode4;
	pNode3->right = pNode5;
	pNode5->right = pNode6;
	pNode6->left = pNode7;
	pNode6->right = pNode8;
	pNode8->left = pNode9;

	Solution sol;
	cout << sol.maxPathSum(pNode1);

	return 0;
}