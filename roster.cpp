#include "roster.h"
#include <iomanip>

using namespace std;

Roster::Roster() {}

void Roster::Parse(string studentData) {
    // Get student ID
     int comma;
    int start;
    comma =  studentData.find(",");
    string sID  =  studentData.substr(0, comma);
    start = comma + 1;
    

    //finding first name
    comma = studentData.find(",", comma + 1);
    string sFName = studentData.substr(start,comma-start);
    start = comma + 1;
   

    //finding last name
    comma = studentData.find(",", comma + 1);
    string sLName = studentData.substr(start,comma - start);
    start = comma + 1;

    //finding email
    comma = studentData.find(",", comma + 1);
    string sEmail = studentData.substr(start,comma - start);
    start = comma + 1;

    // finding age
    comma = studentData.find(",", comma + 1);
    string yrO = studentData.substr(start,comma - start);
    int sAge = stoi(yrO);
    start = comma + 1;


    // finding course  days
    comma = studentData.find(",", comma + 1);
    string cDays1 = studentData.substr(start,comma - start);
    int courseDays1 = stoi(cDays1);
    start = comma + 1;

    comma = studentData.find(",", comma + 1);
    string cDays2 = studentData.substr(start,comma - start);
    int courseDays2 = stoi(cDays2);
    start = comma + 1;

    comma = studentData.find(",", comma + 1);
    string cdays3 = studentData.substr(start,comma - start);
    int courseDays3 = stoi(cdays3);
    start = comma + 1;

    //finding degree program
    comma = studentData.find(",", comma + 1);
    string dp = studentData.substr(start,comma - start);

    //finding degree rpogram
    DegreeProgram dProgram;
    if (dp == "SECURITY") {
		dProgram = SECURITY;
	}
    else if (dp == "NETWORK") {
		dProgram = NETWORK;
	}

	else {
		dProgram = SOFTWARE;
	}

this->add(sID, sFName, sLName, sEmail, sAge, courseDays1, courseDays2, courseDays3, dProgram);
}

void Roster::add(string studentID, string firstName, 
                 string lastName, string emailAddress, int age, 
                 int courseDay1, int courseDay2, int courseDay3, DegreeProgram degreeProgram) {

    // Place days in course into array needed for student object
    int daysArray[3] = {courseDay1, courseDay2, courseDay3};

    // Create new student object and add them to next spot in array
    
    classRosterArray[++studentArrayNum] = new Student(studentID, firstName, 
                                                    lastName, emailAddress, age, daysArray, degreeProgram);

}

void Roster::remove(string studentID) {
    bool deleted = false;
        for (int i = 0; i <= studentArrayNum; ++i) {
            string findID = classRosterArray[i]->getID();

            // Check for student with corresponding ID in roster
            if (findID == studentID) {
                for(int j=i; j < studentArrayNum; ++j) {
                    classRosterArray[j] = classRosterArray[j + 1];
                }
                --studentArrayNum;
                deleted = true;}
        
   }
         if (deleted){
            cout << "The student with ID " << studentID << " has been removed" << endl << endl;
       }
       else { 
        cout <<"Student with " << studentID << " not  found." << endl << endl;}

}

void Roster::printAll() {
    cout << "STUDENT ROSTER: " << endl;
    for (int i = 0; i <= studentArrayNum; ++i) {
        classRosterArray[i]->print();
        }
}


void Roster::printAverageCourseDays(string studentID) {
    float avgDays;
    int sum;
  
  for (int i = 0; i <= studentArrayNum; ++i) {
        string findID = classRosterArray[i]->getID();
        int k = i;
        if(findID == studentID){
            cout << "The average days of courses left "<< studentID<< " is: ";
        for(int i = 0; i <= 4; ++i){
            sum += classRosterArray[k]->getDays()[i];
        }
        avgDays = sum / 3.0;
        cout << fixed << setprecision(2) << avgDays << endl;
        }
        
        }
}

void Roster::printInvalidEmails() {
    cout << "INVALID STUDENT EMAILS:" << endl;

    for (int i = 0; i <= studentArrayNum; i++) {
        string findEmail = classRosterArray[i]->getEmail();
        if ( findEmail.find('@') == string::npos || findEmail.find('.') == string::npos || findEmail.find(' ') != string::npos ) {
            
            cout << findEmail << endl;  
    }
        
    }
cout << "A valid email should include an at sign ('@') and period ('.') and should not include a space (' ')." << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "ALL STUDENTS IN " << degreeProgramArray[degreeProgram] << " DEGREE PROGRAM:" << endl;

    for (int i = 0; i <= studentArrayNum ; i++) {
        if (classRosterArray[i]->getDegree() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}


string Roster::getStudentID(int num) const {
    return classRosterArray[num]->getID();
}

Roster::~Roster() {
    cout << "DESTRUCTOR" << endl;

    for (int i = 0; i < stdsNum - 1; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

Roster::Roster(const Roster& origRoster) {
    for (int i = 0; i < stdsNum; ++i) {
        classRosterArray[i] = new Student;
        *classRosterArray[i] = *(origRoster.classRosterArray[i]);
    }
}

Roster& Roster::operator=(const Roster& objToCopy) {
    if (this != &objToCopy) {
        for (int i = 0; i < stdsNum; ++i) {
            delete classRosterArray[i];
            classRosterArray[i] = new Student;
            *classRosterArray[i] = *(objToCopy.classRosterArray[i]);
        }
    }
    return *this;
}
