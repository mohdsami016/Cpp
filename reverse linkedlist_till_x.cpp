#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val):data(val),next(NULL){}
};

Node* reverseTillKey(Node* head,int key) {
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;

    while(curr!=NULL && curr->data!=key) {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }

    if(curr!=NULL && curr->data==key) {
        next=curr->next;
        curr->next=prev;
        head->next=next;
        return curr;
    }

    return head;
}

void printList(Node* head) {
    while(head!=NULL) {
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"NULL\n";
}

int main() {
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);

    cout<<"Original List:\n";
    printList(head);

    int key=3;
    head=reverseTillKey(head,key);

    cout<<"List after reversing till "<<key<<":\n";
    printList(head);

    return 0;
}
