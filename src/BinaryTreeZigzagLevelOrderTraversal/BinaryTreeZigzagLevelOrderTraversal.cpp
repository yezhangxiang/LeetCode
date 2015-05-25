#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		list<TreeNode*> tmp;
		int curLine = 0, nextLine = 0;
		bool right2Left = true;
		if (root)
		{
			tmp.push_back(root);
			curLine++;
		}
		while (!tmp.empty())
		{
			vector<int> curLayer;
			right2Left = !right2Left;
			for (int i = 0; i < curLine; ++i)
			{
				TreeNode* topNode = *tmp.begin();
				if (topNode->left)
				{
					tmp.push_back(topNode->left);
					nextLine++;
				}
				if (topNode->right)
				{
					tmp.push_back(topNode->right);
					nextLine++;
				}
				curLayer.push_back(topNode->val);
				tmp.pop_front();
			}
			curLine = nextLine;
			nextLine = 0;
			if (right2Left)
			{
				 reverse(curLayer.begin(), curLayer.end());
			}
			ans.push_back(curLayer);
		}
		return ans;
    }
};

int main()
{
	Solution solution;
	TreeNode* root = new TreeNode(1);
	TreeNode n1(2);
	TreeNode n2(3);
	TreeNode n3(4);
	TreeNode n4(5);
	TreeNode n5(9);
	root->left = &n1;
	root->right = &n2;
	n1.left = &n3;
	n2.right = &n4;

	vector<vector<int>> ans = solution.zigzagLevelOrder(root);
}