//
//  student.cpp
//  Class Roster
//
//  Created by Jason Philpy on 3/8/21.
//  Copyright © 2021 Jason Philpy. All rights reserved.
//

#include "student.h"
#include <string>
#include <iostream>
using namespace std;

// Constructor
Student::Student(string id, string firstName, string lastName, string email,
        int age, std::array<int, 3> daysInCourse, DegreeProgram program) {
    m_studentID = id;
    m_firstName = firstName;
    m_lastName = lastName;
    m_email = email;
    m_age = age;
    m_daysInCourse = daysInCourse;
    m_program = program;
}
Student::Student(const Student &student) {
    m_studentID = student.m_studentID;
    m_firstName = student.m_firstName;
    m_lastName = student.m_lastName;
    m_email = student.m_email;
    m_age = student.m_age;
    m_daysInCourse = student.m_daysInCourse;
    m_program = student.m_program;
}
Student& Student::operator=(const Student& objToCopy) {
   return *this;
}


// Destructor
Student::~Student() {}

// Getters
string Student::getStudentID() {
    return m_studentID;
}
string Student::getFirstName() {
    return m_firstName;
}
string Student::getLastName() {
    return m_lastName;
}
string Student::getEmail() {
    return m_email;
}
int Student::getAge() {
    return m_age;
}
std::array<int, 3> Student::getDaysInCourse() {
    return m_daysInCourse;
}
DegreeProgram Student::getProgram() {
    return m_program;
}

// Setters
void Student::setStudentID(string id) {
    m_studentID = id;
}
void Student::setFirstName(string name) {
    m_firstName = name;
}
void Student::setLastName(string name) {
    m_lastName = name;
}
void Student::setEmail(string email) {
    m_email = email;
}
void Student::setAge(int age) {
    m_age = age;
}
void Student::setDaysInCourse(std::array<int, 3> daysInCourse) {
    m_daysInCourse = daysInCourse;
}
void Student::setProgram(DegreeProgram program) {
    m_program = program;
}

// Functions
void Student::print() {
    cout << getStudentID() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName() << "\tAge: " << getAge() << "\tdaysInCoures: {" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "} Degree Program: " << getProgramAsString() << endl;
}
string Student::getProgramAsString() {
    switch(m_program) {
        case SECURITY:
            return "Security";
        case NETWORK:
            return "Network";
        case SOFTWARE:
            return "Software";
        default:
            return "Software";
    }
}
