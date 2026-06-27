/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
    Node* merge2list(Node* head1,Node* head2)
    {
        Node *dummy=new Node(-1);
        Node* temp=dummy;
        while(head1 && head2)
        {
            if(head1->data<head2->data)
            {
                temp->bottom=head1;
                head1=head1->bottom;
                
            }
            else
            {
                temp->bottom=head2;
                head2=head2->bottom;
            }
            temp=temp->bottom;
        }
        if(head1) temp->bottom=head1;
        else    temp->bottom=head2;
        return dummy->bottom;
    }
    Node *flatten(Node *root) {
        // code here
        if(root==nullptr || root->next==nullptr)
            return root;
        Node* mergehead=flatten(root->next);
        return merge2list(mergehead,root);
    }
};