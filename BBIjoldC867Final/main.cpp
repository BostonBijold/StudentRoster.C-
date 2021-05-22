#include <sstream>
#include <iostream>
#include <string>
using namespace std;
#include "roster.h"  // Final instructions B. proof of other files added to the main file;
#include "degree.h"   // Final instructions C enumerated data type.

int main() {

	//final requirements print out;
	cout << "Scripting and Programming Applications: C867 using C++" << endl;
	cout << "ID# 001468656 Boston Bijold" << endl;
	cout << endl;

	Roster classRoster;

	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Boston,Bijold,bbijol1@wgu.edu,25,10,12,30,SOFTWARE"  // Final instruction A. my information has been added;

	};
	string studentid;										//Final instructions D. construction of the student class is displayed here;
	string firstname;										//See student.h/student.cpp for the functions of the student class;
	string lastname;
	string email;
	string age;
	string course1;
	string course2;
	string course3;
	string degree;
	DegreeProgram degreeprogram;
	for (int i = 0; i < 5; i++) {
		string input = studentData[i];
		istringstream inSS(input);


		getline(inSS, studentid, ',');
		getline(inSS, firstname, ',');
		getline(inSS, lastname, ',');
		getline(inSS, email, ',');
		getline(inSS, age, ',');
		getline(inSS, course1, ',');
		getline(inSS, course2, ',');
		getline(inSS, course3, ',');
		getline(inSS, degree, ',');
		if (degree == "SECURITY") {
			degreeprogram = SECURITY;
		}
		else if (degree == "NETWORK") {
			degreeprogram = NETWORK;
		}
		else if (degree == "SOFTWARE") {
			degreeprogram = SOFTWARE;
		}
		else {
			degreeprogram = NONE;
		}

		classRoster.Add(studentid, firstname, lastname, email, std::stoi(age), std::stoi(course1), std::stoi(course2), std::stoi(course3), degreeprogram);

	}   // Final instructions E. above shows the construction of the roster class populating the Array;
	// roster is populated according to the final paramiters;


	classRoster.printAll(); // final instructions F 4.1;
	cout << endl;

	classRoster.printInvalidEmails(); // final instructions F 4.2;
	cout << endl;

	
	for (int i = 0; i < 5; i++) {  // begin the loop for final instuctions F 4.3;
		Student* students = classRoster.rosterAccess(i);  // accessor created to access the roster from the main function.
		string studentName = students->GetStudentID();

		classRoster.printAverageDaysInCourse(studentName); // prints the loop of F 4.3;
	}
	cout << endl;

	cout << "Students in the SOFTWARE program: " << endl;
	classRoster.printByDegreeProgram(SOFTWARE);    // final instructions F 4.4;
	cout << endl;

	classRoster.remove("A3"); // final instructions F 4.5;
	cout << endl;

	classRoster.printAll();  // final instuctions F 4.6;
	cout << endl;

	classRoster.remove("A3"); // final instuctions F 4.7 intended to show that the student wasnt found;
	cout << endl;
	
	// final instructions F 5; use a distuctor to release the memory alocated.
	return 0;
};