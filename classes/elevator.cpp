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

//====== Default Constructor Method Implementation ======//
Elevator::Elevator() {
    for(auto & i : btnPressed)
        for(bool & j : i)
            j = false;
    doorsOpen = false;
    peopleInside = std::vector<class Person>();
    location.section = A;
    location.floor = First;
}

//====== Parameterized Constructor Method Implementation ======//
Elevator::Elevator(Node * nodeCurr, bool btnPress[3][3], bool drsOpen,
                   std::vector<class Person> pplInside) {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) btnPressed[i][j] = btnPress[i][j];
    }
    currentNode = nodeCurr;
    doorsOpen = drsOpen;
    peopleInside = std::move(pplInside);
    location.section = nodeCurr->location.section;
    location.floor = nodeCurr->location.floor;
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
    else if(currentNode->location.floor != Third) {
        currentNode = currentNode->upNode;
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
    else if(currentNode->location.floor != First) {
        currentNode = currentNode->downNode;

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
    else if(currentNode->location.section != A) {
        currentNode = currentNode->leftNode;
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
    else if(currentNode->location.section != C) {
        currentNode = currentNode->rightNode;
        return 1;
    } else return 0;
}

//====== moveHere() Method Implementation ======//
int Elevator::moveHere() {
    return 0;
}

void Elevator::nodeBtnBuff_push_back(Node * node){
    nodeBtnBuffer.push_back(node->location);
}

void Elevator::elevBtnBuff_push_back(Node * node){
    elevBtnBuffer.push_back(node->location);
}

//unsigned short int Elevator::getTime(){
//    return currentTime;
//}

//void Elevator::incrementTime(){
//    currentTime++;
//}

//====== Overloaded << Implementation ======//
std::ostream &operator<<(std::ostream &out, const Elevator &elevator) {
    out
        << "\t\tElevator Location: " << elevator.currentNode->location << std::endl
        << "\t\tElevator Doors: " << (elevator.doorsOpen ? ("Opened"):("Closed")) << std::endl
        << "\t\tCurrent Time: " << Elevator::getTime() << std::endl;
    return out;
}