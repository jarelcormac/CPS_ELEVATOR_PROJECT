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
    droppedOff = false;
}

//====== Parameterized Constructor Method Implementation ======//
Person::Person(Node * nodeStart, Node * nodeEnd, Elevator * elevator, unsigned int stTime, bool inElev, bool dropOff) {
    startLoc = nodeStart;
    endLoc = nodeEnd;
    startTime = stTime;
    inElevator = inElev;
    currentNode = nodeStart;
    currentElevator = elevator;
    droppedOff = dropOff;
    addPersonToNode(nodeStart);
}

//====== Default Destructor Method Implementation ======//
Person::~Person() {
    std::cout << "Person destroyed. Was in elevator: " << inElevator << std::endl;
}

//====== callElevator() Method Implementation ======//
// This method will "call" the elevator and set btnCalled at the node it is at to true
void Person::callElevator() {
    if(currentNode->elevatorCalled) {
        std::cout << "Elevator has already been called to Node " << currentNode->id << std::endl;
    }
    else {
        currentNode->elevatorCalled = true;
        Elevator::nodeBtnBuff_push_back(startLoc);
        std::cout << "Elevator has now been called to Node " << currentNode->id << std::endl;
    }
}

//====== exitedElevator() Method Implementation ======//
void Person::exitedElevator() {
    inElevator = false;
}

//====== enteredElevator() Method Implementation ======//
void Person::enteredElevator(){
    inElevator = true;
}

//====== sendElevator(...) Method Implementation ======//
// Sends elevator data on which node a person wants to travel to into the dropOffBuffer.
// Updates btnPressed status to true if not already done
void Person::sendElevator(__gnu_cxx::__normal_iterator<Person **, std::vector<Person *>> obj) {
    currentElevator->btnPressed[endLoc->location.floor][endLoc->location.section] = true;
    currentElevator->elevBtnBuff_push_back(endLoc);
}

//====== addPersonToNode(...) Method Implementation ======//
void Person::addPersonToNode(Node * node) {
    node->peopleAtNode.push_back(this);
}

//====== Overloaded << Method Implementation ======//
std::ostream &operator<<(std::ostream &out, Person &person) {
    out
        << "\tPerson's Mem Addr: " << &person << std::endl
        << "\tPerson's Start Location: " << person.startLoc->id << std::endl
        << "\tPerson's End Location: " << person.endLoc->id << std::endl
        << "\tPerson Picked Up: " << (person.inElevator ? ("Yes"):("No")) << std::endl
        << "\tPerson Reached Destination: " << (person.droppedOff ? ("Yes"):("No")) << std::endl;
    return out;
}




