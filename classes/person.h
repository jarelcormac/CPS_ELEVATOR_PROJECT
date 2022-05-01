///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: person.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining properties and prototyping methods of class person.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CPS_ELEVATOR_PROJECT_PERSON_H
#define CPS_ELEVATOR_PROJECT_PERSON_H

#include "node.h"


class Person {
private:
    //====== PRIVATE VARIABLES ======//
    bool inElevator;
    Node * currentNode;
    Elevator * currentElevator;

public:
    //====== PUBLIC VARIABLES ======//
    Node * startLoc;
    Node * endLoc;
    unsigned int startTime;

    //====== PUBLIC METHODS ======//
    // Default Person Constructor
    Person();

    // Parameterized Person Constructor
    Person(Node * nodeStart, Node * nodeEnd, Elevator * elevator, unsigned int stTime = 0, bool inElev = false);

    // Default Person Destructor
    ~Person();

    void exitedElevator();

    void enteredElevator();

    // callElevator() Method Prototype
    // This method will "call" the elevator by incrementing the count of people waiting at the node where the elevator
    // was called.
    void callElevator();

    // sendElevator() Method Prototype
    void sendElevator(Node * node);

    // Overload << Method Prototype
    friend std::ostream &operator<<(std::ostream &out, Person &person);
};


#endif //CPS_ELEVATOR_PROJECT_PERSON_H