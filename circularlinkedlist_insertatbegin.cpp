#include<iostream>
using namespace std;
struct node{
	int data;
	node* nxt;
};
class CircularlinkedList{
	private:
	node* head;
	public:
	CircularlinkedList()
	{
		head=NULL;
	}
	void insertatbegin(int value)
	{
		node* newnode=new node();
		newnode->data=value;
		newnode->nxt=NULL;
		if(head==NULL)
		{
			head=newnode;
			newnode->nxt=head;
			return ;
		}
		else
		{
			node* temp=head;
			while(temp->nxt!=head)
			{
				temp=temp->nxt;
			}
			temp->nxt=newnode;
			newnode->nxt=head;
			head=newnode;
		}
	}
	void display()
	{
		node* temp=head;
		do
		{
		 cout<<temp->data<<"->";
		 temp=temp->nxt;
		}while(temp!=head);
		cout<<"HEAD";
	}
};
int main()
{
	CircularlinkedList list;
	list.insertatbegin(10);
    list.insertatbegin(20);
	list.insertatbegin(30);
	list.insertatbegin(40);
	cout<<"list :";
	list.display();
	return 0;
}
