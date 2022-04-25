///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: elevator.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining properties and prototyping methods of class elevator.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "node.h"

#ifndef CPS_ELEVATOR_PROJECT_ELEVATOR_H
#define CPS_ELEVATOR_PROJECT_ELEVATOR_H

/****************************************************
 *
 * ELEVATOR CLASS
 *
 ***************************************************/
class Elevator {
private:
    //====== PRIVATE VARIABLES ======//
    std::vector<struct Node::Location> pickUpBuffer;  // This buffer stores how many people are currently waiting to be
                                                      // picked up at some node location.
    std::vector<struct Node::Location> dropOffBuffer; // This buffer stores how many people are currently waiting to be
                                                      // dropped off at some node location.
    std::vector<class Person> peopleInside;   // This vector stores the people within the elevator itself.

    //====== PRIVATE METHODS ======//
    // Move elevator one node up
    int moveUp();

    // Move elevator one node down
    int moveDown();

    // Move elevator one node left
    int moveLeft();

    // Move elevator one node right
    int moveRight();

    // Open elevator doors
    int openDoors();

    // Close elevator doors
    int closeDoors();

public:
    //====== PUBLIC VARIABLES ======//
    struct Node::Location location;
    bool btnPressed[3][3];
    bool doorsOpen;
    unsigned int occupancy;

    //====== PUBLIC METHODS ======//
    // Default Constructor
    Elevator();

    // Parameterized Elevator Constructor
    Elevator(struct Node::Location* loc, bool* btnPress[3][3], bool drsOpen,
                std::vector<class Person> pplInside);

    // moveHere()
    // Attempts to move the elevator to any other node within the 3x3 array of nodes as efficiently as possible.
    int moveHere();
};


#endif //CPS_ELEVATOR_PROJECT_ELEVATOR_H
