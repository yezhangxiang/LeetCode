// leetcode.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <queue>
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
    vector<vector<int> > levelOrder(TreeNode *root) {
		
		vector<vector<int> > vec2DValue;
		if (root == NULL) return vec2DValue;

		TreeNode *pNodeNull = new TreeNode(0);

		queue<TreeNode*>NodeQueue;

		NodeQueue.push(root);
		NodeQueue.push(pNodeNull);

		vector<int>vecValue;

		while(NodeQueue.size()>1)
		{
			TreeNode* pPopNode = NULL;
			pPopNode = NodeQueue.front();

			if (pPopNode == pNodeNull)
			{
				vec2DValue.push_back(vecValue);
				vecValue.clear();
				NodeQueue.pop();
				NodeQueue.push(pNodeNull);
				continue;
			}

			if (pPopNode)
			{
				vecValue.push_back(pPopNode->val);
				if (pPopNode->left)
					NodeQueue.push(pPopNode->left);
				if (pPopNode->right)
					NodeQueue.push(pPopNode->right);
			}

			NodeQueue.pop();
		}
		vec2DValue.push_back(vecValue);

		delete pNodeNull;
		pNodeNull = NULL;
		return vec2DValue;
	}
};

int main(int argc, char* argv[])
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
	pNode2->right = pNode5;
	pNode3->left = NULL;
	pNode3->right = pNode6;
	pNode4->left = pNode7;
	pNode4->right = NULL;
	pNode6->right = pNode8;

	vector<vector<int> > vecInt2D;
	Solution sol;
	vecInt2D = sol.levelOrder(NULL);

	for (auto i = vecInt2D.begin(); i != vecInt2D.end();i++)
	{
		for(auto j = (*i).begin(); j != (*i).end(); j++)
		{
			cout << *j;
			cout << " ";
		}
		cout << endl;
	}
	
	return 0;
}