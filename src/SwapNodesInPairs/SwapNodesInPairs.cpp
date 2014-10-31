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
	ListNode *swapPairs(ListNode *head) {
		ListNode *first = head;
		ListNode *last_second = NULL;
		while (first!=NULL && first->next!=NULL)
		{
			ListNode *second = first->next;
			if (second!=NULL)
			{
				if (first == head)
				{
					head = second;
				}
				else
				{
					last_second->next = second;
				}
				ListNode *tmp = second->next;
				second->next = first;
				first->next = tmp;
				last_second = first;
				first = tmp;
			}
			else
			{
				first = second;
			}
		}
		return head;
	}
};
int main()
{
	int tmp[] = {1, 2, 3, 4, 5, 6, 7};
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
	first_node = NULL;
	last_node = solution.swapPairs(first_node);
	while (last_node)
	{
		cout << last_node->val << " ";
		last_node = last_node->next;
	}
	cout << endl;
}