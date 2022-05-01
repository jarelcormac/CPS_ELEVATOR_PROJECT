///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 29 APR 2022
// Filename: elevator.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining properties and prototyping methods of class elevator.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#ifndef CPS_ELEVATOR_PROJECT_ELEVATOR_H
#define CPS_ELEVATOR_PROJECT_ELEVATOR_H

#include "person.h"
#include "node.h"


/****************************************************
 *
 * ELEVATOR CLASS
 *
 ***************************************************/

class Elevator {
private:
    //====== PRIVATE VARIABLES ======//
    std::vector<struct Location> pickUpBuffer;  // This buffer stores how many people are currently waiting to be
                                                      // picked up at some node location.
    std::vector<struct Location> dropOffBuffer; // This buffer stores how many people are currently waiting to be
                                                      // dropped off at some node location.
    std::vector<class Person> peopleInside;   // This vector stores the people within the elevator itself.

    //====== PRIVATE METHODS ======//


public:
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

    //====== PUBLIC VARIABLES ======//
    struct Location location;
    bool btnPressed[3][3];
    bool doorsOpen;

    //====== PUBLIC METHODS ======//
    // Default Constructor
    Elevator();

    // Parameterized Elevator Constructor
    Elevator(struct Location loc, bool btnPress[3][3], bool drsOpen = false,
                std::vector<class Person> pplInside = std::vector<class Person>());

    // moveHere()
    // Attempts to move the elevator to any other node within the 3x3 array of nodes as efficiently as possible.
    int moveHere();

    void PickUpBuff_push_back(Node * node);

    void DropOffBuff_push_back(Node * node);

    // Overloaded << Method
    friend std::ostream& operator<<(std::ostream &out, const Elevator &elevator);
};

#endif //CPS_ELEVATOR_PROJECT_ELEVATOR_H