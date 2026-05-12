#include<iostream>
using namespace std;
class MaxHeap {
    int arr[100],size;
public:
    MaxHeap(){size=0;}
    void insert(int x) {
        int i=size; arr[i]=x; size++;
        while(i!=0 && arr[(i-1)/2]<arr[i]) {
            swap(arr[i],arr[(i-1)/2]);
            i=(i-1)/2;
        }
    }
    void display() {
        for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    }
};
class MinHeap {
    int arr[100],size;
public:
    MinHeap(){size=0;}
    void insert(int x) {
        int i=size; arr[i]=x; size++;
        while(i!=0 && arr[(i-1)/2]>arr[i]) {
            swap(arr[i],arr[(i-1)/2]);
            i=(i-1)/2;
        }
    }
    void display() {
        for(int i=0;i<size;i++) cout<<arr[i]<<" ";
    }
};
int main() {
    MaxHeap maxH;
    maxH.insert(10); maxH.insert(20); maxH.insert(5);
    cout<<"Max Heap: "; maxH.display(); cout<<"\n";
    MinHeap minH;
    minH.insert(10); minH.insert(20); minH.insert(5);
    cout<<"Min Heap: "; minH.display();
}

