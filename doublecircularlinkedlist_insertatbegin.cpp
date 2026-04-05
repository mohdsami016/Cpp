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
			void insertatbegin(int value){
				node* newnode=new node();
				newnode->data=value;
				newnode->prev=NULL;
				newnode->nxt=NULL;
				if(head==NULL){
					head=newnode;
					newnode->nxt=head;
				}
				else{
					node* temp=head;
					while(temp->nxt!=head){
						temp=temp->nxt;
					}
					head->prev=newnode;
					newnode->nxt=head;
					head=newnode;
					temp->nxt=head;
				}
			}
			void display(){
				node* temp=head;
				do{
					cout<<temp->data<<"->";
					temp=temp->nxt;
				}while(temp!=head);
				cout<<"Head";
			}
};
int main(){
	doublecircularlinkedlist dc;
	dc.insertatbegin(40);
	dc.insertatbegin(30);
	dc.insertatbegin(20);
	dc.insertatbegin(10);
	dc.display();
	return 0;
}
