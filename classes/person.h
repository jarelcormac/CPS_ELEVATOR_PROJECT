///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 20 APR 2022
// Filename: person.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining properties and prototyping methods of class Person.
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
 * Notes: This class defines the properties and methods of class Person.
 *
 *        The class simulates the a patron who can interact with the elevator
 *         system.
 *
 *        The person should be able to push buttons to either call the
 *         elevator to the node they are spawned at or send the elevator to
 *         their destination node by pushing a node button inside the elevator.
 *
 *        Each person is unique and act as different entities which the
 *         elevator may interact with.
 *
 ******************************************************************************/


#ifndef CPS_ELEVATOR_PROJECT_PERSON_H
#define CPS_ELEVATOR_PROJECT_PERSON_H

#include "node.h"


class Person {
private:
    //====== PRIVATE VARIABLES ======//
    bool inElevator;
    Node * currentNode;
    Elevator * currentElevator;


/**********************************************************************************************************************
 *********************************************************************************************************************/


public:
    //====== PUBLIC VARIABLES ======//
    Node * startLoc;
    Node * endLoc;
    bool droppedOff;
    bool pickedUp;
    unsigned int startTime;


/**********************************************************************************************************************
 *********************************************************************************************************************/


    //====== PUBLIC METHODS ======//
    /*
     * <Person Default Constructor>
     *      Constructs an elevator object based on implementation found in person.cpp.
     */
    Person();

    /*
     * <Person Parameterized Constructor>
     *      Constructs an elevator object based on user's input arguments.
     */
    Person(Node * nodeStart, Node * nodeEnd, Elevator * elevator, unsigned int stTime = 0,
           bool inElev = false, bool dropOff = false, bool pickUp = false);

    /*
     * <Elevator Destructor Method>
     *      This will completely obliterate the poor pointer pointing to the person object in memory.
     */
    ~Person();

    /*
     * <exitedElevator() Method>
     *      Sets person's inElevator status to false.
     */
    void exitedElevator();

    /*
     * <exitedElevator() Method>
     *      Sets person's inElevator status to true.
     */
    void enteredElevator();

    /* <callElevator() Method>
     *      This method will "call" the elevator by incrementing the count of people waiting at the node where the elevator
     *       was called.
     */
    void callElevator();

    /* <sendElevator() Method>
     *      Sends elevator data on which node a person wants to travel to into the dropOffBuffer.
     *      Updates btnPressed status to true if not already done.
     */
    void sendElevator(__gnu_cxx::__normal_iterator<Person **, std::vector<Person *>> obj);

    /*
     * <addPersonToNode(...) Method>
     *      Add a person to the node and pushes them onto the peopleAtNode vector buffer to indicate to the elevator
     *       that someone is ready to get picked up.
     *      TL;DR Person pressed the button to call the elevator and is now waiting.
     */
    void addPersonToNode(Node * node);

    // Overload << Method Prototype
    friend std::ostream &operator<<(std::ostream &out, Person &person);
};


#endif //CPS_ELEVATOR_PROJECT_PERSON_H