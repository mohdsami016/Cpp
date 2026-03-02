#include<iostream>
using namespace std;
struct node{
int data;
node*next;
};
node*head=NULL;
void createList(int x){
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
void insertAtPosition(int x,int pos){
node*newnode=new node;
newnode->data=x;
if(pos==1){
newnode->next=head;
head=newnode;
}
else{
node*temp=head;
for(int i=1;i<pos-1;i++){
temp=temp->next;
}
newnode->next=temp->next;
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
int n,x,pos,val;
cin>>n;
for(int i=0;i<n;i++){
cin>>x;
createList(x);
}
cin>>pos>>val;
insertAtPosition(val,pos);
display();
return 0;
}
