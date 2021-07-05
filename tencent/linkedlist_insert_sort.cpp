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
        ListNode *target = head->next,*cur,*temp, *tail=head,*prev;   //tail一开始也等于head，刚开始只有head是sorted
        while(target!=nullptr) 
        {
            //ListNode* sentinel=nullptr；
            //从已经排好序的地方从头到尾扫
            cur = head;
            prev= nullptr;
            while(cur!=target&&cur->val<=target->val)   //知道碰到比target大的，插入到该点之前
            {
                prev = cur;
                cur = cur->next;}
            //if(sentinel==nullptr)   //如果target比第一个元素head都小
            if(prev==nullptr)
            {
                temp = target->next;
                tail->next = target->next;
                target->next = head;
                head = target;
                target = temp;
            }
            else if(cur==target){tail = target;target = target->next;}   //如果target比tail还大
            else  //trivial insertion
            {
                temp = target->next;
                prev->next = target;   //new added
                target->next = cur;
                target = temp;
                tail->next = temp;
            }
        }
        return head;
    }
};
