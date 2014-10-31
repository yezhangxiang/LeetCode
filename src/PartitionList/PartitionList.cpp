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
    ListNode *partition(ListNode *head, int x) {
        ListNode *current=head;
		ListNode *last_small = NULL;
		ListNode *last_big = NULL;
		ListNode *first_small = NULL;
		ListNode *first_big = NULL;
		bool have_small = false;
		bool have_big = false;
		if (head==NULL)
		{
			return head;
		}
		while (current)
		{
			if (current->val < x)
			{
				if (!have_small)
				{
					first_small = current;
					have_small = true;
					last_small = first_small;
				}
				else
				{
					last_small->next = current;
					last_small = last_small->next;
				}
			}
			else
			{
				if (!have_big)
				{
					first_big = current;
					have_big = true;
					last_big = first_big;
				}
				else
				{
					last_big->next = current;
					last_big = last_big->next;
				}
			}
			current =current->next;
		}
		if (last_big)
		{
			last_big->next = NULL;
		}
		if (last_small)
		{
			last_small->next = first_big;
			return first_small;
		}
		else
		{
			return first_big;
		}
    }
};

int main()
{
// 	int tmp[] = {2,1};
	int tmp[] = {1,4,3,5,2,3,1};
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
	last_node = solution.partition(first_node, 10);
	while (last_node)
	{
		cout << last_node->val << " ";
		last_node = last_node->next;
	}
	cout << endl;
}