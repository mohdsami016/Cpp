#include<iostream>
#include<stack>
using namespace std;

bool areEqual(stack<int>S1,stack<int>S2){
    if (S1.size()!=S2.size()){
        return false;
    }
    while(!S1.empty()){
        if 0(S1.top()!= S2.top()){
            return false;
        }
        S1.pop();
        S2.pop();
    }
    return true;
}

int main() {
    stack<int>S1,S2;
    S1.push(10);
    S1.push(60);
    S1.push(80);

    S2.push(10);
    S2.push(60);
    S2.push(8);

    if(areEqual(S1, S2)) {
        cout << "Both are equal";
    } else{
        cout << "Both are not equal";
    }
    return 0;
}

