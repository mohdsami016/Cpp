#include<iostream>
using namespace std;

void swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void selectionsort(int a[],int n){
	for(int i=n-1;i>0;i--){
		int maxindex=0;
		for(int j=1;j<=i;j++){
			if(a[maxindex]<a[j]){
				maxindex=j;
			}
		}
		swap(a[maxindex],a[i]);
	}
}
void printarray(int a[],int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	int a[]={65,87,2,4,56};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"original array:"<<endl;
	printarray(a,n);
	selectionsort(a,n);
	cout<<"\nsorted array :"<<endl;
	printarray(a,n);
	return 0;
}
