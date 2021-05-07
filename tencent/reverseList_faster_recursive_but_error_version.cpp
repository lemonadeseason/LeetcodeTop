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
        if(!head)
        {
            return nullptr;
        }
        if(!(head->next))   //最后一个元素
        {
            return head;
        }
        ListNode* newHead = reverseList(head->next);   //head之后的所有节点已经反转了
        head->next->next = head;
        return newHead;
    }
};
