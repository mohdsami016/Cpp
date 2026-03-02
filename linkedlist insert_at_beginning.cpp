#include<iostream>
using namespace std;
struct node{
int data;
node*next;
};
node*head=NULL;
void insertAtBeginning(int x){
node*newnode=new node;
newnode->data=x;
newnode->next=head;
head=newnode;
}
void display(){
node*temp=head;
while(temp!=NULL){
cout<<temp->data<<" ";
temp=temp->next;
}
}
int main(){
int n,x;
cout<<"enter n value\n";
cin>>n;
for(int i=0;i<n;i++){
cout<<"enter value of nodes\n";
cin>>x;
insertAtBeginning(x);
}
display();
return 0;
}
