//
//  roster.hpp
//  Class Roster
//
//  Created by Jason Philpy on 3/8/21.
//  Copyright © 2021 Jason Philpy. All rights reserved.
//

#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class Roster {
public:
    // Constructor
    Roster();
    // Destructor
    ~Roster();

    // Functions
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    // Variables
    Student *classRosterArray[5];

protected:
    // Variables
    int arrayCount;
    

};

#endif /* roster_hpp */
