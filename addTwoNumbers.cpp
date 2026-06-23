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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int sum=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(l1!=nullptr || l2!=nullptr)
        {
            sum=carry;
            if(l1) sum+=l1->val;
            if(l2) sum+=l2->val;
            ListNode* n=new ListNode(sum%10);
            temp->next=n;
            temp=temp->next;
            carry=(sum/10);
            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;
        }
        if(carry)
        {
            ListNode *n=new ListNode(carry);
            temp->next=n;
        }
        return dummy->next;
    }
};