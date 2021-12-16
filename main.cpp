//
//  main.cpp
//  Class Roster
//
//  Created by Jason Philpy on 3/8/21.
//  Copyright © 2021 Jason Philpy. All rights reserved.
//

#include <iostream>
#include <array>
#include "student.h"
#include "roster.h"
using namespace std;

int main() {
    cout << "Scripting and Programming - Applications – C867 C++ #001467497 Jason Philpy" << endl;
    Roster classRoster;
    classRoster.printAll();
    classRoster.printInvalidEmails();
    for (Student *student : classRoster.classRosterArray) {
        classRoster.printAverageDaysInCourse(student->getStudentID());
    }
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
}
