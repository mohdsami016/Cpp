#include<iostream>
using namespace std;

struct node{
	node* nxt;
	int data;
};
class Queue{
	private:
		node* rear;
		public:
			Queue(){
				rear=NULL;
			}
			void enqueue(int value){
				node* newnode=new node();
				newnode->data=value;
				if(rear==NULL){
					rear=newnode;
					newnode->nxt=newnode;
				}
				else{
					newnode->nxt=rear->nxt;
					rear->nxt=newnode;
					rear=newnode;
				}
			}
			void dequeue(){
				if(rear==NULL){
					cout<<"deletion is not posssible";
					return;
				}
				if(rear->nxt==rear){
					delete rear;
					rear=NULL;
					return;
				}
				node* temp=rear->nxt;
				rear->nxt=temp->nxt;
				delete temp;
			}
			void display(){
				if(rear==NULL){
					cout<<"Queue is empty";
					return;
				}
				node* temp=rear->nxt;
				cout<<"Queue:";
				do{
					cout<<temp->data<<"->";
					temp=temp->nxt;
				}while(temp!=rear->nxt);
				cout<<"Front\n";
			}
};
int main(){
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(40);
	q.enqueue(80);
	q.enqueue(160);
	q.display();
	q.dequeue();
	cout<<"Queue after deleting a element:\n";
	q.display();
	return 0;
}
