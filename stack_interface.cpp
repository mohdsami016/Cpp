#include<iostream>
using namespace std;

class ArrayStack{
private:
    int arr[100];
    int top;
public:
    ArrayStack(){top=-1;}
    void push(int x){
        if(isFull()){
            cout<<"Stack Overflow\n";
            return;
        }
        arr[++top]=x;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow\n";
            return;
        }
        top--;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==99;
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty\n";
            return;
        }
        cout<<"Stack elements: ";
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    ArrayStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout<<"Top element: "<<s.peek()<<endl;
    s.pop();
    cout<<"After pop, top element: "<<s.peek()<<endl;
    s.display();
    cout<<"Is stack empty? "<<(s.isEmpty()?"Yes":"No")<<endl;
    cout<<"Is stack full? "<<(s.isFull()?"Yes":"No")<<endl;
    return 0;
}

