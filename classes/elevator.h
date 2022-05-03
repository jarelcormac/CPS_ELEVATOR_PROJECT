///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 29 APR 2022
// Filename: elevator.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining properties and prototyping methods of class elevator.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef CPS_ELEVATOR_PROJECT_ELEVATOR_H
#define CPS_ELEVATOR_PROJECT_ELEVATOR_H

#include "person.h"
#include "node.h"
#include <iomanip>


/****************************************************
 *
 * ELEVATOR CLASS
 *
 ***************************************************/

class Elevator {
private:
    //====== PRIVATE VARIABLES ======//
    static unsigned short int currentTime;
    static std::vector<struct Location> nodeBtnBuffer;  // This buffer stores the order in which node buttons were pushed
    std::vector<struct Location> elevBtnBuffer; // This buffer stores the order in which elevator buttons were pushed
    std::vector<class Person *> peopleInside;   // This vector stores the people within the elevator itself
    Node * currentNode;

    //====== PRIVATE METHODS ======//
    // Move elevator one node up
    int moveUp();

    // Move elevator one node down
    int moveDown();

    // Move elevator one node left
    int moveLeft();

    // Move elevator one node right
    int moveRight();

    // Open elevator doors
    int openDoors();

    // Close elevator doors
    int closeDoors();

public:
    //====== PUBLIC STATIC METHODS ======//
    // initializeCurrentTime() Method
    // Initializes current time
    static void initializeCurrentTime() {
        currentTime = 0;
    }

    // getTime() Method
    // Returns current time
    static unsigned short int getTime() {
        return currentTime;
    }

    // incrementTime() Method
    // Increments time by 1 unit
    static void incrementTime() {
        currentTime++;
    }



    //====== PUBLIC VARIABLES ======//
    struct Location location;
    bool btnPressed[3][3]; // The buttons in the elevator
    bool doorsOpen;


    //====== PUBLIC METHODS ======//
    // Default Constructor
    Elevator();

    // Parameterized Elevator Constructor
    Elevator(Node * nodeCurr, bool btnPress[3][3], bool drsOpen = false,
                std::vector<class Person*> pplInside = std::vector<class Person*>());

    // Default Destructor Method
    ~Elevator();

    // moveHere()
    // Attempts to move the elevator to any other node within the 3x3 array of nodes as efficiently as possible.
    int moveHere(Node * node);

    // updateNodeBtnBuffer() Method
    // Updates the nodeBtnBuffer every time a node hop occurs.
    void updateNodeBtnBuffer(Node * node);

    // dropOff() Method
    // Drops off any people at the current node
    void dropOff();

    // pickUp() Method
    void pickUp();

    // nodeBtnBuff_push_back(...) Method
    // Push a node into the nodeBtnBuffer.
    static void nodeBtnBuff_push_back(Node * node);

    // elevBtnBuff_push_back(...) Method
    // Push a node into the elevBtnBuffer.
    void elevBtnBuff_push_back(Node * Node);

    // isNodeBtnBuffEmpty() Method
    // Returns true or false if nodeBtnBuffer vector is empty or not
    static bool isNodeBtnBuffEmpty();

    // sendElevator() Method Prototype
    // Activates the push button in the elevator
    void sendElevator(__gnu_cxx::__normal_iterator<Person **, std::vector<Person *>> obj);

    // getCurrentNode() Method
    // Gets the value of the current node elevator resides in
    Node * getCurrentNode();

    // printSystem(...) Method
    // Prints out the current state of the elevator system.
    void printSystem(Node nodeArray[3][3], Floor floor, Section section);

    // Overloaded << Method
    friend std::ostream& operator<<(std::ostream &out, const Elevator &elevator);
};

#endif //CPS_ELEVATOR_PROJECT_ELEVATOR_H