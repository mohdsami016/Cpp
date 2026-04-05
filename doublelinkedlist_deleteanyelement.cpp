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

    void deleteatposition(int pos) {
        if(head==NULL) {
            cout<<"List is empty!"<<endl;
            return;
        }

        node* temp=head;
        int count=1;

        if(pos==1) {
            head=head->nxt;
            if(head!=NULL) {
                head->prev=NULL;
            }
            delete temp;
            return;
        }

        while(temp!=NULL && count<pos) {
            temp=temp->nxt;
            count++;
        }

        if(temp==NULL) {
            cout<<"Position out of range!"<<endl;
            return;
        }

        if(temp->prev!=NULL) {
            temp->prev->nxt=temp->nxt;
        }
        if(temp->nxt!=NULL) {
            temp->nxt->prev=temp->prev;
        }
        delete temp;
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

    s.deleteatposition(2);
    cout<<"After deleting element at position 2:";
    s.display();

    s.deleteatposition(1);
    cout<<"After deleting element at position 1:";
    s.display();

    s.deleteatposition(10);
    return 0;
}
