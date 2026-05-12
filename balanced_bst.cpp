#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* create(int x) {
    Node* t=new Node();
    t->data=x;
    t->left=t->right=NULL;
    return t;
}
Node* build(int arr[],int l,int r) {
    if(l>r) return NULL;
    int mid=l+(r-l)/2;
    Node* root=create(arr[mid]);
    root->left=build(arr,l,mid-1);
    root->right=build(arr,mid+1,r);
    return root;
}
void inorder(Node* root) {
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    int arr[]={1,2,3,4,5};
    Node* root=build(arr,0,4);
    cout<<"Inorder: ";
    inorder(root);
}

