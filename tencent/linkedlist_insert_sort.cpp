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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* target = head->next,*cur,*prev=nullptr,*temp;
        while(target!=nullptr)
        {
            cur = head;
            while(cur!=target&&cur->val<=target->val)   //没有到边界而且还小
            {cur = cur->next;}
            if(prev==nullptr)   //如果target比head都小
            {
                temp = target->next;
                target->next = head;
                head = target;
                target = temp;
            }
        }
        return head;
    }
};
