/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // code here
        Node* dummy=new Node(-1);
        Node* tail=dummy;
        while(head1!=nullptr && head2!=nullptr)
        {
            if(head1->data<=head2->data)
            {
                tail->next=head1;
                head1=head1->next;
            }
            else
            {
                tail->next=head2;
                head2=head2->next;
            }
            tail=tail->next;
        }
        if(head1!=nullptr)
            tail->next=head1;
        if(head2!=nullptr)
            tail->next=head2;
        return dummy->next; 
    }
};