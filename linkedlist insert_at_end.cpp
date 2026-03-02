#include<iostream>
using namespace std;
struct node{
int data;
node*next;
};
node*head=NULL;
void insertAtEnd(int x){
node*newnode=new node;
newnode->data=x;
newnode->next=NULL;
if(head==NULL){
head=newnode;
}
else{
node*temp=head;
while(temp->next!=NULL){
temp=temp->next;
}
temp->next=newnode;
}
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
cin>>n;
for(int i=0;i<n;i++){
cin>>x;
insertAtEnd(x);
}
display();
return 0;
}
