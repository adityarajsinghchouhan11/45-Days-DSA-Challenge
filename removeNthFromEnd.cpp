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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head;
        ListNode *slow=head;
        for(int i=1;i<=n;i++) 
        {   
            if(fast==nullptr) return head->next;
            fast=fast->next;
        }
        if(fast==nullptr)
        {
            ListNode *dlt=head;
            head=head->next;
            delete dlt;
            return head;
        }
        while(fast->next!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *delnode=slow->next;
        slow->next=slow->next->next;
        delete delnode;
        return head;
    }
};
//ListNode *start=new ListNode;
// start->next=head;
// ListNode *temp=head;
// int count=0;
// while(temp!=nullptr)
// {
//     count++;
//     temp=temp->next;
// }
// int k=count-n;
// temp=start;
// while(k)
// {
//     temp=temp->next;
//     k--;
// }
// ListNode *dlt=temp->next;
// temp->next=temp->next->next;
// delete dlt;
// ListNode *nhead=start->next;
// delete start;
// return nhead;