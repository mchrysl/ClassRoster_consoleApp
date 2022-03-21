#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"
#include "degree.h"

class NetworkStudent:public Student {
public:
	NetworkStudent(const string inStudentID, const string inFirstName, const string inLastName, const string inEmailAddress, const int inAge,
		const int inDaysInCourse1, const int inDaysInCourse2, const int inDaysInCourse3, const Degree inDegreeProgram);

	~NetworkStudent();

	void print();

	virtual int getDegreeProgram() const;

	virtual void print() const;

private:
	Degree degreeProgram;
};

#endif