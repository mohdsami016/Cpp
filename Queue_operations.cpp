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
			void display(){
				if(isEmpty()){
					cout<<"Queue is empty";
					return;
				}
				cout<<"Queue elements: ";
				for(int i=front;i<=rear;i++){
					cout<<a[i]<<" ";
				}
			}
};
int main(){
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.display();
	q.dequeue();
	cout<<"\nAfter deleting a element from Queue\n";
	q.display();
	return 0;
	
}
