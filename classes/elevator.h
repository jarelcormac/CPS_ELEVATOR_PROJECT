///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 10 APR 2022
// Filename: elevator.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining properties and prototyping methods of class Person.
//              The Elevator class is in charge of bookkeeping patrons (both at every node and inside the elevator),
//               finding the best path to take within the node system, picking-up and dropping-off passengers at the
//               correct locations they want to go to, and updating buffers used in both the class itself and other
//               classes that require them.
//              Basically, this class is our baby.
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


/******************************************************************************
 *
 * ELEVATOR CLASS
 *
 * Notes: The elevator class is the main brain of the entire system.
 *
 *        It is able to calculate its own path around the 3x3 node system
 *         utilizing the node button and elevator button buffers. The path-
 *         finding algorithm is based on a FIFO queue algorithm. The
 *         algorithm is designed to be robust,
 *
 *        The elevator is also capable of moving person entities that exist
 *         at a node into the elevator itself, move them around the node
 *         system, and properly drop them off where the patrons need to go.
 *
 ******************************************************************************/

class Elevator {
private:
    //====== PRIVATE VARIABLES ======//
    static unsigned short int currentTime;
    static std::vector<struct Location> nodeBtnBuffer;  // This buffer stores the order in which node buttons were pushed
    std::vector<struct Location> elevBtnBuffer; // This buffer stores the order in which elevator buttons were pushed
    std::vector<class Person *> peopleInside;   // This vector stores the people within the elevator itself
    Node * currentNode;


/**********************************************************************************************************************
 *********************************************************************************************************************/


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


/**********************************************************************************************************************
 *********************************************************************************************************************/


public:
    //====== PUBLIC STATIC METHODS ======//
    /*
     * <initializeCurrentTime() Method>
     *      Function initializes the current time for the elevator since the system tests started.
     */
    static void initializeCurrentTime() {
        currentTime = 0;
    }

    /*
     * <getTime() Method>
     *      Function returns the current time of the elevator.
     */
    static unsigned short int getTime() {
        return currentTime;
    }

    /*
     * <incrementTime()>
     *      Function increments the current time of the elevator.
     */
    static void incrementTime() {
        currentTime++;
    }


/**********************************************************************************************************************
 *********************************************************************************************************************/


    //====== PUBLIC VARIABLES ======//
    struct Location location;
    bool btnPressed[3][3]; // This array simulates the actual buttons inside the elevator that patrons may press.
    bool doorsOpen;


    //====== PUBLIC METHODS ======//
    /*
     * <Elevator Default Constructor>
     *      Constructs an elevator object based on implementation found in elevator.cpp.
     */
    Elevator();

    /*
     * <Elevator Parameterized Constructor>
     *      Constructs an elevator object based on user's input arguments.
     */
    Elevator(Node * nodeCurr, bool btnPress[3][3], bool drsOpen = false,
                std::vector<class Person*> pplInside = std::vector<class Person*>());

    /*
     * <Elevator Destructor Method>
     *      This will completely obliterate the poor pointer pointing to the elevator object in memory.
     */
    ~Elevator();

    /*
     * <moveHere(...) Method>
     *      This right here is the big brain plays of the elevator.
     *      It is in charge of finding out the quickest path to take within the node grid system based on the
     *       elevator's calculated next destination.
     *      At each node hop, it also can determine if a person/people need to get dropped-off or picked-up at the
     *       current node, even if the current node is not the elevator's calculated destination node.
     */
    int moveHere(Node * node);

    /*
     * <dropOff() Method>
     *      This is a pretty thick piece of code that drops off the patron (or multiple patrons) at their destination
     *       node, on top of updating the node button and elevator button buffers if required.
     */
    void dropOff();

    /*
     * <pickUp() Method>
     *      This algorithm will move the elevator from the current node to the next destination node using the Elevator Button
     *       Buffer to determine in which order of nodes should the elevator travel.
     *      This algorithm will have an issue where it will not know the previous location it was at and may back
     *       track to a node where it has already proven to be a dead end.
     *      One way to fix this would be to keep track of the nodes that are definite dead
     *       ends and make note of the nodes that have a branching path it can return to.
     */
    void pickUp();


    /*
     * <nodeBtnBuff_push_back(...) Method>
     *      Called when a patron enters the system and pushes the node's button to call the elevator to their location.
     *      If there are already people who called the elevator, their node position will be inserted at the very end
     *       of the vector.
     *      Duplicate calls (meaning multiple button presses) will not add the node position to the vector buffer again,
     *       ensuring that the elevator will go to whatever node called it first.
     *      The buffer can essentially be thought of as a FIFO queue.
     */
    static void nodeBtnBuff_push_back(Node * node);

    /* <elevBtnBuff_push_back(...) Method>
     *      Called when a patron presses a button inside the elevator to indicate to the elevator where their
     *       destination is.
     *      Similar to the nodeBtnBuff_push_back method, it is also a FIFO queue and restricts duplicate calls to
     *       send the elevator to a node if that elevator is already being sent to that node.
     */
    void elevBtnBuff_push_back(Node * Node);

    /*
     * <sendElevator() Method>
     *      Acknowledges that an elevator button has been pressed and turns the value of the btnPressed array to
     *       false.
     */
    void sendElevator(__gnu_cxx::__normal_iterator<Person **, std::vector<Person *>> obj);

    /*
     * <getCurrentNode() Method>
     *      Returns the current node in which the elevator resides. Doi.
     */
    Node * getCurrentNode();

    /*
     * printSystem(...) Method
     *      Prints out the current state of the elevator system to the console via 2D representation.
     */
    void printSystem(Node nodeArray[3][3], Floor floor, Section section);

    /*
     * <Overloaded << Method>
     */
    friend std::ostream& operator<<(std::ostream &out, const Elevator &elevator);
};

#endif //CPS_ELEVATOR_PROJECT_ELEVATOR_H