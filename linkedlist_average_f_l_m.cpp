#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;
};
class linkedlist{
	private:
		node* head;
	public:
		linkedlist(){
			head=NULL;
		}
		void insertatEnd(int value){
			node* newnode=new node();
			newnode->data=value;
			newnode->next=NULL;
			if(head==NULL)
			{
				head=newnode;
			}
			else
			{
				node* temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=newnode;
			}
		}
		double findavg(){
			if(head==NULL)
				return 0;
				int first=head->data;
				node* temp=head;
				while(temp->next!=NULL){
					temp=temp->next;
				}
				int last=temp->data;
				node* x=head;
				node* y=head;
				while((y!=NULL)&&(y->next!=NULL)){
					x=x->next;
					y=y->next->next;
				}
				int mid=x->data;
					return (first+mid+last)/3.0;
			
		}
};
int main()
{
	linkedlist a;
	a.insertatEnd(10);
	a.insertatEnd(20);
	a.insertatEnd(40);
	a.insertatEnd(30);
	a.insertatEnd(10);
	a.insertatEnd(70);
	cout<<"The average of First,Last,Middle element is :"<<a.findavg();
	return 0;
}
