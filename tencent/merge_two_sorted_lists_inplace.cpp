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
       //设置一个prev，就可以实现in place的合并了
        ListNode *head=new ListNode(),*pre=head;
        while(l1!=nullptr&&l2!=nullptr)
        {
        if(l1->val<l2->val)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
        }
        
        pre->next = l1!=nullptr?l1:l2;     //顶多l2也是空，指向空也无所谓，本来就是最后一个要指向空
        return head->next;
    }
};
