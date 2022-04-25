///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: elevator.cpp
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Contains implementation of methods defined for the Elevator class.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "elevator.h"

//====== Default Constructor Method Implementation ======//
Elevator::Elevator() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) btnPressed[i][j] = false;
    }
    doorsOpen = false;
    peopleInside = std::vector<class Person>();
    location.section = A;
    location.floor = First;
}

//====== Parameterized Constructor Method Implementation ======//
Elevator::Elevator(struct Node::Location* loc, bool* btnPress[3][3], bool drsOpen,
                            std::vector<class Person> pplInside) {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) btnPressed[i][j] = btnPress[i][j];
    }
    doorsOpen = drsOpen;
    peopleInside = pplInside;
    location.section = loc->section;
    location.floor = loc->floor;
}

int Elevator::openDoors() {
    try{
        doorsOpen = true;
    }
    catch(std::exception){
        return -1; // Unsuccessful opening of doors
    }
    return 0;
}

int Elevator::closeDoors() {
    try{
        doorsOpen = false;
    }
    catch(std::exception){
        return -1; // Unsuccessful opening of doors
    }
    return 0;
}

int Elevator::moveUp() {
    location.floor = (Floor)(location.floor - 1); // minus 1 because floors work
                                        // oppositely from vertical arrays in C++
    return 0;
}

int Elevator::moveDown() {
    location.floor = (Floor)(location.floor + 1); // plus 1 because floors work
                                        // oppositely from vertical arrays in C++
    return 0;
}

int Elevator::moveLeft() {
    location.section = (Section)(location.section - 1);
    return 0;
}

int Elevator::moveRight() {
    location.section = (Section)(location.section + 1);
    return 0;
}

int Elevator::moveHere() {
    return 0;
}

void Elevator::PickUpBuff_push_back(Node::Location loc){
    pickUpBuffer.push_back(loc);
}

void Elevator::DropOffBuff_push_back(Node::Location loc){
    dropOffBuffer.push_back(loc);
}