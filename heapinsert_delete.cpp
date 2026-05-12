#include<iostream>
using namespace std;
int heap[100]; int size=0;
void insert(int x) {
    int i=size; heap[i]=x; size++;
    while(i>0 && heap[(i-1)/2]<heap[i]) {
        swap(heap[i],heap[(i-1)/2]);
        i=(i-1)/2;
    }
}
void deleteRoot() {
    cout<<"Deleted: "<<heap[0]<<endl;
    heap[0]=heap[size-1]; size--;
    int i=0;
    while(true) {
        int l=2*i+1,r=2*i+2,largest=i;
        if(l<size && heap[l]>heap[largest]) largest=l;
        if(r<size && heap[r]>heap[largest]) largest=r;
        if(largest!=i) {
            swap(heap[i],heap[largest]);
            i=largest;
        } else break;
    }
}
void display() {
    for(int i=0;i<size;i++) cout<<heap[i]<<" ";
}
int main() {
    insert(10); insert(20); insert(5);
    display(); cout<<"\n";
    deleteRoot();
    display();
}

