/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		vector<int> num;
		ListNode *current = head;
		do 
		{
			num.push_back(current->val);
			current = current->next;
		} while (current != NULL);
		return recursion(num.begin(), num.end());
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
	ListNode* start_node = new ListNode(0);
	ListNode* lastnode = start_node;
	for (int i = 1; i < 7; ++i)
	{
		ListNode* new_listnode = new ListNode(i);
		lastnode->next = new_listnode;
		lastnode = new_listnode;
	}
	TreeNode *sort_node = solution.sortedListToBST(start_node);
}