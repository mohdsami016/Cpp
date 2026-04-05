#include<iostream>
using namespace std;

struct node {
    int data;
    node* nxt;
};

class CircularLinkedList {
private:
    node* head;
public:
    CircularLinkedList() {
        head=NULL;
    }

    void insertatbeggining(int value) {
        node* newnode=new node();
        newnode->data=value;
        if(head==NULL){
            head=newnode;
            head->nxt=head;
            return;
        }
        node* temp=head;
        while(temp->nxt!=head){
            temp=temp->nxt;
        }
        temp->nxt=newnode;
        newnode->nxt=head;
        head=newnode;
    }

    void deleteatposition(int pos) {
        if(head==NULL){
            cout<<"List is empty!"<<endl;
            return;
        }

        node* temp=head;
        if(pos==1){
            if(head->nxt==head){
                delete head;
                head=NULL;
                return;
            }
            node* last=head;
            while(last->nxt!=head){
                last=last->nxt;
            }
            head=head->nxt;
            last->nxt=head;
            delete temp;
            return;
        }

        int count=1;
        node* prev=NULL;
        while(count<pos && temp->nxt!=head){
            prev=temp;
            temp=temp->nxt;
            count++;
        }

        if(count!=pos){
            cout<<"Position out of range!"<<endl;
            return;
        }

        prev->nxt=temp->nxt;
        delete temp;
    }

    void display() {
        if(head==NULL){
            cout<<"List is empty!"<<endl;
            return;
        }
        node* temp=head;
        do{
            cout<<temp->data<<"->";
            temp=temp->nxt;
        }while(temp!=head);
        cout<<"HEAD"<<endl;
    }
};

int main() {
    CircularLinkedList c;
    c.insertatbeggining(40);
    c.insertatbeggining(30);
    c.insertatbeggining(20);
    c.insertatbeggining(10);

    cout<<"Original circular list:";
    c.display();

    c.deleteatposition(2);
    cout<<"After deleting element at position 2:";
    c.display();

    c.deleteatposition(1);
    cout<<"After deleting element at position 1:";
    c.display();

    c.deleteatposition(10);
    return 0;
}
