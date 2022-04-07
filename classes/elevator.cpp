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
    occupancy = 0;
    location.section = A;
    location.floor = First;
}

//====== Parameterized Constructor Method Implementation ======//
Elevator::Elevator(struct Node::Location* x1, bool* x2[3][3], bool x3, unsigned int x4) {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) btnPressed[i][j] = x2[i][j];
    }
    doorsOpen = x3;
    occupancy = x4;
    location.section = x1->section;
    location.floor = x1->floor;
}

int Elevator::openDoors() {
    return 0;
}

int Elevator::closeDoors() {
    return 0;
}

int Elevator::moveUp() {
    return 0;
}

int Elevator::moveDown() {
    return 0;
}

int Elevator::moveLeft() {
    return 0;
}

int Elevator::moveRight() {
    return 0;
}

int Elevator::moveHere() {
    return 0;
}
