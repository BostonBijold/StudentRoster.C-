#pragma once
#ifndef Student_HEADER
#define Student_HEADER

#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
	//getters
	// Final instructions D(2a);
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int* GetDaysInCourse();
	DegreeProgram GetDegreeProgram();

	//setters
	//final instructions D(2b);
	void SetStudentID(string);
	void SetFirstName(string);
	void SetLastName(string);
	void SetEmailAddress(string EAddress);
	void SetAge(int age);
	void SetDaysInCourse(int* course1);
	void SetDegreeProgram(DegreeProgram program);


	//additional functions
	// Final instructions D(2e);
	void print();

	//constructor
	// Final instructions D(2d);
	Student(string, string, string, string, int, int*, DegreeProgram);

	// Final instructions D(1)
private:
	int Age, daysInCourse[3]; 
	string Email, FirstName, LastName, StudentID;
	DegreeProgram Program;
};

#endif