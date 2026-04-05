#include<iostream>
using namespace std;

struct node {
    node* nxt;
    node* prev;
    int data;
};

class doublecircularlinkedlist {
private:
    node* head;
public:
    doublecircularlinkedlist() {
        head=NULL;
    }

    void insertatposition(int value,int pos) {
        node* newnode=new node();
        newnode->data=value;
        if(head==NULL){
            if(pos==1){
                head=newnode;
                newnode->nxt=head;
                newnode->prev=head;
                return;
            }else{
                cout<<"Position out of range!"<<endl;
                delete newnode;
                return;
            }
        }

        if(pos==1){
            node* temp=head;
            while(temp->nxt!=head){
                temp=temp->nxt;
            }
            newnode->nxt=head;
            newnode->prev=temp;
            temp->nxt=newnode;
            head->prev=newnode;
            head=newnode;
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
        newnode->prev=temp;
        temp->nxt->prev=newnode;
        temp->nxt=newnode;
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
    dc.insertatposition(10,1);
    dc.insertatposition(20,2);
    dc.insertatposition(30,3);
    dc.insertatposition(99,2);
    dc.insertatposition(5,1);

    cout<<"List after insertions at specific positions:";
    dc.display();
    return 0;
}
