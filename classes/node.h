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
    // I made these public so that elevator.h can access these and didn't want to copy these into elevator.h
    // Eliminated redundancy but I'm not sure if this is the best solution
    // NodeDirection
    struct NodeDirection {
        Node* node;
        enum Direction direction;
    };

    // Location Structure
    struct Location {
        enum Section section;
        enum Floor floor;
        bool operator==(Location const &other){
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
    unsigned short int id;
    unsigned int peopleWaiting;

public:
    //====== PUBLIC VARIABLES ======//
    bool btnCalled;
    struct Node::Location location;

    //====== PUBLIC METHODS ======//
    // Default Constructor
    Node();

    // Need to add parameterized constructor???
    // Yeeeees
    Node(   unsigned int id, struct Location location,
            Node *upNode = nullptr, Node *rightNode = nullptr, Node *leftNode = nullptr, Node *downNode = nullptr,
            unsigned int peopleWaiting = 0, bool btnCalled = false);

    // isElevatorHere() checks to see if the elevator resides in the current node this method is called at
    bool isElevatorHere(Elevator * elevator);
        // Need to come up with some if conditions to properly return true or false
        // Possibly compare elevator's known position vs. current node location
            // ^^ that's exactly how we'll do it

    // nearbyNodes() lists the nodes immediately upwards, downwards, left, and right of the current node
    std::vector<NodeDirection> nearbyNodes();
        // Should return empty vector if there are no nodes residing next to the current node
        // Tentative if we return the nearby nodes' IDs or the nearby nodes' locations

    // addNode(...) will add a node in the required direction relative to the current node
    int addNode(Node* node, enum Direction direction);

    // Not too sure what this method does or what's different than the previous addNode(...)
        // It's the same thing just with the NodeDirection struct.
    int addNode(NodeDirection nodeDirect);
};


#endif //CPS_ELEVATOR_PROJECT_NODE_H
