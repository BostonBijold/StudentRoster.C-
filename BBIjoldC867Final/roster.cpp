
#include <iostream>
#include <string>
#include "roster.h"



Roster::Roster() {

}

void Roster::Add(string studentid, string firstname, string lastname, string email, int age, int course1, int course2, int course3, DegreeProgram degreeprogram) {
	int course[3] = { course1, course2, course3 };
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentid, firstname, lastname, email, age, course, degreeprogram);

			break;
		}

	}
	return;
}


void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
}

void Roster::remove(string studentID) {
	bool removed = false;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			removed = true;
			break;
		}
	}
	if (removed == false) {
		cout << "The student requested to be removed does not exist." << endl;
	}
	return;
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetStudentID() == studentID) {
			int* days = classRosterArray[i]->GetDaysInCourse();
			int course1 = *days;
			int course2 = *(days + 1);
			int course3 = *(days + 2);
			cout << classRosterArray[i]->GetStudentID() << "'s average number of days in each course is ";
			cout << (course1 + course2 + course3) / 3 << " days." << endl;
			break;
		}
	}
	return;
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		string email;
		int periodcount = 0;
		int atcount = 0;
		int spacecount = 0;
		email = classRosterArray[i]->GetEmailAddress();
		for (int j = 0; j < email.length(); j++) {
			if (email[j] == '.') {
				periodcount++;
			}
			if (email[j] == '@') {
				atcount++;
			}
			if (email[j] == ' ') {
				spacecount++;
			}

		}
		if (periodcount == 0 || atcount != 1 || spacecount != 0) {
			cout << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->GetDegreeProgram() == degreeprogram)
			classRosterArray[i]->print();
	}
}

Student* Roster::rosterAccess(int arynum) {   //used to access the Roster to retrive data such as student IDs;
	return classRosterArray[arynum];
}
Roster::~Roster() {
	//cout << "destructor is called.";  // commented out as a test to prove the destructor is called only at the end of the program;
	delete* classRosterArray;
}