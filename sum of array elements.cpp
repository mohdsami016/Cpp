#include<iostream>
using namespace std;

int sumarray(int a[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum=a[i]+sum;
	}
	return sum;
}
int main(){
	int a[]={65,87,2,4,56};
	int n=sizeof(a)/sizeof(a[0]);
	
	cout<<"sum of array elements ="<<sumarray(a,n);
	return 0;
}
