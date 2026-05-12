#include<iostream>
#include<queue>
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
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp=q.front(); q.pop();
        if(temp->left==NULL) {
            temp->left=create(x);
            return root;
        } else q.push(temp->left);
        if(temp->right==NULL) {
            temp->right=create(x);
            return root;
        } else q.push(temp->right);
    }
    return root;
}
void levelOrder(Node* root) {
    if(root==NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp=q.front(); q.pop();
        cout<<temp->data<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}
int main() {
    Node* root=NULL;
    root=insert(root,1);
    insert(root,2);
    insert(root,3);
    insert(root,4);
    cout<<"Level Order: ";
    levelOrder(root);
}

