#include<iostream>
using namespace std;
void merge(int a[],int l,int mid, int h){
	int n1=mid-l+1;
	int n2=h-mid;
	
	int left[n1],right[n2];
	for( int i=0;i<n1; i++)
	left[i]=a[l+i];
	for( int j=0;j<n2; j++)
	right[j]=a[mid+1+j];
	
	int i=0,j=0,k=l;
	while(i<n1 && j<n2){
		if(left[i]<=right[j]){
		a[k]=left[i];
		i++;
		}
		else{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		a[k]=left[i];
		i++;
		k++;
	}
	while(j<n2){
		a[k]=right[j];
		j++;
		k++;
	}

}
void mergesort(int a[],int l,int h){ 
	if(l<h){
		
	int mid=l+(h-l)/2;
	mergesort(a,l,mid);
	mergesort(a,mid+1,h);
	
	merge(a,l,mid,h);
	}
}
int main(){
	int n=7,a[7]={21,8,9,3,4,6,1};
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	mergesort(a,0,n-1);
	cout<<"\nSorted array:\n";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";	
	return 0;
}
