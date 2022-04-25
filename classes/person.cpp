///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: person.cpp
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Contains implementation of methods defined for the Person class.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "person.h"
#include "elevator.h"

//====== Default Constructor Method Implementation ======//
Person::Person() :
    startLoc(Node::Location()),
    endLoc(Node::Location(B, Second)),
    startTime(0),
    inElevator(false),
    currentNode(nullptr),
    currentElevator(nullptr)
{};

//====== Parameterized Constructor Method Implementation ======//
Person::Person(struct Node::Location startLocation, struct Node::Location endLocation,
       unsigned int stTime, bool inElev, Node * node, Elevator * elevator) :
       startLoc(startLocation),
       endLoc(endLocation),
       startTime(stTime),
       inElevator(inElev),
       currentNode(node),
       currentElevator(elevator)
       {};

//====== callElevator() Method Implementation ======//
// This method will "call" the elevator and set btnCalled at the node it is at to true
void Person::callElevator() {
    currentNode->btnCalled = true;
    currentElevator->PickUpBuff_push_back(startLoc);
};


//====== sendElevator(...) Method Implementation ======//
// Sends elevator data on which node a person wants to travel to into the dropOffBuffer.
// Updates btnPressed status to true if not already done
void Person::sendElevator() {
    currentElevator->btnPressed[endLoc.floor][endLoc.section] = true;
    currentElevator->DropOffBuff_push_back(startLoc);
};

