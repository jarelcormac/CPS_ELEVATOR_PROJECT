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
//#include "elevator.h"

class Elevator; // Forward declares Elevator so the compiler knows what it is without causing a circular dependency.

class Person {
public:
    //====== PUBLIC VARIABLES ======//
    struct Node::Location startLoc;
    struct Node::Location endLoc;
    unsigned int startTime;
    bool inElevator;
    Node * currentNode;
    Elevator * currentElevator;

    //====== PUBLIC METHODS ======//
    // Default Person Constructor
    Person();

    // Parameterized Person Constructor
    Person(struct Node::Location startLocation, struct Node::Location endLocation,
           unsigned int stTime, bool inElev, Node * node, Elevator * elevator);

    // callElevator() Method Prototype
    // This method will "call" the elevator by incrementing the count of people waiting at the node where the elevator
    // was called.
    void callElevator();

    // sendElevator() Method Prototype
    void sendElevator();

private:
    //====== PRIVATE VARIABLES ======//

};


#endif //CPS_ELEVATOR_PROJECT_PERSON_H
