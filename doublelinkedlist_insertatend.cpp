#include<iostream>
using namespace std;
struct node{
	int data;
	node* nxt;
	node* prev;
};
class Doublelinkedlist{
	private:
		node* head;
		public:
			Doublelinkedlist(){
				head=NULL;
			}
			void insertatEnd(int value){
				node* newnode=new node();
				newnode->data=value;
				newnode->prev=NULL;
				newnode->nxt=NULL;
				if(head==NULL){
					head=newnode;
					return ;
				}
				node* temp=head;
				while(temp->nxt!=NULL){
					temp=temp->nxt;
				}
				temp->nxt=newnode;
				newnode->prev=temp;
			}
			void display(){
				node* temp=head;
				while(temp!=NULL){
					cout<<temp->data<<"->";
					temp=temp->nxt;
				}
				cout<<"NULL";
			}
};
int main(){
	Doublelinkedlist s;
	s.insertatEnd(10);
	s.insertatEnd(20);
	s.insertatEnd(40);
	s.insertatEnd(80);

	s.display();
	return 0;
}
