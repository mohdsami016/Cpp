#include<iostream>
using namespace std;
class Student{
private:
int sub1,sub2,sub3;
public:
Student(int s1,int s2,int s3){
sub1=s1;
sub2=s2;
sub3=s3;
}
float average(){
return(sub1+sub2+sub3)/3.0;
}
float percentage(){
return((sub1+sub2+sub3)/300.0)*100;
}
void display(){
cout<<"Average:"<<average()<<endl;
cout<<"Percentage:"<<percentage()<<"%"<<endl;
cout<<"\n"<<endl;
}
};
int main(){
Student s1(80,75,90),s2(60,70,65),s3(88,92,85);
s1.display();
s2.display();
s3.display();
return 0;
}
