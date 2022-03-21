// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

using namespace std;

// Input Data
const static string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                 "A5,Margaret,Chrysler,mchrysl@wgu.edu,48,6,31,48,SOFTWARE" };
const int stuDataArraySize = 5;

    // E.3. Define the following functions:   (for Roster class)
    // E.3.a. 

    void Roster::add(string studentID, string firstName, string lastName, string emailAddress, unsigned int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram) {
        // sets the instance variables from part D1 and updates the roster
        // E.2.b. Add each student object to the next empty classRosterArray entry
        for (int i = 0; i < 5; ++i) {
            if (classRosterArray[i] == nullptr) {
                if (degreeProgram == NETWORK) {
                    // Create a NetworkStudent Object and add it to the classRosterArray
                    classRosterArray[i] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
                    return;
                }
                else if (degreeProgram == SECURITY) {
                    // Create a SecurityStudent Object and add it to the classRosterArray
                    classRosterArray[i] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
                    return;
                }
                else if (degreeProgram == SOFTWARE) {
                    // Create a SoftwareStudent Object and add it to the classRosterArray
                    classRosterArray[i] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
                    return;
                }
                else {
                    // Not a vaid degree program
                    cout << "Cannot add student " << studentID << " due to an invalid degree program." << endl;
                } //end else
            }//end if nullptr condition loop
            else {
                //Nothing to do here --- DELETE ELSE ???
                //cout << "Try the next place in the array." << endl;
            }

        }// end for loop to find next empty classRosterArray
        cout << "It appears the class (array) is full!" << endl;

        return;
    } 

    // E.3.b. 
    void Roster::remove(string studentID) {
        // removes students from the roster by student ID. If the student ID does not exist, the function printes an error message indicating that the student was not found.
        // find the location of student that matches studentID
        cout << "Made it to remove function" << endl;
        bool studentFound = false;
        for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {       // look through all students in the roster
            cout << "Inside for loop to find the student" << endl;
            if ((classRosterArray[i] != nullptr) && ((classRosterArray[i]->getStuId()) == studentID)) {
                cout << "Student found" << classRosterArray[i]->getStuId() << endl;
                //print that student's information
                studentFound = true;
                cout << "StudentFound is now true" << endl;
                delete classRosterArray[i];     //free up memory
                //clean up array -- fill in the space
                do {
                classRosterArray[i] = classRosterArray[i + 1 ];  //move pointer values until the last array entry...
                i += 1;         //increment counter
                } while ( i < (sizeof(classRosterArray) / sizeof(classRosterArray[i])) - 1 );
                classRosterArray[i] = nullptr;
                cout << "Student deleted & array filled in" << endl;
                return;
            }
         }
        if(studentFound == false) {
            cout << "No student with that ID was found." << endl;
        }

        return;
    }

    // E.3.c. 
    void Roster::printAll() {
        // prints a complete tab-separated list of student data using accessor functions with the provided format:
        //          1 <tab> First Name: John <tab> Last Name: Smith <tab> Age: 20 <tab> daysInCourse: {35, 40, 55} Degree Program: Security. 
        //          The printAll() function should loop through all the students in classRosterArray and call the print() function for each student
        for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {
            if (classRosterArray[i] != nullptr) {
                cout << (i + 1) << "\t";        // Line counter label -- ?? Should the first part printed be number of items printed or the student's ID ??
                classRosterArray[i]->print();    // Print the rest of the student's information -- presuming print() function is the desired accessor function??
            }
        }

        return;
    }

    // E.3.d. 
    void Roster::printDaysInCourse(string studentID) {
        // correctly prints a student's average number of days in the three courses.
        //          The student is identified by the studentID parameter
        int* gotDaysInCourse = nullptr;
        double sumOfDays = 0;
        double averageDays = 0.0;
        // find student
        for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {
            if (classRosterArray[i]->getStuId() == studentID) {
                // Get daysInCourse values, sum then get average and print out the average
                gotDaysInCourse = classRosterArray[i]->getDaysInCourse();
                int s = 0;
                // sum the daysInCourse
                for (; s < 3; ++s) {
                    //cout << "entry" << s << ": " << gotDaysInCourse[s];
                    sumOfDays += (double)gotDaysInCourse[s];
                    //cout << "sum: " << sumOfDays << endl;
                }
                averageDays = sumOfDays / s;
                cout << "Average number of days per course: " << averageDays << endl;
                return;
            }
        }
        

        return;
    }

    // E.3.e. 
    void Roster::printInvalidEmails() {
        // verifies student email addresses and displays all invlid email addresses to the user.
        // Note: a valid email should include an at sign (@), and period ('.'), and should not include a space(' ')

        for (int studentCount = 0; studentCount < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++studentCount) {
            string evalEmail = classRosterArray[studentCount]->getStuEmail();
            //cout << "Email to evaluate: " << evalEmail << endl;   // TEST --- did the email string retrieve okay?
            bool hasAtSign = false;
            bool hasPeriod = false;
            bool hasSpace = false;

            // linear search for desired & undesired features
            for (int i = 0; i < ((int)evalEmail.length()); ++i) {
                if (evalEmail.at(i) == '@') {
                    hasAtSign = true;
                }
                else if (evalEmail.at(i) == '.') {
                    hasPeriod = true;
                }
                if (evalEmail.at(i) == ' ') {
                    hasSpace = true;
                }
            }//end for

            // if it does not have an @, if it does not have a '.', or if it does have a space - print it as invalid
            if ((hasAtSign == false) || (hasPeriod == false) || (hasSpace == true)) {
                // Print invalid email addresses
                cout << "Invalid Email: " << evalEmail << endl;
            }
            //else {
                // TEST --- print valid emails also
            //    cout << "Valid by default: " << evalEmail << endl;
            //}
        }
        return;
    }

    // E.3.f. 
    void Roster::printByDegreeProgram(int degreeProgram) {
        //that prints out student information for a degree program specified by an enumerated type
        for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[i]); ++i) {       // look through all students in the roster
            //cout << "printByDegreeProgram passed argument: " << degreeProgram << " -- " << classRosterArray[i]->getDegreeProgram() << endl;
            if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
                //print that student's information
                classRosterArray[i]->print();
            }
        }

        return;
    }

    Roster::~Roster() {
        for (int i = 0; i < 5; ++i) {
            if (classRosterArray[i] != nullptr) {
                delete classRosterArray[i];
            }
        }
        return;
    }




    // the variable for this class (maybe can't be declared here?)
        //Student* classRosterArray[];
    //******************************************************************************************************************






