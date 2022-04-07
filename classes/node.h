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

#include <vector>
#include <iostream>
#include "../standalone_headers/enumerations.h"
//#include "elevator.h" // This will create a circular dependency error


#ifndef CPS_ELEVATOR_PROJECT_NODE_H
#define CPS_ELEVATOR_PROJECT_NODE_H


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
class Elevator; // Forward declares Elevator so the compiler knows what it is without causing a circular dependency

class Node {
public:
    //====== PUBLIC STRUCTURES (SHARED WITH ELEVATOR CLASS) ======//
    // Node Direction Structure
    struct NodeDirection {
        NodeDirection(Node *n, Direction d) : node(n), direction(d) {}

        Node* node;
        enum Direction direction;
    };

    // Location Structure
    struct Location {
        enum Section section;
        enum Floor floor;

        // Constructors
        Location():section(A), floor(First){}
        Location(enum Section s, enum Floor f) :section(s), floor(f){}

        // Overloaded == Operator
        bool operator==(Location const &other) const {
            if(floor == other.floor && section == other.section) return true;
            else return false;
        }
    };

private:
    //====== PRIVATE VARIABLES ======//
    Node* upNode;
    Node* downNode;
    Node* leftNode;
    Node* rightNode;
    unsigned int id;
    unsigned int peopleWaiting;

public:
    //====== PUBLIC VARIABLES ======//
    bool btnCalled;
    struct Node::Location location;

    //====== PUBLIC METHODS ======//
    // Default Node Constructor
    Node();

    // Parameterized Node Constructor
    Node(unsigned int x1, struct Location x2,
         Node *x3, Node *x4, Node *x5, Node *x6,
         unsigned int x7, bool x8);

    // isElevatorHere() Method Prototype
    // Checks to see if the elevator resides in the current node this method is called at.
    bool isElevatorHere(Elevator * elevator) const;
        // Need to come up with some if conditions to properly return true or false
        // Possibly compare elevator's known position vs. current node location
            // ^^ that's exactly how we'll do it

    // nearbyNodes() Method Prototype
    // Lists the nodes immediately upwards, downwards, left, and right of the current node
    std::vector<NodeDirection> nearbyNodes();
        // Should return empty vector if there are no nodes residing next to the current node
        // Tentative if we return the nearby nodes' IDs or the nearby nodes' locations

    // addNode(...)
    // Adds a node in the required direction relative to the current node.
    int addNode(Node* node, enum Direction direction);

    // This version of addNode(...) completed the same goal as the previous addNode(...) method in a different manner.
    // This is just to offer some versatility and ease of programming in case one method does not work.
    int addNode(NodeDirection nodeDirect);

    // Overloaded << Method.
    // This prints out the current node instance's status.
    friend std::ostream& operator<<(std::ostream &out, const Node &node);
};


#endif //CPS_ELEVATOR_PROJECT_NODE_H
