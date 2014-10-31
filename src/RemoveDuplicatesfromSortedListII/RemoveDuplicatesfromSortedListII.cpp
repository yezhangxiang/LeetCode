#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head)
		{
			return head;
		}
		ListNode tmp(head->val-1);
		tmp.next = head;
		ListNode *current = head;
		head = &tmp;
		ListNode *last = head;
		int last_val = head->val;
		while (current!= NULL)
		{
			if (current->val == last_val || (current->next!=NULL && current->val == current->next->val))
			{
				last->next = current->next;
				last_val = current->val;
			}
			else
			{
				last = current;
			}
			current = current->next;
		}
		return head->next;
	}
};

int main()
{
	int tmp[] = {1,1};
	ListNode a_node(tmp[0]);
	ListNode *first_node = &a_node;
	ListNode *last_node = first_node;
	for (int i = 1; i < sizeof(tmp)/sizeof(int); ++i)
	{
		ListNode *new_node = new ListNode(tmp[i]);
		last_node->next = new_node;
		last_node = new_node;
	}
	Solution solution;
// 	first_node = NULL;
	last_node = solution.deleteDuplicates(first_node);
// 	last_node = first_node;
	while (last_node)
	{
		cout << last_node->val << " ";
		last_node = last_node->next;
	}
	cout << endl;
}