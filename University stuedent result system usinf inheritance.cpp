#include<iostream>
using namespace std;
class AcademicRecord
{
	protected:
		int rollno;
		int marks;
	public:
		void GetAR(){
			cout<<"Enter roll no :"<<endl;
			cin>>rollno;
			cout<<"Enter marks :"<<endl;
			cin>>marks;
		}
		void displayAR(){
			cout<<"AcademicRecord: \nrollno : "<<rollno;
			cout<<"\nmarks :"<<marks<<endl;
		}
};
class SportsRecord {
	protected :
		string SportName;
		int SportScore;
			
	public:
		void GetSR(){
			cout<<"Enter sport name :"<<endl;
			cin>>SportName;
			cout<<"Enter score in sport :"<<endl;
			cin>>SportScore;
		}
		
		void displaySR(){
			cout<<"SportsRecord: \nSport Name:"<<SportName;
			cout<<"\nScore :"<<SportScore<<endl;
		}
	
		
};
class Student : public AcademicRecord, public SportsRecord{
	public: 
	void read()
	{
		GetAR();
		GetSR();
	}
	void display()
	{
		displayAR();
		displaySR();
	}
	void perfromance(){
		float TP=(SportScore+marks)/2.0;
		cout<<"Total performance:"<<TP;
		
	}
};

int main()
{
	
	Student s1;
	s1.read();
	s1.display();
	s1.perfromance();
	return 0;
}
