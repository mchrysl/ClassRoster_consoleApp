#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"
#include "degree.h"

class SoftwareStudent :public Student {
public:

	virtual int getDegreeProgram() const;

	SoftwareStudent(const string inStudentID, const string inFirstName, const string inLastName, const string inEmailAddress, const int inAge,
		const int inDaysInCourse1, const int inDaysInCourse2, const int inDaysInCourse3, const Degree inDegreeProgram);

	~SoftwareStudent();

	virtual void print() const;

private:
	Degree degreeProgram;
};

#endif
