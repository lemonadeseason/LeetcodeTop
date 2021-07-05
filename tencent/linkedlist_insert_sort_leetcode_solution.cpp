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
//链表的插入操作为了遍历需要在head之前插入一个dummyHead，这样就可以少判断一次，并且不用为head专门设计操作
//链表中插入一定要有prev，而cur是可有可无，因为通过next能到cur
//如果只用prev->next->val，可能取到没定义的值（到最后时），因此可以判断一下是否当前的target是不是连tail也大于，这样的话，只需要把tail挪到之后的一个就行
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *target = head->next,*temp, *tail=head,*dummyHead = new ListNode(0),*prev;   //tail一开始也等于head，刚开始只有head是sorted
        dummyHead->next = head;
        while(target!=nullptr) 
        {
            if(head==nullptr) return nullptr;
            if(target->val>=tail->val)
            {
                tail = tail->next;
            }
            else
            {
            prev = dummyHead;
            while(prev->next->val<=target->val)   //知道碰到比target大的，插入到该点之前
            {
                prev = prev->next;
            }
            //if(sentinel==nullptr)   //如果target比第一个元素head都小
            temp = target->next;
            target->next = prev->next;
            prev->next = target;   //new added
            tail->next = temp;
            }
            target = tail->next;

        }
        return dummyHead->next;
    }
};
