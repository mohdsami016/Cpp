#include<iostream>
using namespace std;
class Employee{
	public:
		int ID;
		string name;
		int salary;
		int TotalSalary;
		
		void getEmployeeDetails(){
			cout<<"Enter ID:";
			cin>>ID;
			cout<<"\nEnter name:";
			cin>>name;
			cout<<"\nEnter basic salary:";
			cin>>salary;
		}
		void calculateSalary(){
			TotalSalary=salary;
		}
		void DisplayEmployeeDetails(){
			cout<<"Employee details\nID:";
			cout<<ID;
			cout<<"\nname:";
			cout<<name;
			cout<<"\nbasic salary:";
			cout<<salary;
			cout<<"\nTotal salary:";
			cout<<TotalSalary;
		}
};

class Manager: public Employee{
	private:
		int allowance;
	public:
		
		void getManagerDetails(){
			getEmployeeDetails();
			cout<<"Enter allowance:";
			cin>>allowance;
		}
		void calculateSalary(){
			TotalSalary=salary+allowance;
		}
		void DisplayManagerDetails(){
			DisplayEmployeeDetails();
		}
};

int main(){
	Manager m1;
	m1.getManagerDetails();
	m1.calculateSalary();
	m1.DisplayManagerDetails();
	return 0;
}
