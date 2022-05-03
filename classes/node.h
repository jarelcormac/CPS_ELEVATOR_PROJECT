///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: node.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining properties and prototyping methods of class elevator.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/******************************************************************************
 *
 * NODE CLASS
 *
 * Notes: This class defines the properties and methods of a Node when created.
 *
 *        Each node has its own unique ID and the counter that keeps track of
 *        the number of people waiting for the elevator to stop at that node.
 *
 *        Each node keeps track of the immediate nodes on the left, right,
 *        upwards, and downwards (relative to current node).
 *
 *        Each node has an assigned location and a boolean variable indicating
 *        whether or not the button for the node has been pressed.
 *
 ******************************************************************************/


#ifndef CPS_ELEVATOR_PROJECT_NODE_H
#define CPS_ELEVATOR_PROJECT_NODE_H

#include <vector>
#include "../standalone_headers/location.h"


class Elevator;

class Node {
public:
    //====== PUBLIC STRUCTURES (SHARED WITH ELEVATOR CLASS) ======//
    /*
     * <Node Direction Structure>
     */
    struct NodeDirection {
        // Default Constructor.
        NodeDirection(Node *n, Direction d) : node(n), direction(d) {}

        // Data for the struct.
        Node* node;
        enum Direction direction;
    };


/**********************************************************************************************************************
 *********************************************************************************************************************/


    //====== PUBLIC VARIABLES ======//
    std::string id;
    bool elevatorCalled;
    unsigned short int timeCalled;
    unsigned int timeBtnPressed;
    struct Location location;
    Node* upNode;
    Node* downNode;
    Node* leftNode;
    Node* rightNode;
    std::vector<class Person *> peopleAtNode;   // This vector stores the people at the current node


/**********************************************************************************************************************
 *********************************************************************************************************************/


    //====== PUBLIC METHODS ======//
    /*
     * <Default Node Constructor>
     *      Constructs a node object based on implementation found in node.cpp.
     */
    Node();

    /*
     * <Parameterized Node Constructor>
     *      Constructs a node object based on user's input arguments.
     */
    Node(std::string ID, struct Location loc,
         Node *up = nullptr, Node *down = nullptr, Node *left = nullptr, Node *right = nullptr,
         bool buttonCalled = false);

    /*
     * <isElevatorHere() Method Prototype>
     *      Checks to see if the elevator resides in the current node this method is called at.
     */
    bool isElevatorHere(Elevator * elevator) const;

    /*
     * <nearbyNodes() Method Prototype>
     *      Lists the nodes immediately upwards, downwards, left, and right of the current node
     */
    std::vector<NodeDirection> nearbyNodes();

    /*
     * <addNode(...) Method>
     *      Adds a node in the required direction relative to the current node.
     */
    int addNode(Node* node, enum Direction direction);

    /*
     * <addNode(...) Method>
     *      This version of addNode(...) completed the same goal as the previous addNode(...) method
     *       in a different manner.
     *      This is just to offer some versatility and ease of programming in case one method does not work.
     */
    int addNode(NodeDirection nodeDirect);

    /*
     * <callElevator() Method>
     *      This method will call the Elevator by pressing the node button.
     */
    void callElevator();


    /*
     * <Overloaded << Method>
     *      This prints out the current node instance's status.
     */
    friend std::ostream& operator<<(std::ostream &out, const Node &node);
};



#endif //CPS_ELEVATOR_PROJECT_NODE_H