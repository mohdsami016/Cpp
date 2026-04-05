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

    void insertatposition(int value,int pos) {
        node* newnode=new node();
        newnode->data=value;
        if(head==NULL){
            if(pos==1){
                head=newnode;
                head->nxt=head;
                return;
            }else{
                cout<<"Position out of range!"<<endl;
                delete newnode;
                return;
            }
        }

        if(pos==1){
            insertatbeggining(value);
            delete newnode;
            return;
        }

        node* temp=head;
        int count=1;
        while(count<pos-1 && temp->nxt!=head){
            temp=temp->nxt;
            count++;
        }

        if(count!=pos-1){
            cout<<"Position out of range!"<<endl;
            delete newnode;
            return;
        }

        newnode->nxt=temp->nxt;
        temp->nxt=newnode;
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

    c.insertatposition(99,3);
    cout<<"After inserting 99 at position 3:";
    c.display();

    c.insertatposition(5,1);
    cout<<"After inserting 5 at position 1:";
    c.display();

    c.insertatposition(100,10);
    return 0;
}
