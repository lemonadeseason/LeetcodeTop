/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//设置一快一慢的两个指针，如果两个可以相遇，则代表是有环的（但可能某些圈可能会错过？）
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;   //不然的话都进不了while循环
        //int i = 1;
        while(slow!=fast)
        {
            if(fast==NULL||fast->next==NULL)   //有结尾
            return false;
            //fast = fast->next;
            fast = fast->next->next;
            //if((i++)%2==0)
            slow = slow->next;
        }
        return true;    //如果slow和fast重合了，代表是有环的
    }
};
