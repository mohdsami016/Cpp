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
			void insertatbeggining(int value){
				node* newnode=new node();
				newnode->data=value;
				newnode->prev=NULL;
				newnode->nxt=NULL;
				if(head==NULL){
					head=newnode;
					return ;
				}
				newnode->nxt=head;
				head->prev=newnode;
				head=newnode;
			}
			void display(){
				node* temp=head;
				while(temp!=NULL){
					cout<<temp->data<<"->";
					temp=temp->nxt;
				}
				cout<<"NULL";
			}
			void delete_begin(){
				node* temp=head;
				head=head->nxt;
				head->prev=NULL;
				delete temp;
			}
};
int main(){
	Doublelinkedlist s;
	s.insertatbeggining(80);
	s.insertatbeggining(40);
	s.insertatbeggining(20);
	s.insertatbeggining(10);
	s.display();
	s.delete_begin();
	cout<<"\nList after deleted :";
	s.display();
	return 0;
}
