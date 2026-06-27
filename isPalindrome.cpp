/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    Node* reverse(Node* head) {
        // code here
        Node *pre=nullptr;
        Node* cur=head;
        while(cur)
        {
            Node* next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
    bool isPalindrome(Node *head) {
        //  code here
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr)  
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *newhead=reverse(slow->next);
        Node* first=head;
        Node * second=newhead;
        while(second)
        {
            if(first->data!=second->data)
            {
                reverse(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newhead);
        return true;
    }
};