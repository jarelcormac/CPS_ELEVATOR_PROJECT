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

unsigned short int Elevator::currentTime = 0;
std::vector<struct Location> Elevator::nodeBtnBuffer = std::vector<struct Location>();

//====== Default Constructor Method Implementation ======//
Elevator::Elevator() {
    for(auto & i : btnPressed)
        for(bool & j : i)
            j = false;
    doorsOpen = false;
    peopleInside = std::vector<class Person*>();
    location.section = A;
    location.floor = First;
}

//====== Parameterized Constructor Method Implementation ======//
Elevator::Elevator(Node * nodeCurr, bool btnPress[3][3], bool drsOpen,
                   std::vector<class Person*> pplInside) {
    for(int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            btnPressed[i][j] = btnPress[i][j];
        }
    }
    currentNode = nodeCurr;
    doorsOpen = drsOpen;
    peopleInside = std::move(pplInside);
    location.section = nodeCurr->location.section;
    location.floor = nodeCurr->location.floor;
}

//====== Default Destructor() Method Implementation ======//
Elevator::~Elevator() {
    std::cout << "Elevator Destroyed. " << std::endl;
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
    else if(currentNode->location.floor != Third && currentNode->upNode != nullptr) {
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
    else if(currentNode->location.floor != First && currentNode->downNode != nullptr) {
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
    else if(currentNode->location.section != A && currentNode->leftNode != nullptr) {
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
    else if(currentNode->location.section != C && currentNode->rightNode != nullptr) {
        currentNode = currentNode->rightNode;
        return 1;
    } else return 0;
}

//====== moveHere() Method Implementation ======//
/*
 * This algorithm will have an issue where it will not know the previous locations
 * it was at and may back track to a node where it has already proven to be a dead
 * end.
 * One way to fix this would be to keep track of the nodes that are definite dead
 * ends and make note of the nodes that have a branching path it can return to.
*/
int Elevator::moveHere(Node * node) {
    // nearbyNodes is necessary to take the correct path when there isn't a direct
    // link to the destination.
    std::vector<Node::NodeDirection> nearbyNodes;

    for(;;) {
        // Checks if destination node's floor is higher than current node's floor
        if (node->location.floor < currentNode->location.floor) {
            if (!moveUp()) { // If so, attempt to move up
                nearbyNodes = node->nearbyNodes(); // check for nearby nodes if unsuccessful
                if (nearbyNodes.size() == 1) {
                    switch (nearbyNodes[0].direction) {
                        case Up:    moveUp();       continue;
                        case Down:  moveDown();     continue;
                        case Left:  moveLeft();     continue;
                        case Right: moveRight();    continue;
                    }
                }
                for (auto nodeDirec: nearbyNodes) {
                    if (abs(nodeDirec.node->location.section - node->location.section) <
                        abs(nodeDirec.node->location.section - currentNode->location.section)) {

                    }
                }
            }
        }
            // Checks if destination node's floor is lower than current node's floor
        else if (node->location.floor > currentNode->location.floor) {
            if (!moveDown()) { // If so, attempt to move down
                nearbyNodes = node->nearbyNodes(); // check for nearby nodes if unsuccessful
                if (nearbyNodes.size() == 1) {
                    switch (nearbyNodes[0].direction) {
                        case Up:    moveUp();       continue;
                        case Down:  moveDown();     continue;
                        case Left:  moveLeft();     continue;
                        case Right: moveRight();    continue;
                    }
                }
                for (auto nodeDirec: nearbyNodes) {
                    if (abs(nodeDirec.node->location.section - node->location.section) <
                        abs(nodeDirec.node->location.section - currentNode->location.section)) {

                    }
                }
            }
        }
            // This means destination node is on the same floor as the current node.
        else {
            // Checks if destination node's section is left of current node's section
            if (node->location.section < currentNode->location.section) {
                if (!moveLeft()) { // If so, attempt to move left
                    nearbyNodes = node->nearbyNodes(); // check for nearby nodes if unsuccessful
                    if (nearbyNodes.size() == 1) {
                        switch (nearbyNodes[0].direction) {
                            case Up:    moveUp();       continue;
                            case Down:  moveDown();     continue;
                            case Left:  moveLeft();     continue;
                            case Right: moveRight();    continue;
                        }
                    }
                }
            }
                // Checks if destination node's section is right of current node's section
            else if (node->location.section > currentNode->location.section) {
                if (!moveRight()) { // If so, attempt to move right
                    nearbyNodes = node->nearbyNodes(); // check for nearby nodes if unsuccessful
                    if (nearbyNodes.size() == 1) {
                        switch (nearbyNodes[0].direction) {
                            case Up:    moveUp();       continue;
                            case Down:  moveDown();     continue;
                            case Left:  moveLeft();     continue;
                            case Right: moveRight();    continue;
                        }
                    }
                }
            }
                // This means the destination node is both on the same floor and same section as the current node.
                // TL;DR: The destination was reached.
            else {
                std::cout << "-Destination Reached-" << std::endl;
                Elevator::pickUp();
                Elevator::dropOff();
                return 1; // successfully reached destination
            }
        }
    }
    return 0; // if unsuccessful
}

void updateNodeBtnBuffer(Elevator * elevator) {

}

//====== dropOff() Method Implementation ======//
void Elevator::dropOff() {
    Elevator::openDoors();
    // Deletes any people who have reached their destination; they're getting off the elevator
    std::vector<class Person *> temp;
    unsigned int count = peopleInside.size() - 1;
    for(auto person = peopleInside.end() - 1;
        !peopleInside.empty() && person != peopleInside.begin() - 1;
        person--, count--) {
        if ((*person)->endLoc == currentNode) {
            //temp.insert(temp.end(), std::make_move_iterator(peopleInside.at(count)), std::make_move_iterator(peopleInside.at(count)));
            (*person)->exitedElevator();
            peopleInside.erase(person);
        }
//        count++;
    }
//    for(auto p : temp){
//        peopleInside.erase(temp);
//    }

    // Update the node button buffer
    for(auto node = begin(nodeBtnBuffer);
        !nodeBtnBuffer.empty() && node != end(nodeBtnBuffer); node++) {
        if(*node == currentNode->location) {
            nodeBtnBuffer.erase(node);
        }
    }

    // Update the elevator button buffer
    for(auto loc = begin(elevBtnBuffer);
        !elevBtnBuffer.empty() && loc != end(elevBtnBuffer); loc++) {
        if(currentNode->location == *loc && btnPressed[loc->floor][loc->section]) {
            btnPressed[loc->floor][loc->section] = false;
            elevBtnBuffer.erase(loc);
        }
    }

    std::cout << "Elevator Button Buffer AFTER DROP OFF: " << std::endl;
    if(elevBtnBuffer.empty()) std::cout << "Buffer is empty" << std::endl;
    else for(auto i : elevBtnBuffer) std::cout << i << std::endl;
    Elevator::closeDoors();
}

//====== pickUp() Method Implementation ======//
void Elevator::pickUp() {
    Elevator::openDoors();
    // Moves all the people at the current node into the elevator
    if(!currentNode->peopleAtNode.empty()) {
        auto temp = peopleInside.size();
        bool existsFlag = false;
        // Move all people waiting at node into the elevator
        peopleInside.insert(peopleInside.end(), std::make_move_iterator(currentNode->peopleAtNode.begin()), std::make_move_iterator(currentNode->peopleAtNode.end()));
        for(auto person = peopleInside.begin() + temp;
            person != peopleInside.end();
            person++) {
            (*person)->enteredElevator();
            // Check if elevBtnBuffer is empty; if so, add the current person's end location to buffer.
            if(elevBtnBuffer.empty()) {
                btnPressed[(*person)->endLoc->location.floor][(*person)->endLoc->location.section] = true;
                elevBtnBuff_push_back((*person)->endLoc);
            }
            // Else, if the buffer is empty, check if any elevator buttons that a person needs to go to is already in the buffer;
            // If not, add
            else {
                for(const auto loc : elevBtnBuffer) {
                    if(loc == (*person)->endLoc->location) {
                        existsFlag = true;
                        break;
                    }
                }
                if(!existsFlag) {
                    btnPressed[(*person)->endLoc->location.floor][(*person)->endLoc->location.section] = true;
                    elevBtnBuff_push_back((*person)->endLoc);
                }
            }
        }
        currentNode->peopleAtNode.erase(currentNode->peopleAtNode.begin(), currentNode->peopleAtNode.end());
    }
    std::cout << "Elevator Button Buffer AFTER PICK UP: " << std::endl;
    if(elevBtnBuffer.empty()) std::cout << "Buffer is empty" << std::endl;
    else for(auto i : elevBtnBuffer) std::cout << i << std::endl;
    Elevator::closeDoors();
}

//====== nodeBtnBuff_push_back(...) Method Implementation ======//
void Elevator::nodeBtnBuff_push_back(Node * node){
    nodeBtnBuffer.push_back(node->location);
}

//====== elevBtnBuff_push_back(...) Method Implementation ======//
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
        << "\tElevator Location: " << elevator.currentNode->location << std::endl
        << "\tElevator Doors: " << (elevator.doorsOpen ? ("Opened"):("Closed")) << std::endl
        << "\tCurrent Time: " << Elevator::getTime() << std::endl;
    return out;
}