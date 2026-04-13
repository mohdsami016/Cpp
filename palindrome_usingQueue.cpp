#include<iostream>
using namespace std;

class Queue{
	private:
		int a[100];
		int front,rear;
		public:
			Queue(){
				front=0;
				rear=-1;
			}
			bool isEmpty(){
				return front>rear;
			}
			bool isFull(){
				return rear==99;
			}
			void enqueue(int value){
				if(isFull()){
					cout<<"Queue is full";
					return;
				}
				++rear;
				a[rear]=value;
			}
			void dequeue(){
				if(isEmpty()){
					cout<<"Queue is empty";
					return;
				}
				front++;
			}
			int peek(){
				if(isEmpty()){
					cout<<"Queue is empty";
					return -1;
				}
				return a[front];
			}
			bool ispalindrome(int a[]){
				int temp1=rear;
				int temp2=front;
				while(temp2<=temp1){
					if(a[temp1]==a[temp2]){
						temp2++;
						temp1--;
					}
					else
					return false;
				}
				return true;
			}
			void display(){
				if(isEmpty()){
					cout<<"Queue is empty";
					return;
				}
				cout<<"Queue elements: ";
				for(int i=front;i<=rear;i++){
					cout<<a[i]<<" ";
				}
					if(ispalindrome(a)){
		               cout<<"\nThe given Queue is palindrome";
	                }
	                else
   	                 cout<<"\nIt is not a palindrome";
		 	}
};
int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(2);
	q.enqueue(1);
	q.display();

	return 0;
	
}
