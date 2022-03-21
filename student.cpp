#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

// Set Functions ***************************************
void Student::setStuId(string inStuId) {
    stuId = inStuId;

    return;
}
void Student::setStuFirstName(string inStuFirstName) {
    stuFirstName = inStuFirstName;

    return;
}
void Student::setStuLastName(string inStuLastName) {
    stuLastName = inStuLastName;
}
void Student::setStuEmail(string inStuEmail) {
    stuEmail = inStuEmail;

    return;
}
void Student::setStuAge(unsigned int inStuAge) {
    stuAge = inStuAge;

    return;
}
void Student::setDaysInCourse(int inStuDaysInCourse1, int inStuDaysInCourse2, int inStuDaysInCourse3) {
    int inputDaysArray[3] = { inStuDaysInCourse1, inStuDaysInCourse2, inStuDaysInCourse3 };
    for (int i = 0; i < 3; ++i) {
        daysInCourse[i] = inputDaysArray[i];
    }

    return;
 }


 // Get Functions *******************************************
string Student::getStuId() {
    return this->stuId;
}
string Student::getStuFirstName() const {
    return stuFirstName;
}
string Student::getStuLastName() const {
    return stuLastName;
}
string Student::getStuEmail() const {
    return stuEmail;
}
unsigned int Student::getStuAge() const {
    return stuAge;
}
int* Student::getDaysInCourse() const {
    static int sendDaysInCourse[3] = { 0,0,0 };
    for (int i = 0; i < 3; ++i) {
        sendDaysInCourse[i] = daysInCourse[i];
    }

    return sendDaysInCourse;
}





// Constructor & Big Three Functions *******************

Student::Student(string inStuID, string inStuFirstName, string inStuLastName, string inStuEmail, unsigned int inStuAge, int inStuCourse1, int inStuCourse2, int inStuCourse3) {
    this->setStuId(inStuID);
    this->setStuFirstName(inStuFirstName);
    this->setStuLastName(inStuLastName);
    this->setStuEmail(inStuEmail);
    this->setStuAge(inStuAge);
    this->setDaysInCourse(inStuCourse1, inStuCourse2, inStuCourse3);

    return;
}
Student::~Student() {
    cout << "Time to destroy student: " << this->getStuId() << endl;
    /*
    this->setStuId(" ");
    this->setStuFirstName(" ");
    this->setStuLastName(" ");
    this->setStuEmail(" ");
    this->setStuAge(0);
    this->setDaysInCourse(0, 0, 0);
    */
    //remove or delete the object's pointer
    
    return;
}


// virtual Functions
void Student::print() const {
    cout << "First Name: " << stuFirstName << "\tLast Name: " << stuLastName << "\tAge: " << stuAge << "\tDays in course: (";
    for (int i = 0; i < 3; ++i) {
        if (i < 2) {
            cout << daysInCourse[i] << ", ";
        }
        else {
            cout << daysInCourse[i] << ") ";
        }   
    }

    return;
}


