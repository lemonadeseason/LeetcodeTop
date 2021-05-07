/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*to deal with empty input*/
        if(head==NULL)
        {
            return NULL;
        }
        /*if only one element, just return itself*/
        if(head->next==NULL)
        {
            return head;
        }
        ListNode* first = head;
        ListNode* cur = head;
        ListNode* next = cur->next;
        while(next->next!=NULL)
        {
            cur = next;
            next = next->next;
        }
        cur->next = NULL;
        next->next = reverseList(first);
        return next;
    }
};
