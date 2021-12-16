//
//  student.hpp
//  Class Roster
//
//  Created by Jason Philpy on 3/8/21.
//  Copyright © 2021 Jason Philpy. All rights reserved.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <string>
#include <array>
#include "degree.h"
using namespace std;

class Student {
public:

    // Constructor
    Student(string id, string firstName, string lastName, string email, int age,
            std::array<int, 3> daysInCourse, DegreeProgram program);
    Student(const Student &student);
    Student& operator=(const Student& objToCopy);
    // Destructor
    ~Student();

    // Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    std::array<int, 3> getDaysInCourse();
    DegreeProgram getProgram();

    // Setters
    void setStudentID(string id);
    void setFirstName(string name);
    void setLastName(string name);
    void setEmail(string email);
    void setAge(int age);
    void setDaysInCourse(std::array<int, 3> daysInCourse);
    void setProgram(DegreeProgram program);
    
    // Functions
    void print();
    string getProgramAsString();
protected:
    // Variables
    string m_studentID;
    string m_firstName;
    string m_lastName;
    string m_email;
    int m_age;
    std::array<int, 3> m_daysInCourse;
    DegreeProgram m_program;
};


#endif /* student_hpp */
