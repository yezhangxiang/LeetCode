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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ans;
		recursion(ans, root);
		return ans;
	}
private:
	void recursion(vector<int> &order, TreeNode*root)
	{
		if (root)
		{
			recursion(order, root->left);
			recursion(order, root->right);
			order.push_back(root->val);
		}
	}
};


int main()
{

}