#include<iostream>
using namespace std;

class stackinterface{
	public:
		virtual void pop()=0;
		virtual void push(int value)=0;
		virtual int top()=0;
		virtual bool isEmpty()=0;
		virtual bool isFull()=0;
};
class stack:public stackinterface{
	private:
		int* a;
		int topind;
		int size;
		public:
			stack(){
				topind=-1;
				a=NULL;
				size=0;
			}
			void getsize(){
				cout<<"Enter size of stack\n";
				cin>>size;
				a= new int[size];
			}
			void push(int value)override{
				if(isFull()){
					cout<<"\nStack is full\n";
					return;
				}
				a[++topind]=value;
			}
			void pop()override{
			  if(isEmpty()){
				cout<<"stack is empty\n";
				return;
			  }
			  topind--;
			}
			int top()override{
				if(isEmpty()){
					cout<<"stack is empty\n";
						return -1;
				}
				return a[topind];
			}
			bool isFull()override{
				return (topind>=size-1);
			}
			bool isEmpty()override{
				return (topind<0);
			}
			void display(){
				if(isEmpty()){
					cout<<"stack is empty\n";
					return;
				}
				for(int i=topind;i>=0;i--){
					cout<<a[i]<<" ";
				}
			}
};
int main(){
	stack s1;
	s1.getsize();
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.display();
	s1.pop();
	cout<<"\nstack after poping element: ";
	s1.display();
	s1.top();
	
}
