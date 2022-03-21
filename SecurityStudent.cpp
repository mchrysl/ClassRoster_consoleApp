#include "student.h"
#include "SecurityStudent.h"
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

int SecurityStudent::getDegreeProgram() const {
	return SECURITY;
}

SecurityStudent::SecurityStudent(const string inStudentID, const string inFirstName, const string inLastName, const string inEmailAddress, const int inAge,
	const int inDaysInCourse1, const int inDaysInCourse2, const int inDaysInCourse3, const Degree inDegreeProgram)
	:Student(inStudentID, inFirstName, inLastName, inEmailAddress, inAge, inDaysInCourse1, inDaysInCourse2, inDaysInCourse3)	// call Student (base class) constructor
{
	degreeProgram = inDegreeProgram;
}

SecurityStudent::~SecurityStudent() {
    cout << "Time to destroy security student: " << this->getStuId() << endl;
    /*
    this->setStuId(" ");
    this->setStuFirstName(" ");
    this->setStuLastName(" ");
    this->setStuEmail(" ");
    this->setStuAge(0);
    this->setDaysInCourse(0, 0, 0);
    */
    //remove or delete the object's pointer
    delete this;
    return;
}

void SecurityStudent::print() const {
	Student::print();
	cout << "Degree Program: Security" << endl;
}