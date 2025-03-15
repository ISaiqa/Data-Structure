#include<iostream>

using namespace std;
class Student
{
	private:
		int rollNumber;
		string name;
		double gpa;
	public:
		Student (int rollNumber,string name,double gpa )
		{
			this->rollNumber=rollNumber;
			this->name= name;
			this->gpa=gpa;
		}
		void setRollNo(int rollNo);
		void setName(string name);
		void setGpa(double gpa);
		int getRollNo();
		string getName();
		double getGpa();
	    void display();
			
};
void Student::setRollNo(int rollNo)
{
	this->rollNumber=rollNumber;
}
void Student::setName(string name)
{
	this->name= name;
	
}
void Student::setGpa(double gpa)
{
	this->gpa= gpa;
}
int Student::getRollNo()
{
	return rollNumber;
}
string  Student::getName()
{
	return name;
}
double Student::getGpa()
{
	return gpa;
}
void Student::display()
{
	cout<<"\t STUDENT DETAILS"<<endl;
	cout<<"Roll number\t"<<rollNumber<<endl;
	cout<<"Name\t"<<name<<endl;
}

