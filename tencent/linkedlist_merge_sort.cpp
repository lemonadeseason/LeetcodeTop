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
    //使用自上而下的归并排序
    ListNode* sortList(ListNode* head) {
        return sortList_recursive(head);
    }
    ListNode* sortList_recursive(ListNode* head) {
        if(head==nullptr) return nullptr; //输入可能为空
        if(head->next==nullptr) return head; //如果链表长度为1，则直接返回
        //否则找到这个链表的中点，分为两个独立的链表（前一个也有next域为nullptr的尾部），将两个排序好，调用归并
        ListNode *quick = head, *slow=head;
        while(quick!=nullptr&&quick->next!=nullptr&&quick->next->next!=nullptr)   //链表长度为2会正常退出循环，为3时也会退出，为4时进入下一轮循环，会在下下一轮开始时面临同长度为2一样的情况
        {
            //while循环的条件至少保证了还有3个元素
            quick = quick->next->next;    
            slow = slow->next;
        }
        //return new ListNode(slow->val);
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        head = sortList_recursive(head);
        head2 = sortList_recursive(head2);
        return merge(head,head2); //返回合并的结果
    }
    //将两个排好序的链表，按照从小到大的顺序合并
    ListNode* merge(ListNode* head1,ListNode* head2)
    {
        ListNode* dummmyHead = new ListNode(0),*cur = dummmyHead;
        while(head1!=nullptr&&head2!=nullptr)
        {
            if(head1->val<head2->val)
            {
                cur->next = head1;
                cur = head1;
                head1 = head1->next;
            }
            else
            {
                cur->next = head2;
                cur = head2;
                head2 = head2->next;
            }
        }
        if(head1!=nullptr)
        {
            cur->next=head1;
        }
        else
        {
            cur->next=head2;
        }
        return dummmyHead->next;
    }

};
