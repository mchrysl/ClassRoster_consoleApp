#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

// D. For the Student class, do the following
class Student {

public:
	void setStuId(string inStuId);
	void setStuFirstName(string inStuFirstName);
	void setStuLastName(string inStuLastName);
	void setStuEmail(string inStuEmail);
	void setStuAge(unsigned int inStuAge);
	void setDaysInCourse(int inStuCourse1, int inStuCourse2, int inStuCourse3);

	string getStuId();
	string getStuFirstName() const;
	string getStuLastName() const;
	string getStuEmail() const;
	unsigned int getStuAge() const;
	int* getDaysInCourse() const;   // returns a pointer to a static array declared in the function

	
	Student(string inStuID, string inStuFirstName, string inStuLastName, string inStuEmail, unsigned int inStuAge, int inStuCourse1, int inStuCourse2, int inStucourse3);	
	~Student();	// Destructor

	virtual int getDegreeProgram() const = 0;
	virtual void print() const;

private:
	string stuId;
	string stuFirstName;
	string stuLastName;
	string stuEmail;
	unsigned int stuAge;
	int daysInCourse[3];

};

#endif