void main()
{
    //F.Demonstrate the program's required functionality by adding a void main() function to roster.cpp, which will contain the required function calls to achieve the following results:
    // F.1. Print out to the screen, via your application, the course title, the programming language used, your student ID, and your name.
    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 001224428" << endl;
    cout << "Student Name: Margaret Charysler" << endl;


    // F.2. Create an instance of the Roster class called classRoster
    Roster classRoster;

    // F.3. Add each student to classRoster.
    // Start with the input data...
    

    // Variables used in main() to split out tokens
    int firstPosition, commaPosition, commaCount;
    string parseString;
    string inStudentID;
    string inFirstName;
    string inLastName;
    string inEmailAddress;
    unsigned int inAge = 0;
    int inDaysInCourse1 = 0;
    int inDaysInCourse2 = 0;
    int inDaysInCourse3 = 0;
    string tempDegreeString = "";
    Degree inDegreeProgram;



    // E.2. Create a student object for each student in the data table by using the subclasses NewtworkStudent, SecurityStudent, and SoftwareStudent, and populate
    for (int countStudent = 0; countStudent < stuDataArraySize; ++countStudent) {

        // E.2.a. Apply pointer operations when parsing each set of data identified in  the studentData table (??? EMAILED INSTRUCTOR ???)
        parseString = studentData[countStudent];   // copy a string to manipulate

        // Initialize variables to search the string
        firstPosition = 0;
        commaPosition = NULL;
        commaCount = 0;

        commaPosition = parseString.find(',');      // find the first comma - do not specify where to start search

        while ((commaPosition != string::npos) && parseString.at(commaPosition) == ',') {

            switch (commaCount) {
            case 0:
                inStudentID = parseString.substr(firstPosition, (commaPosition - firstPosition));
                break;
            case 1:
                inFirstName = parseString.substr(firstPosition, (commaPosition - firstPosition));
                break;
            case 2:
                inLastName = parseString.substr(firstPosition, (commaPosition - firstPosition));
                break;
            case 3:
                inEmailAddress = parseString.substr(firstPosition, (commaPosition - firstPosition));
                break;
            case 4:
                inAge = stoi((parseString.substr(firstPosition, (commaPosition - firstPosition))), nullptr, 10);
                break;
            case 5:
                inDaysInCourse1 = stoi((parseString.substr(firstPosition, (commaPosition - firstPosition))), nullptr, 10);
                break;
            case 6:
                inDaysInCourse2 = stoi((parseString.substr(firstPosition, (commaPosition - firstPosition))), nullptr, 10);
                break;
            case 7:
                inDaysInCourse3 = stoi((parseString.substr(firstPosition, (commaPosition - firstPosition))), nullptr, 10);
                break;
            default:
                cout << "This would be an error. End of string parsing doesn't fit the logic comparison." << endl;
                break;
            };//switch end

            // update variables for next loop/extraction
            commaCount += 1;
            firstPosition = commaPosition + 1;
            commaPosition = NULL;

            // find the next commaPosition
            commaPosition = parseString.find(',', firstPosition);

        }//while loop end -- parsed all but degree program


        //  Convert string input for tempDegreeString to enum Degree inDegreeProgram value
        tempDegreeString = parseString.substr(firstPosition, (commaPosition - firstPosition));
        if (tempDegreeString == "NETWORK") {
            inDegreeProgram = NETWORK;  
        }
        else if (tempDegreeString == "SECURITY") {
            inDegreeProgram = SECURITY;
        }
        else if (tempDegreeString == "SOFTWARE") {
            inDegreeProgram = SOFTWARE;
        }

        // Call "add" function to add the student to the classRosterArray
        classRoster.add(inStudentID, inFirstName, inLastName, inEmailAddress, inAge, inDaysInCourse1, inDaysInCourse2, inDaysInCourse3, inDegreeProgram);


    }//end for loop for each parsed string

        // F.4. Convert the following pseudo code to complete the resto fthe main() function:
        cout << "Print full roster" << endl;
        classRoster.printAll();
        cout << endl;   // space between for ease of reading
        cout << "Print list of invalid emails" << endl;
        classRoster.printInvalidEmails();
        cout << endl;   // space between for ease of reading
        //loop through classRosterArray and for each element:
        cout << "Print average number of days in course" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "  student ID: " << classRoster.classRosterArray[i]->getStuId() << "  " << endl;
            classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStuId());
        }
        cout << endl;   // space between for ease of reading
        cout << "Print students in software degree program" << endl;
        classRoster.printByDegreeProgram(SOFTWARE);
        cout << endl;   // space between for ease of reading
        cout << "Remove student with ID of A3" << endl;
        classRoster.remove("A3");
        cout << endl;   // space between for ease of reading
        cout << "Try to remove student with ID of A3 again" << endl;
        classRoster.remove("A3");
        cout << "back to main from second remove" << endl;
        //expected: the above line should print a message saying such a student with this ID was not found.
        // F.5. Call the destructor to release the Roster memory
        //delete &classRoster;
        cout << "End of program. Destructor will be called & releases the Student objects." << endl;

    return;
}
//





//***************************************************************************************************************************
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file