#include<iostream>
using namespace std;

struct node{
    node* nxt;
    node* prev;
    int data;
};

class doublecircularlinkedlist{
private:
    node* head;
public:
    doublecircularlinkedlist(){
        head=NULL;
    }

    void insertatend(int value){
        node* newnode=new node();
        newnode->data=value;
        if(head==NULL){
            head=newnode;
            newnode->nxt=head;
            newnode->prev=head;
        }else{
            node* temp=head;
            while(temp->nxt!=head){
                temp=temp->nxt;
            }
            temp->nxt=newnode;
            newnode->prev=temp;
            newnode->nxt=head;
            head->prev=newnode;
        }
    }

    void deleteatbegin(){
        if(head==NULL){
            cout<<"List is empty!"<<endl;
            return;
        }
        if(head->nxt==head){
            delete head;
            head=NULL;
            return;
        }
        node* last=head->prev;
        node* temp=head;
        head=head->nxt;
        head->prev=last;
        last->nxt=head;
        delete temp;
    }

    void deleteatposition(int pos){
        if(head==NULL){
            cout<<"List is empty!"<<endl;
            return;
        }
        if(pos==1){
            deleteatbegin();
            return;
        }
        node* temp=head;
        int count=1;
        while(count<pos && temp->nxt!=head){
            temp=temp->nxt;
            count++;
        }
        if(count!=pos){
            cout<<"Position out of range!"<<endl;
            return;
        }
        node* prevnode=temp->prev;
        node* nextnode=temp->nxt;
        prevnode->nxt=nextnode;
        nextnode->prev=prevnode;
        delete temp;
    }

    void display(){
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

int main(){
    doublecircularlinkedlist dc;
    dc.insertatend(10);
    dc.insertatend(20);
    dc.insertatend(30);
    dc.insertatend(40);

    cout<<"Original list:";
    dc.display();

    dc.deleteatposition(2);
    cout<<"After deleting element at position 2:";
    dc.display();

    dc.deleteatposition(1);
    cout<<"After deleting element at position 1:";
    dc.display();

    dc.deleteatposition(10);
    return 0;
}
