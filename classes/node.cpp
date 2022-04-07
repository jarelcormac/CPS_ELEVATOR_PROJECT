///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: node.cpp
// Project Name: CPS_ELEVATOR_PROJECT
// Description:
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "node.h"
#include "elevator.h"


//====== Default Constructor Method Implementation ======//
Node::Node() {
    upNode = nullptr;
    downNode = nullptr;
    leftNode = nullptr;
    rightNode = nullptr;
    id = 0;
    peopleWaiting = 0;
    btnCalled = false;
    location = Location(A,First);
}

//====== Parameterized Constructor Implementation ======//
Node::Node(unsigned int x1, struct Location x2,
           Node *x3, Node *x4, Node *x5, Node *x6,
           unsigned int x7, bool x8) {
    id = x1;
    location.floor = x2.floor;
    location.section = x2.section;
    upNode = x3;
    downNode = x4;
    leftNode = x5;
    rightNode = x6;
    peopleWaiting = x7;
    btnCalled = x8;
}

//====== isElevatorHere(...) Method Implementation ======//
bool Node::isElevatorHere(Elevator * elevator){
    if(elevator->location == this->location) return true;
    else return false;
}

//====== Overloaded << Implementation ======//
std::ostream &operator<<(std::ostream &out, const Node &node) {
    out << "\tUp Node: " << node.upNode << "\n"
        << "\tDown Node: " << node.downNode << "\n"
        << "\tLeft Node: " << node.leftNode << "\n"
        << "\tRight Node: " << node.rightNode << "\n"
        << "\tNode ID: " << node.id << "\n"
        << "\tPeople Waiting At Node: " << node.peopleWaiting << "\n"
        << "\tButton Called At Node: " << node.btnCalled << "\n"
        << "\tFloor Location of Node: " << node.location.floor << "\n"
        << "\tSection Location of Node: " << node.location.section << "\n" << std::endl;
    return out;
}

