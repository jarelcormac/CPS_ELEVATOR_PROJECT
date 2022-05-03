///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 10 APR 2022
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

/*
 * Initializing static variables.
 */
unsigned short int Elevator::currentTime = 0;
std::vector<struct Location> Elevator::nodeBtnBuffer = std::vector<struct Location>();
std::vector<struct Location> Elevator::elevBtnBuffer = std::vector<struct Location>();


//====== Default Constructor Method Implementation ======//
Elevator::Elevator() {
    for(auto & i : btnPressed)
        for(bool & j : i)
            j = false;
    doorsOpen = false;
    peopleInside = std::vector<class Person*>();
    location.section = A;
    location.floor = First;
    for(int i = 0; i <= 2; i ++) {
        for (int j = 0; j < 2; ++j) {
            nodeArray[i][j] = Node();
        }
    }
}

//====== Parameterized Constructor Method Implementation ======//
Elevator::Elevator(Node * nodeCurr, bool btnPress[3][3], Node nodeArr[3][3], bool drsOpen,
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
    for(int i = 0; i <= 2; i ++) {
        for (int j = 0; j < 2; ++j) {
            nodeArray[i][j] = nodeArr[i][j];
        }
    }
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
int Elevator::moveUp() {
    // Check if elevator doors are open.
    if(doorsOpen) {
        std::cout << "************** DANGER: ELEVATOR DOORS ARE OPEN - WILL NOT MOVE. **************" << std::endl;
        return 0;
    }
    // Else, change the elevator's current node to the node directly upwards of the elevator's current position.
    else if(currentNode->location.floor != Third && currentNode->upNode != nullptr) {
        currentNode = currentNode->upNode;
        // If the elevator is not empty, check to see if there are any people inside that need to be dropped off
        // at the current node.
        if(!currentNode->peopleAtNode.empty()) {
            pickUp();
        }
        // If the elevator itself is not empty, then check if there is any one that needs to get dropped off.
        if(!peopleInside.empty()) {
            for(auto person = peopleInside.end() - 1;
                !peopleInside.empty() && person != peopleInside.begin() - 1;
                person--) {
                if ((*person)->endLoc == currentNode) {
                    dropOff();
                    break;
                }
            }
        }
        return 1;
    } else return 0;
}

//====== moveDown() Method Implementation ======//
int Elevator::moveDown() {
    // Check if elevator doors are open.
    if(doorsOpen) {
        std::cout << "************** DANGER: ELEVATOR DOORS ARE OPEN - WILL NOT MOVE. **************" << std::endl;
        return 0;
    }
    // Else, change the elevator's current node to the node directly upwards of the elevator's current position.
    else if(currentNode->location.floor != First && currentNode->downNode != nullptr) {
        currentNode = currentNode->downNode;
        // If the elevator is not empty, check to see if there are any people inside that need to be dropped off
        // at the current node.
        if(!currentNode->peopleAtNode.empty()) {
            pickUp();
        }
        // If the elevator itself is not empty, then check if there is any one that needs to get dropped off.
        if(!peopleInside.empty()) {
            for(auto person = peopleInside.end() - 1;
                !peopleInside.empty() && person != peopleInside.begin() - 1;
                person--) {
                if ((*person)->endLoc == currentNode) {
                    dropOff();
                    break;
                }
            }
        }
        return 1;
    } else return 0;
}

//====== moveLeft() Method Implementation ======//
int Elevator::moveLeft() {
    // Check if elevator doors are open.
    if(doorsOpen) {
        std::cout << "************** DANGER: ELEVATOR DOORS ARE OPEN - WILL NOT MOVE. **************" << std::endl;
        return 0;
    }
    // Else, change the elevator's current node to the node directly upwards of the elevator's current position.
    else if(currentNode->location.section != A && currentNode->leftNode != nullptr) {
        currentNode = currentNode->leftNode;
        // If the elevator is not empty, check to see if there are any people inside that need to be dropped off
        // at the current node.
        if(!currentNode->peopleAtNode.empty()) {
            pickUp();
        }
        // If the elevator itself is not empty, then check if there is any one that needs to get dropped off.
        if(!peopleInside.empty()) {
            for(auto person = peopleInside.end() - 1;
                !peopleInside.empty() && person != peopleInside.begin() - 1;
                person--) {
                if ((*person)->endLoc == currentNode) {
                    dropOff();
                    break;
                }
            }
        }
        return 1;
    } else return 0;
}

//====== moveRight() Method Implementation ======//
int Elevator::moveRight() {
    // Check if elevator doors are open.
    if(doorsOpen) {
        std::cout << "************** DANGER: ELEVATOR DOORS ARE OPEN - WILL NOT MOVE. **************" << std::endl;
        return 0;
    }
    // Else, change the elevator's current node to the node directly upwards of the elevator's current position.
    else if(currentNode->location.section != C && currentNode->rightNode != nullptr) {
        currentNode = currentNode->rightNode;
        // If the elevator is not empty, check to see if there are any people inside that need to be dropped off
        // at the current node.
        if(!currentNode->peopleAtNode.empty()) {
            pickUp();
        }
        // If the elevator itself is not empty, then check if there is any one that needs to get dropped off.
        if(!peopleInside.empty()) {
            for(auto person = peopleInside.end() - 1;
                !peopleInside.empty() && person != peopleInside.begin() - 1;
                person--) {
                if ((*person)->endLoc == currentNode) {
                    dropOff();
                    break;
                }
            }
        }
        return 1;
    } else return 0;
}

//====== moveHere() Method Implementation ======//
int Elevator::moveHere(Location loc) {
    // nearbyNodes is necessary to take the correct path when there isn't a direct link to the destination.
    std::vector<Node::NodeDirection> nearbyNodes;

    // Loops until the elevator reaches its calculated destination node.
    for(;;) {
        // Checks if destination node's floor is higher than current node's floor.
        if (loc.floor < currentNode->location.floor) {
            if (!moveUp()) { // If so, attempt to move up.
                nearbyNodes = currentNode->nearbyNodes(); // Checks for nearby nodes if unsuccessful.
                if (nearbyNodes.size() == 1) {
                    switch (nearbyNodes[0].direction) {
                        case Up:    moveUp();       continue;
                        case Down:  moveDown();     continue;
                        case Left:  moveLeft();     continue;
                        case Right: moveRight();    continue;
                    }
                }
                for (auto nodeDirec: nearbyNodes) {
                    if (abs(nodeDirec.node->location.section - loc.section) <
                        abs(nodeDirec.node->location.section - currentNode->location.section)) {

                    }
                }
            }
        }
        // Checks if destination node's floor is lower than current node's floor.
        else if (loc.floor > currentNode->location.floor) {
            if (!moveDown()) { // If so, attempt to move down
                nearbyNodes = currentNode->nearbyNodes(); // Checks for nearby nodes if unsuccessful.
                if (nearbyNodes.size() == 1) {
                    switch (nearbyNodes[0].direction) {
                        case Up:    moveUp();       continue;
                        case Down:  moveDown();     continue;
                        case Left:  moveLeft();     continue;
                        case Right: moveRight();    continue;
                    }
                }
                for (auto nodeDirec: nearbyNodes) {
                    if (abs(nodeDirec.node->location.section - loc.section) <
                        abs(nodeDirec.node->location.section - currentNode->location.section)) {

                    }
                }
            }
        }
        // Else, this means the destination node is on the same floor as the current node.
        else {
            // Checks if destination node's section is left of current node's section.
            if (loc.section < currentNode->location.section) {
                if (!moveLeft()) { // If so, attempt to move left.
                    nearbyNodes = currentNode->nearbyNodes(); // Checks for nearby nodes if unsuccessful.
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
            // Checks if destination node's section is right of current node's section.
            else if (loc.section > currentNode->location.section) {
                if (!moveRight()) { // If so, attempt to move right
                    nearbyNodes = currentNode->nearbyNodes(); // Checks for nearby nodes if unsuccessful.
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
                printSystem();
                return 1; // Successfully reached destination.
            }
        }
    }
    return 0; // if unsuccessful
}


//====== dropOff() Method Implementation ======//
void Elevator::dropOff() {
    Elevator::openDoors();
    /*
     * Deletes any people who have reached their destination.
     * They're getting off the elevator. Duh.
     */
    for(auto person = peopleInside.end() - 1;
        !peopleInside.empty() && person != peopleInside.begin() - 1;
        person--) {
        if ((*person)->endLoc == currentNode) {
            (*person)->exitedElevator();
            (*person)->droppedOff = true;
            peopleInside.erase(person);
        }
    }

    /*
     * Updates the node buffer by scanning the vector buffer and removing the location from the vector if there's a
     *  match between one of the elements of the buffer and the current location of the elevator.
     * This one took a while to be honest.
     */
    for(auto loc = begin(nodeBtnBuffer);
        !nodeBtnBuffer.empty() && loc != end(nodeBtnBuffer); loc++) {
        if(*loc == currentNode->location) {
            nodeBtnBuffer.erase(loc);
        }
    }

    /*
     * Updates the elevator buffer by scanning the vector buffer and removing the location from the vector if there's a
     *  match between one of the elements of the buffer and the current location of the elevator.
     * Also updates btnPressed to be false at the location where the patrons were dropped off.
     * Basically, we turned off one of the LED lights for a button in the elevator letting it know that this
     *  destination was reached, and it should move on.
     */
    for(auto loc = end(elevBtnBuffer) - 1;
        !elevBtnBuffer.empty() && loc != begin(elevBtnBuffer) - 1; loc--) {
        if(currentNode->location == *loc && btnPressed[loc->floor][loc->section]) {
            btnPressed[loc->floor][loc->section] = false;
            elevBtnBuffer.erase(loc);
        }
    }
    closeDoors();
}

//====== pickUp() Method Implementation ======//
void Elevator::pickUp() {
    openDoors();
    // Check if there are people waiting at the node the elevator is at.
    if(!currentNode->peopleAtNode.empty()) {
        for(auto loc = begin(nodeBtnBuffer);
            !nodeBtnBuffer.empty() && loc < end(nodeBtnBuffer); loc++) {
            if(*loc == currentNode->location) {
                nodeBtnBuffer.erase(loc);
            }
        }
        auto temp = peopleInside.size();
        bool existsFlag = false;
        // Move all people waiting at node into the elevator.
        peopleInside.insert(peopleInside.end(), std::make_move_iterator(currentNode->peopleAtNode.begin()), std::make_move_iterator(currentNode->peopleAtNode.end()));
        /*
         * This checks if the people who just entered the elevator already have a destination node in the node button
         *  buffer.
         * Effectively, this means that it checks if the button for each person's end location has already been pushed
         *  to prevent duplicate nodes that the elevator needs to travel to from being added to the buffer.
         * This one had me running for my money.
         */
        for(auto person = peopleInside.begin() + temp;
            person != peopleInside.end();
            person++) {
            (*person)->enteredElevator();
            // Check if elevBtnBuffer is empty; if so, add the current person's end location to buffer.
            if(elevBtnBuffer.empty()) {
                btnPressed[(*person)->endLoc->location.floor][(*person)->endLoc->location.section] = true;
                elevBtnBuff_push_back((*person)->endLoc);
            }
            /*
             * Else, if the buffer is empty, check if any elevator buttons that a new person needs to go to is already in the buffer;
             * If not, add it to the buffer and move on with your day.
             */
            else {
                for(const auto loc : elevBtnBuffer) {
                    if(loc == (*person)->endLoc->location) {
                        existsFlag = true;
                        break;
                    }
                }
                if(!existsFlag) {
                    const auto currentPerson = person;
                    sendElevator(currentPerson);
                }
            }
        }
        /*
         * Resets the number of people at the node, indicating that the node is now empty, and no one is waiting
         * at the node.
         */
        currentNode->peopleAtNode.erase(currentNode->peopleAtNode.begin(), currentNode->peopleAtNode.end());
        nodeArray[currentNode->location.floor][currentNode->location.section].peopleAtNode.clear();
    }
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
//
//void Elevator::incrementTime(){
//    currentTime++;
//}



//====== sendElevator() Method Implementation ======//
void Elevator::sendElevator(__gnu_cxx::__normal_iterator<Person **, std::vector<Person *>> obj) {
    btnPressed[(*obj)->endLoc->location.floor][(*obj)->endLoc->location.section] = true;
    elevBtnBuff_push_back((*obj)->endLoc);
}


//====== Overloaded << Method Implementation ======//
std::ostream &operator<<(std::ostream &out, const Elevator &elevator) {
    out
        << "\tElevator Location: " << elevator.currentNode->location << std::endl
        << "\tElevator Doors: " << (elevator.doorsOpen ? ("Opened"):("Closed")) << std::endl;
    return out;
}

//====== getCurrentNode() Implementation ======//
Node * Elevator::getCurrentNode(){
    return currentNode;
}

//====== getNodeBtnBufferFirst() Implementation ======//
Location Elevator::getNodeBtnBufferFirst() {
    return nodeBtnBuffer.at(0);
}

//====== nodeButtonBufferEmpty() Implementation ======//
bool Elevator::nodeButtonBufferEmpty() {
    return nodeBtnBuffer.empty();
}

//====== nodeButtonBufferEmpty() Implementation ======//
bool Elevator::elevatorButtonBufferEmpty() {
    return elevBtnBuffer.empty();
}

//====== nextButtonBuffer() Implementation ======//
Location Elevator::nextBufferLocation() {
    if(!elevBtnBuffer.empty()) return elevBtnBuffer[0];
    else if(!nodeBtnBuffer.empty()) return nodeBtnBuffer[0];
    return {A, First};
}

//====== nextButtonBuffer() Implementation ======//
Location Elevator::getNodeBtnBuffer() {
    return nodeBtnBuffer.at(1);
}

//====== printSystem(...) Method Implementation ======//
void Elevator::printSystem() {
    Floor floor = currentNode->location.floor;
    Section section = currentNode->location.section;
    std::cout << std::endl
              << "  3A=====3B=====3C"   << std::endl
              << "[ " << std::setw(2) << ((floor == Third && section == A) ? "{}" :
                                          std::to_string(nodeArray[Third][A].peopleAtNode.size())) << " ] "
              << "[ " << std::setw(2) <<  ((floor == Third && section == B) ? "{}" :
                                           std::to_string(nodeArray[Third][B].peopleAtNode.size())) << " ] "
              << "[ " << std::setw(2) << ((floor == Third && section == C) ? "{}" :
                                          std::to_string(nodeArray[Third][C].peopleAtNode.size())) << " ] "  << std::endl
              << "         ||"   << std::endl
              << "  2A=====2B=====2C"   << std::endl
              << "[ " << std::setw(2) << ((floor == Second && section == A) ? "{}" :
                                          std::to_string(nodeArray[Second][A].peopleAtNode.size())) << " ] "
              << "[ " << std::setw(2) << ((floor == Second && section == B) ? "{}" :
                                          std::to_string(nodeArray[Second][B].peopleAtNode.size())) << " ] "
              << "[ " << std::setw(2) << ((floor == Second && section == C) ? "{}" :
                                          std::to_string(nodeArray[Second][C].peopleAtNode.size())) << " ] "  << std::endl
              << "         ||"   << std::endl
              << "  1A=====1B=====1C"   << std::endl
              << "[ " << std::setw(2) << ((floor == First && section == A) ? "{}" :
                                          std::to_string(nodeArray[First][A].peopleAtNode.size())) << " ] "
              << "[ " << std::setw(2) << ((floor == First && section == B) ? "{}" :
                                          std::to_string(nodeArray[First][B].peopleAtNode.size())) << " ] "
              << "[ " << std::setw(2) << ((floor == First && section == C) ? "{}" :
                                          std::to_string(nodeArray[First][C].peopleAtNode.size())) << " ] "  << std::endl
              << std::endl;
}


