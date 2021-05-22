#pragma once


#include "student.h"

using namespace std;

class Roster {
public:
	void Add(string studentid, string firstname, string lastname, string email,
		int age, int course1, int course2, int course3, DegreeProgram degreeprogram);
	// Final instructions E(2a&b) after parsing in main the student is created with the add above;

	//Final instructions E(3);
	void printAll();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);
	Student* rosterAccess(int); // to access the Roster for data like student ID;
	Roster();
	// Final instructions E(5) the destuctor;
	~Roster();

private:
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };  //Final instructions E(1);
};