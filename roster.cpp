//
//  roster.cpp
//  Class Roster
//
//  Created by Jason Philpy on 3/8/21.
//  Copyright © 2021 Jason Philpy. All rights reserved.
//

#include "roster.h"
#include "student.h"
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include <sstream>
using namespace std;


// Constructor
Roster::Roster() {
    arrayCount = 0;
    const string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jason,Philpy,jphilpy@gmail.com,35,20,25,30,SOFTWARE"};
    for (int i=0; i<5; i++) {
        vector<string> dataRow;
        stringstream stringStream(studentData[i]);
        while(stringStream.good()) {
            string data;
            getline(stringStream, data, ',');
            dataRow.push_back(data);
        }

        int age = stoi(dataRow.at(4));
        DegreeProgram program = SOFTWARE;
        if (dataRow.at(8) == "SECURITY") {
            program = SECURITY;
        } else if (dataRow.at(8) == "NETWORK") {
            program = NETWORK;
        }
        add(dataRow.at(0), dataRow.at(1), dataRow.at(2), dataRow.at(3), age, stoi(dataRow.at(5)), stoi(dataRow.at(6)), stoi(dataRow.at(7)), program);
    }

}

// Destructor
Roster::~Roster() {
    int arraySize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
    for(int i = 0; i < arraySize - 1; ++i) {
        delete classRosterArray[i];
    }
}

// Functions
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    std::array<int, 3> daysInCourse = { daysInCourse1, daysInCourse2, daysInCourse3 };
    //Student *student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
    classRosterArray[arrayCount] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeprogram);
    arrayCount++;
}

void Roster::remove(string studentID) {
    int arraySize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
    bool removedItem = false;
    for (int i = 0; i < arraySize; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            removedItem = true;
            int newSize = arraySize - 1;
            if (i < arraySize) {
                for (int j = i; j < newSize; j++) {
                    classRosterArray[j] = classRosterArray[j+1];
                }
            }
            break;
        }
    }
    if (!removedItem) {
        cout << "No student with the ID: '" << studentID << "' was found." << endl;
    }
    
}
void Roster::printAll() {
    for (Student *student : classRosterArray) {
        student->print();
    }

}
void Roster::printAverageDaysInCourse(string studentID) {
    for (Student *student : classRosterArray) {
        if (student->getStudentID() == studentID) {
            double totalDays = 0.0;
            for (int day : student->getDaysInCourse()) {
                totalDays += static_cast<double>(day);
            }
            double averageDays = totalDays / 3.0;
            cout << "Student " << studentID << " has an average of " << averageDays << " days in course." << endl;
            break;
        }
    }
}
void Roster::printInvalidEmails() {
    for (Student *student : classRosterArray) {
        string email = student->getEmail();
        bool isValid = true;
        if (email.find(" ") != std::string::npos) {
            isValid = false;
        }
        if (isValid) {
            bool hasDot = false;
            bool hasAt = false;
            for (auto &ch : email) {
                if (ch == '@') {
                    hasAt = true;
                }
                if (hasAt && ch == '.') {
                    hasDot = true;
                }
            }
            if (!hasDot || !hasAt) {
                isValid = false;
            }
        }
        if (!isValid) {
            cout << "Invalid Email: " << email << endl;
        }
    }
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (Student *student : classRosterArray) {
        if (student->getProgram() == degreeProgram) {
            cout << "Degree Filter: ";
            student->print();
        }
    }
}

