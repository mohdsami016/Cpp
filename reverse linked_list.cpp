#include<iostream>
using namespace std;
struct node{
	int data;
	node* next;
};
class LinkedList{
	private:
	node* head;
	public:
	LinkedList()
	{
		head=NULL;
	}
	void insertatEnd(int value)
	{
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
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newnode;
		}
		}
	    void Reverse_LinkedList()
	    {
	    	node* prev=NULL;
	    	node* current=head;
	    	node* next=NULL;
	    	while(current!=NULL)
	    	{
	    		next=current->next;
	    		current->next=prev;
	    		prev=current;
	    		current=next;
			}
			head=prev;
		}
		void dispaly()
		{
			node* temp=head;
			while(temp!=NULL)
			{
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"NULL";
		}
};
int main()
{
	LinkedList list;
	list.insertatEnd(10);
    list.insertatEnd(20);
	list.insertatEnd(30);
	list.insertatEnd(40);
	cout<<"Original list :";
	list.dispaly();
	cout<<"\nReverse list :";
	list.Reverse_LinkedList();
	list.dispaly();
	return 0;
}
