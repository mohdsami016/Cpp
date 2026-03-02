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
		void insert(int value)
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
	    void Reverse_half_LinkedList(int size)
	    {
	    	node* prev=NULL;
	    	node* current=head;
	    	node* next=NULL;
	    	int count=0;
	    	int mid=size/2;
	    
	    	while(current!=NULL&&count<mid)
	    	{
	    		next=current->next;
	    		current->next=prev;
	    		prev=current;
	    		current=next;
	    		count++;
			}
			if(head!=NULL)
			{
				head->next=current;
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
	int n;
	cout<<"Enter the size :\n";
	cin>>n;
	int value;
	cout<<"enter values of list\n";
	for(int i=0;i<n;i++){
		cin>>value;
		list.insert(value);
	}
	cout<<"Original list :";
	list.dispaly();
	list.Reverse_half_LinkedList(n);
	cout<<"\nReverse list :";
	
	list.dispaly();
	return 0;
}
