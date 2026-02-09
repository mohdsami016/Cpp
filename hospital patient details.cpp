#include<iostream>
#include<string.h>
using namespace std;

class Patient{
	private:
		string patientname;
		int patientID;
		int AdmittedDays;
		int costperday;
		int bill;
		public:
			void getpatientdetail(){
				cout<<"Enter patient name"<<endl;
				cin>>patientname;
				cout<<"Enter patient ID"<<endl;
				cin>>patientID;
				cout<<"Enter number of days patient admitted"<<endl;
				cin>>AdmittedDays;
			}
			void calculatebill(){
				cout<<"enter cost per day"<<endl;
				cin>>costperday;
				bill=costperday*AdmittedDays;
			}
			void display(){
				cout<<"\nPatient Details :"<<endl;
				cout<<" Patient Name :"<<patientname<<endl;
				cout<<" Patient ID :"<<patientID<<endl;
				cout<<" Number of days Patient Admitted :"<<AdmittedDays<<endl;
				cout<<"Per Day Cost :"<<costperday;
				cout<<" Total bill :"<<bill<<endl;
			}
};
int main(){
	Patient p1;
	p1.getpatientdetail();
	p1.calculatebill();
	p1.display();
	return 0;
}
