#include <iostream>
#include "roster.h"
using namespace std;

int main() {

    const std::string studentData[] = 
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
        "A5,Ashley,Dieudonne,addiytyv@wgu.edu,23,20,34,40,20,SOFTWARE"};

    cout << " Course title: SCRIPTING AND PROGRAMMING - APPLICATIONS — C867" << " Programming language used: C++" << " WGU student ID: " << " Name: Ashley Dieudonne" << endl <<  endl;
    
    const int studentDataSize = 5;

    Roster classRoster;

    
    for (int i = 0; i < studentDataSize; ++i) {
        classRoster.Parse(studentData[i]);
    }

    classRoster.printAll();
    cout << endl;

    classRoster.printInvalidEmails();
    cout << endl;

    
    for (int i = 0; i < studentDataSize; ++i) {
        string studentID = classRoster.getStudentID(i);
        classRoster.printAverageCourseDays(studentID);
    }
    cout << endl;

    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    classRoster.remove("A3");

    classRoster.printAll();
    cout << endl;

    classRoster.remove("A3");

    return 0;

}