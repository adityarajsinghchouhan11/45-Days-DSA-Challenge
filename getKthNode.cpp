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
    ListNode *reverseLL(ListNode *head)
    {
        ListNode *temp=head;
        ListNode *pre=nullptr;
        while(temp!=nullptr)
        {
            ListNode *next=temp->next;
            temp->next=pre;
            pre=temp;
            temp=next;
        }
        return pre;
    }
    ListNode* getKthNode(ListNode* temp,int k)
    {
        k-=1;
        while(temp!=nullptr && k>0)
        {
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp=head;
        ListNode *preNode=nullptr;
        while(temp!=nullptr)
        {
            ListNode *knode=getKthNode(temp,k);
            if(knode==nullptr)
            {
                if(preNode!=nullptr)
                    preNode->next=temp;
                break;
            }
            ListNode *nextNode=knode->next;
            knode->next=nullptr;
            reverseLL(temp);
            if(head==temp)
                head=knode;
            else
                preNode->next=knode;
            
            preNode=temp;
            temp=nextNode;
        }
        return head;
    }
};