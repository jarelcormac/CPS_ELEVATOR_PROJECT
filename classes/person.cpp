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
Person::Person() {
    startLoc = nullptr;
    endLoc = nullptr;
    startTime = 0;
    inElevator = false;
    currentNode = nullptr;
    currentElevator = nullptr;
}

//====== Parameterized Constructor Method Implementation ======//
Person::Person(Node * nodeStart, Node * nodeEnd, Elevator * elevator, unsigned int stTime, bool inElev) {
    startLoc = nodeStart;
    endLoc = nodeEnd;
    startTime = stTime;
    inElevator = inElev;
    currentNode = nodeStart;
    currentElevator = elevator;
}

//====== Default Destructor Method Implementation ======//
Person::~Person() {
    std::cout << "this bitch dead, I mean... they \"got off\"" << std::endl;
}

//====== callElevator() Method Implementation ======//
// This method will "call" the elevator and set btnCalled at the node it is at to true
void Person::callElevator() {
    currentNode->elevatorCalled = true;
    currentElevator->nodeBtnBuff_push_back(startLoc);
}


//====== sendElevator(...) Method Implementation ======//
// Sends elevator data on which node a person wants to travel to into the dropOffBuffer.
// Updates btnPressed status to true if not already done
void Person::sendElevator(Node * node) {
    currentElevator->btnPressed[node->location.floor][node->location.section] = true;
    currentElevator->elevBtnBuff_push_back(startLoc);
}

//====== Overloaded << Method Implementation ======//
std::ostream &operator<<(std::ostream &out, Person &person) {
    out
        << "\tPerson's Start Location: " << person.startLoc->id << std::endl
        << "\tPerson's End Location: " << person.endLoc->id << std::endl
        << "\tPerson's Current Location: " << person.currentNode->id << std::endl
        << "\tPerson in Elevator: " << (person.inElevator ? ("Yes"):("No")) << std::endl;
    return out;
}




