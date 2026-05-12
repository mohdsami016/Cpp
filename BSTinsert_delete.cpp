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
Node* insert(Node* root,int x) {
    if(root==NULL) return create(x);
    if(x<root->data) root->left=insert(root->left,x);
    else if(x>root->data) root->right=insert(root->right,x);
    return root;
}
Node* findMin(Node* root) {
    while(root->left!=NULL) root=root->left;
    return root;
}
Node* deleteNode(Node* root,int key) {
    if(root==NULL) return NULL;
    if(key<root->data) root->left=deleteNode(root->left,key);
    else if(key>root->data) root->right=deleteNode(root->right,key);
    else {
        if(root->left==NULL && root->right==NULL) {
            delete root; return NULL;
        } else if(root->left==NULL) {
            Node* temp=root->right; delete root; return temp;
        } else if(root->right==NULL) {
            Node* temp=root->left; delete root; return temp;
        } else {
            Node* temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}
void inorder(Node* root) {
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main() {
    Node* root=NULL;
    root=insert(root,10);
    insert(root,5);
    insert(root,15);
    root=deleteNode(root,10);
    cout<<"Inorder: ";
    inorder(root);
}

