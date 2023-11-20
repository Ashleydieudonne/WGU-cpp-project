#include "student.h"
using namespace std;


//All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.

//EMPTY CONSTRUCTOR
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;

    for (int i = 0; i < studentArraySize; ++i) {
        this->cDays[i] = 0;
    }
}

//DEFAULT CONSTRUCTOR
Student::Student(string studentID, string firstName, string lastName, string email, int age, int cDays[], DegreeProgram dp) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;

    for (int j = 0; j < studentArraySize; ++j) {
        this->cDays[j] = cDays[j];
    }
    this->dp = dp;
}

//DESTRUCTOR
Student::~Student() {}

//accessors
string Student::getID() const {  return this->studentID;  }
string Student::getFirstName() const { return this->firstName;  }
string Student::getLastName() const {  return this->lastName;  }
string Student::getEmail() const {  return this->email;  }
int Student::getAge() const {  return this->age;  }
int* Student::getDays() {  return this->cDays;  }
DegreeProgram Student::getDegree() const {  return this->dp;  }

//mutators
void Student::setID(string studentID) {  this->studentID = studentID;  }
void Student::setFirstName(string firstName) {  this->firstName = firstName;  }
void Student::setLastName(string lastName) {  this->lastName = lastName;  }
void Student::setEmail(string email) {  this->email = email;  }
void Student::setAge(int age) {  this->age = age;  }
void Student::setDaysInCourse(int cDays[]) {
    for(int k = 0; k < studentArraySize; ++k) {
        this->cDays[k] = cDays[k];
    }
}
void Student::setDegree(DegreeProgram dprog) {  this->dp = dprog;  }

void Student::print() {
    cout << "Student ID: " << this->getID() << '\t';
    cout << "First Name: " << this->getFirstName() << '\t';
    cout << "Last Name: " << this->getLastName() << '\t';
    cout << "Age: " << this->getAge() << '\t';
    cout << "Days in Course: {";
    for (int i = 0; i < studentArraySize; ++i) {
        if(i == (studentArraySize - 1)) {
            cout << this->getDays()[i] << "}" << '\t';
        }
        else {
            cout << this->getDays()[i] << ", ";
        }
    }
    cout << "Degree Program: " << degreeProgramArray[this->getDegree()] << endl;
}