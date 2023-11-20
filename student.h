#include <string>
#include <iostream>
#include "degree.h"

#pragma once


using std::string;
using std::cout;


class Student {
   public:
    const static int studentArraySize = 3;
    
    //CONSTRUCTORS
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int cDays[], DegreeProgram dp);

    //DESTRUCTOR
    ~Student();

    Student(const Student& someStudent);

    //accessors
    string getID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmail() const;
    int getAge() const;
    int* getDays();
    DegreeProgram getDegree() const;

    //mutators
    void setID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysInCourse(int cDays[]);
    void setDegree(DegreeProgram dprog);

    void print();

   private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int cDays[studentArraySize];
    DegreeProgram dp;
};

/* Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:

•  student ID

•  first name

•   last name

•  email address

•  age

•  array of number of days to complete each course

•  degree program*/