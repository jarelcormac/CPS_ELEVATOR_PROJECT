///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 20 APR 2022
// Filename: person.cpp
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Contains implementation of methods defined for the Person class.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/******************************************************************************
 *
 * PERSON CLASS
 *
 * Notes: This class defines the properties and methods of a Node when created.
 *
 *        Each node has its own unique ID and the counter that keeps track of
 *        the number of people waiting for the elevator to stop at that node.
 *
 *        Each node keeps track of the immediate nodes on the left, right,
 *        upwards, and downwards (relative to current node).
 *
 *        Each node has an assigned location and a boolean variable indicating
 *        whether or not the button for the node has been pressed.
 *
 ******************************************************************************/


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
    pickedUp = false;
}

//====== Parameterized Constructor Method Implementation ======//
Person::Person(Node * nodeStart, Node * nodeEnd, Elevator * elevator, unsigned int stTime,
               bool inElev, bool dropOff, bool pickUp) {
    startLoc = nodeStart;
    endLoc = nodeEnd;
    startTime = stTime;
    inElevator = inElev;
    currentNode = nodeStart;
    currentElevator = elevator;
    droppedOff = dropOff;
    pickedUp = pickUp;
    addPersonToNode(nodeStart);
    callElevator();
}

//====== Default Destructor Method Implementation ======//
Person::~Person() {
    std::cout << "Person destroyed. Was in elevator: " << inElevator << std::endl;
}

//====== callElevator() Method Implementation ======//
void Person::callElevator() {
    // If the elevator has already been called, output the following statement.
    if(currentNode->elevatorCalled) {
        std::cout << "Elevator has already been called to Node " << currentNode->id << std::endl;
    }
    // Else, push the node location to the node button buffer and change elevatorCalled for the current node to true.
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
    pickedUp = true;
    inElevator = true;
}

//====== sendElevator(...) Method Implementation ======//
void Person::sendElevator(__gnu_cxx::__normal_iterator<Person **, std::vector<Person *>> obj) {
    currentElevator->btnPressed[endLoc->location.floor][endLoc->location.section] = true;
    currentElevator->elevBtnBuff_push_back(endLoc);
}

//====== addPersonToNode(...) Method Implementation ======//
void Person::addPersonToNode(Node * node) {
    node->peopleAtNode.push_back(this);
    currentElevator->nodeArray[node->location.floor][node->location.section].peopleAtNode.push_back(this);
}

//====== Overloaded << Method Implementation ======//
std::ostream &operator<<(std::ostream &out, Person &person) {
    out
        << "\tPerson's Memory Address: " << &person << std::endl
        << "\tPerson's Start Location: " << person.startLoc->id << std::endl
        << "\tPerson's End Location: " << person.endLoc->id << std::endl
        << "\tPerson In Elevator: " << (person.inElevator ? ("Yes"):("No")) << std::endl
        << "\tPerson Picked Up: " << (person.pickedUp ? ("Yes"):("No")) << std::endl
        << "\tPerson Reached Destination: " << (person.droppedOff ? ("Yes"):("No")) << std::endl;
    return out;
}


