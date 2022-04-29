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
#include "specialExceptions.h"
#include <utility>

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
Elevator::Elevator(struct Node::Location loc, bool btnPress[3][3], bool drsOpen,
                   std::vector<class Person> pplInside) {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) btnPressed[i][j] = btnPress[i][j];
    }
    doorsOpen = drsOpen;
    peopleInside = std::move(pplInside);
    location.section = loc.section;
    location.floor = loc.floor;
}

//====== openDoors() Method Implementation ======//
int Elevator::openDoors() {
    try{
        doorsOpen = true;
    }
    catch(OpenDoorsException &e){
        std::cout << e.what() << std::endl;
        return -1; // Unsuccessful opening of doors
    }
    return 0;
}

//====== closeDoors() Method Implementation ======//
int Elevator::closeDoors() {
    try{
        doorsOpen = false;
    }
    catch(CloseDoorsException &e){
        std::cout << e.what() << std::endl;
        return -1; // Unsuccessful closing of doors
    }
    return 0;
}

//====== moveUp() Method Implementation ======//
/*
 * Attempts to move elevator up by one node.
 * Returns 1 if successful, returns 0 if unsuccessful
 */
int Elevator::moveUp() {
    if(doorsOpen) {
        std::cout << "************** DANGER: ELEVATOR DOORS ARE OPEN - WILL NOT MOVE. **************" << std::endl;
        return 0;
    }
    else if(location.floor != Third) {
        location.floor = (Floor)(location.floor - 1);   // minus 1 because floors work
                                                        // oppositely from vertical arrays in C++
        return 1;
    } else return 0;
}

//====== moveDown() Method Implementation ======//
/*
 * Attempts to move elevator down by one node.
 * Returns 1 if successful, returns 0 if unsuccessful
*/
int Elevator::moveDown() {
    if(doorsOpen) {
        std::cout << "************** DANGER: ELEVATOR DOORS ARE OPEN - WILL NOT MOVE. **************" << std::endl;
        return 0;
    }
    else if(location.floor != First) {
        location.floor = (Floor)(location.floor + 1); // plus 1 because floors work
                                                      // oppositely from vertical arrays in C++
        return 1;
    } else return 0;
}

//====== moveDown() Method Implementation ======//
/*
 * Attempts to move elevator left by one node.
 * Returns 1 if successful, returns 0 if unsuccessful
*/
int Elevator::moveLeft() {
    if(doorsOpen) {
        std::cout << "************** DANGER: ELEVATOR DOORS ARE OPEN - WILL NOT MOVE. **************" << std::endl;
        return 0;
    }
    else if(location.section != A) {
    location.section = (Section)(location.section - 1);
        return 1;
    } else return 0;
}

//====== moveRight() Method Implementation ======//
/*
 * Attempts to move elevator right by one node.
 * Returns 1 if successful, returns 0 if unsuccessful
*/
int Elevator::moveRight() {
    if(doorsOpen) {
        std::cout << "************** DANGER: ELEVATOR DOORS ARE OPEN - WILL NOT MOVE. **************" << std::endl;
        return 0;
    }
    else if(location.section != C) {
        location.section = (Section)(location.section + 1);
        return 1;
    } else return 0;
}

//====== moveHere() Method Implementation ======//
int Elevator::moveHere() {
    return 0;
}

void Elevator::PickUpBuff_push_back(Node::Location loc){
    pickUpBuffer.push_back(loc);
}

void Elevator::DropOffBuff_push_back(Node::Location loc){
    dropOffBuffer.push_back(loc);
}

//====== Overloaded << Implementation ======//
std::ostream &operator<<(std::ostream &out, const Elevator &elevator) {
    out
        << "\tElevator Location: " << elevator.location << std::endl
        << "\t\tElevator Doors: " << (elevator.doorsOpen ? ("Opened"):("Closed")) << std::endl;
    return out;
}