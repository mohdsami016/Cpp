#include<iostream>
using namespace std;
int main(){
	int a[6]={3,2,7,9,1,5};
	int n=6;
	for(int i=1;i<n;i++){
	
	int key=a[i];
	int j=i-1;
	while((j>=0)&&(a[j]>key)){
		
		a[j+1]=a[j];
		j=j-1;
	}
	a[j+1]=key;
    }
    for(int i=0;i<n;i++)
    {
    	cout<<a[i];
	}
	return 0;
}
