#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "Student.h"
#include "NetworkStudent.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include "degree.h"
using namespace std;



class Roster {

public:
	void add(string studentID, string firstName, string lastName, string emailAddress, unsigned int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);

	void remove(string studentID);

	void printAll();

	void printDaysInCourse(string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(int degreeProgram);

	~Roster();

    // E.1. Create an array of pointers, classRosterArray, to hold the data provided in the studentData table
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
   
	
};

#endif	