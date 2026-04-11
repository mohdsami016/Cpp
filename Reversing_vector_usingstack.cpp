#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void reverseVector(vector<int> &vec){
	stack<int> st;
	for(int i=0;i<vec.size();i++){
		st.push(vec[i]);
	}
	for(int i=0;i<vec.size();i++){
		vec[i]=st.top();
		st.pop();
	}
}
int main(){
	vector<int> vect;
	vect.push_back(13);
    vect.push_back(12);
    vect.push_back(10);
    vect.push_back(9);
	cout<<"The vector before reversing:";
    for(int i=0; i<vect.size(); i++){
    cout << vect[i] << " ";
    }
	reverseVector(vect);
	cout<<"\nThe reversed vector is:";
    for(int i=0; i<vect.size(); i++){
    cout << vect[i] << " ";
    }
	return 0;
}
