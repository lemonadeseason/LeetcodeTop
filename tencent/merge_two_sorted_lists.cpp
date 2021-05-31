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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode* head = new ListNode();
        ListNode* cur = head;
        while(l1!=nullptr&&l2!=nullptr)
        {
            cur->next = new ListNode();
            cur=cur->next;
            if(l1->val<l2->val)
            {cur->val=l1->val;
            l1=l1->next;}
            else
            {cur->val=l2->val;
            l2=l2->next;}
        }
        while(l1!=nullptr)
        {
            cur->next = new ListNode();
            cur=cur->next;
            cur->val=l1->val;
            l1 = l1->next;
        }
        while(l2!=nullptr)
        {
            cur->next = new ListNode();
            cur=cur->next;
            cur->val=l2->val;
            l2 = l2->next;
        }
        return head->next;
    }
};
