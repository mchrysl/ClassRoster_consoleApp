#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
#include "NetworkStudent.h"
using namespace std;

int NetworkStudent::getDegreeProgram() const {
	return 0;
}

NetworkStudent::NetworkStudent(const string inStudentID, const string inFirstName, const string inLastName, const string inEmailAddress, const int inAge,
	const int inDaysInCourse1, const int inDaysInCourse2, const int inDaysInCourse3, const Degree inDegreeProgram)
	:Student(inStudentID, inFirstName, inLastName, inEmailAddress, inAge, inDaysInCourse1, inDaysInCourse2, inDaysInCourse3)	// call Student (base class) constructor
{
	degreeProgram = inDegreeProgram;
}

NetworkStudent::~NetworkStudent() {
    cout << "Time to destroy the network student: " << this->getStuId() << endl;
    this->setStuId(" ");
    this->setStuFirstName(" ");
    this->setStuLastName(" ");
    this->setStuEmail(" ");
    this->setStuAge(0);
    this->setDaysInCourse(0, 0, 0);
    
    //remove or delete the object's pointer
    delete this;
    return;
}

void NetworkStudent::print() const {
    Student::print();
    cout << "Degree Program: Network" << endl;
}