#include<iostream>
using namespace std;

int sumarray(int a[],int n){
	int sum=0;
	for(int i=0;i<n;i++){
		if(a[i]%2!=0){
			sum=sum+a[i];
		}
	}
	return sum;
}
int main(){
	int a[]={65,87,2,4,56};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"sum of odd elements in array ="<<sumarray(a,n);
	return 0;
}
