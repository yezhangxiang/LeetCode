#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
		return height(root) >= 0;
    }
	int height(TreeNode* root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);
		if (leftHeight < 0 || rightHeight < 0 || abs(leftHeight-rightHeight) > 1)
		{
			return -1;
		}
		return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
	}
};
int main()
{
	TreeNode *pNode1 = new TreeNode(1);
	TreeNode *pNode2 = new TreeNode(2);
	TreeNode *pNode3 = new TreeNode(3);
	TreeNode *pNode4 = new TreeNode(4);
	TreeNode *pNode5 = new TreeNode(5);
	TreeNode *pNode6 = new TreeNode(6);
	TreeNode *pNode7 = new TreeNode(7);
	TreeNode *pNode8 = new TreeNode(8);

	pNode1->left = pNode2;
	pNode1->right = pNode3;
	pNode2->left = pNode4;
	pNode3->left = NULL;
	pNode3->right = pNode5;
	pNode4->left = pNode6;
	pNode5->right = pNode7;
	//pNode4->left = pNode7;
	//pNode4->right = NULL;
	//pNode6->right = pNode8;

	Solution sol;
	if (sol.isBalanced(pNode1))
	{
		cout << "balanced!" << endl;
	}
	else
	{
		cout << "not banlanced!" << endl;
	}

}