#include<iostream>
using namespace std;

struct node {
    int data;
    node* nxt;
    node* prev;
};

class Doublelinkedlist {
private:
    node* head;
public:
    Doublelinkedlist() {
        head=NULL;
    }

    void insertatbeggining(int value) {
        node* newnode=new node();
        newnode->data=value;
        newnode->prev=NULL;
        newnode->nxt=NULL;
        if(head==NULL) {
            head=newnode;
            return;
        }
        newnode->nxt=head;
        head->prev=newnode;
        head=newnode;
    }

    void insertatposition(int value,int pos) {
        node* newnode=new node();
        newnode->data=value;
        newnode->prev=NULL;
        newnode->nxt=NULL;

        if(pos==1) {
            insertatbeggining(value);
            return;
        }

        node* temp=head;
        int count=1;

        while(temp!=NULL && count<pos-1) {
            temp=temp->nxt;
            count++;
        }

        if(temp==NULL) {
            cout<<"Position out of range!"<<endl;
            delete newnode;
            return;
        }

        newnode->nxt=temp->nxt;
        newnode->prev=temp;

        if(temp->nxt!=NULL) {
            temp->nxt->prev=newnode;
        }
        temp->nxt=newnode;
    }

    void display() {
        node* temp=head;
        while(temp!=NULL) {
            cout<<temp->data<<"->";
            temp=temp->nxt;
        }
        cout<<"NULL"<<endl;
    }
};

int main() {
    Doublelinkedlist s;
    s.insertatbeggining(80);
    s.insertatbeggining(40);
    s.insertatbeggining(20);
    s.insertatbeggining(10);

    cout<<"Original list:";
    s.display();

    s.insertatposition(99,3);
    cout<<"After inserting 99 at position 3:";
    s.display();

    s.insertatposition(5,1);
    cout<<"After inserting 5 at position 1:";
    s.display();

    s.insertatposition(100,10);
    return 0;
}
