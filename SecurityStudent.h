#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"
#include "degree.h"

class SecurityStudent :public Student {
public:
	virtual int getDegreeProgram() const;

	SecurityStudent(const string inStudentID, const string inFirstName, const string inLastName, const string inEmailAddress, const int inAge,
		const int inDaysInCourse1, const int inDaysInCourse2, const int inDaysInCourse3, const Degree inDegreeProgram);

	~SecurityStudent();

	virtual void print() const;

private:
	Degree degreeProgram;
};

#endif
