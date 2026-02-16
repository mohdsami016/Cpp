#include<iostream>
using namespace std;

void insertion_sort(int a[],int l){
    for(int j=1;j<l;j++){
        int current=a[j];
        int prev=j-1;
        while(prev>=0&&a[prev]>current){
            a[prev+1]=a[prev];
            prev--;
        }
        a[prev+1]=current;
    }
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    int a[n];
    cout<<"Enter "<<n<<" elements: \n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<"Before sorting:";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    insertion_sort(a,n);

    cout<<"After sorting:";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    return 0;
}
