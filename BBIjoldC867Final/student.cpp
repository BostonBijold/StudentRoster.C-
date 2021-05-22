
#include "student.h"
#include "degree.h"

//getters
// Final instructions D(2a);

string Student::GetStudentID() {
	return StudentID;
}
string Student::GetFirstName()
{
	return FirstName;
}
string Student::GetLastName()
{
	return LastName;
}
string Student::GetEmailAddress() {
	return Email;
}
int Student::GetAge() {
	return Age;
}
int* Student::GetDaysInCourse() {
	return daysInCourse;
}
DegreeProgram Student::GetDegreeProgram() {
	return Program;
}


//setters
// Final instructions D(2b);
void Student::SetStudentID(string IDNumber) {
	StudentID = IDNumber;
	return;
}
void Student::SetFirstName(string FName) {
	FirstName = FName;
	return;
}
void Student::SetLastName(string LName) {
	LastName = LName;
	return;
}
void Student::SetEmailAddress(string EAddress) {
	Email = EAddress;
	return;
}
void Student::SetAge(int Nage) {
	Age = Nage;
	return;
}
void Student::SetDaysInCourse(int* course1) {
	for (int i = 0; i < 3; i++) {  
		daysInCourse[i] = course1[i];
	}
	return;
}
void Student::SetDegreeProgram(DegreeProgram program) {
	Program = program;
	return;
}



// constructor;
// Final insructions D(2d);
Student::Student(string studentid, string firstName, string lastName, string email, int age, int* course1, DegreeProgram degreeprogram) {
	StudentID = studentid;
	FirstName = firstName;
	LastName = lastName;
	Email = email;
	Age = age;
	for (int i = 0; i < 3; i++) {   
		daysInCourse[i] = course1[i];
	}
	Program = degreeprogram;

	return;
}
// never use a mutator in a constructor. use the constructor to directly create a new student. note for me;

// functions
// Final instructions D(2e);
void Student::print()
{
	cout << StudentID << "\t";
	cout << "First Name: " << FirstName << "\t";
	cout << "Last Name: " << LastName << "\t";
	cout << "Email address: " << Email << "\t";
	cout << "Age: " << Age << "\t";
	cout << "daysIncourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t";
	cout << "Degree Program: ";
	switch (Program) {
	case 0: cout << "SECURITY";
		break;
	case 1: cout << "NETWORK";
		break;
	case 2:cout << "SOFTWARE";
		break;
	case 3: cout << "NONE";
		break;
	}
	cout << endl;
}