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
		ListNode *first = head;
		while (first!= NULL && first->next!=NULL)
		{
			ListNode *end = first->next;
			while (end != NULL && end->val == first->val)
			{
				end = end->next;
			}
			first->next = end;
			first = end;
		}
		return head;
	}
};

int main()
{
	int tmp[] = {1, 1, 1, 2, 2, 2, 3, 3, 4,5,6,7, 7};
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
	solution.deleteDuplicates(first_node);
	last_node = first_node;
	while (last_node)
	{
		cout << last_node->val << " ";
		last_node = last_node->next;
	}
	cout << endl;
}