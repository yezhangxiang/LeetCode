/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head != NULL)
        {
            (head->val == val ? head : head->next) = removeElements(head->next, val);
        }
        return head;
    }
};

