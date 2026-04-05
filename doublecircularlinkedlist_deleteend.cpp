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

    void deleteatend(){
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
        node* secondlast=last->prev;
        secondlast->nxt=head;
        head->prev=secondlast;
        delete last;
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

    dc.deleteatend();
    cout<<"After deleting at end:";
    dc.display();
    return 0;
}
