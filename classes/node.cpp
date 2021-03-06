///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: node.cpp
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Contains implementation of methods defined for the Node class.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "node.h"
#include "elevator.h"

//====== Default Constructor Method Implementation ======//
Node::Node() {
    upNode = nullptr;
    downNode = nullptr;
    leftNode = nullptr;
    rightNode = nullptr;
    id = "ID Uninitialized";
    elevatorCalled = false;
    location = Location(A,First);
    peopleAtNode = std::vector<class Person*>();
    timeCalled = 0;
    timeBtnPressed = 0;
}

//====== Parameterized Constructor Implementation ======//
Node::Node(std::string ID, struct Location loc,
           Node *up, Node *down, Node *left, Node *right,
           bool elevCalled) {
    id = ID;
    location.floor = loc.floor;
    location.section = loc.section;
    upNode = up;
    downNode = down;
    leftNode = left;
    rightNode = right;
    elevatorCalled = elevCalled;
    peopleAtNode = std::vector<class Person*>();
    timeCalled = 0;
    timeBtnPressed = 0;
}

//====== isElevatorHere(...) Method Implementation ======//
bool Node::isElevatorHere(Elevator * elevator) const{
    if(elevator->location == this->location) return true;
    else return false;
}

//====== Overloaded << Implementation ======//
std::ostream &operator<<(std::ostream &out, const Node &node) {
    out
        << "\tNode ID: " << node.id << std::endl
        << "\tNode Grid:" << std::endl
        << "\t\t" << (node.upNode == nullptr ? ("--"):(node.upNode->id)) << std::endl
        << "\t" << (node.leftNode == nullptr ? ("--"):(node.leftNode->id)) << "\t" << node.id
        << "\t" << (node.rightNode == nullptr ? ("--"):(node.rightNode->id)) << std::endl
        << "\t\t" << (node.downNode == nullptr ? ("--"):(node.downNode->id)) << std::endl
        << "\tPeople Waiting At " << node.id << ": " << node.peopleAtNode.size() << std::endl
        << "\tElevator Called To " << node.id << ": " << (node.elevatorCalled ? ("Yes"):("No")) << std::endl;
    return out;
}

//====== nearbyNodes() Method Implementation ======//
// nearbyNodes() will return the nodes, and their directions relative to the source node,
// that are directly next to the source node.
std::vector<Node::NodeDirection> Node::nearbyNodes() {
    std::vector<NodeDirection> nodes;

    if(upNode != nullptr) nodes.push_back(NodeDirection(upNode, Up));
    if(downNode != nullptr) nodes.push_back(NodeDirection(downNode, Down));
    if(leftNode != nullptr) nodes.push_back(NodeDirection(leftNode, Left));
    if(rightNode != nullptr) nodes.push_back(NodeDirection(rightNode, Right));

    return nodes;
}

//====== addNodes(...) Method Implementation ======//
int Node::addNode(Node *node, enum Direction direction) {
    switch(direction){
        case Up:
            this->upNode = node;
            node->downNode = this;
            break;
        case Down:
            this->downNode = node;
            node->upNode = this;
            break;
        case Left:
            this->leftNode = node;
            node->rightNode = this;
            break;
        case Right:
            this->rightNode = node;
            node->leftNode = this;
            break;
    }
    return 0;
}

//====== addNode(...) Implementation ======//
int Node::addNode(Node::NodeDirection nodeDirect) {
    switch(nodeDirect.direction){
        case Up:
            this->upNode = nodeDirect.node;
            nodeDirect.node->downNode = this;
            break;
        case Down:
            this->downNode = nodeDirect.node;
            nodeDirect.node->upNode = this;
            break;
        case Left:
            this->leftNode = nodeDirect.node;
            nodeDirect.node->rightNode = this;
            break;
        case Right:
            this->rightNode = nodeDirect.node;
            nodeDirect.node->leftNode = this;
            break;
    }
    return 0;
}

//====== callElevator() Method Implementation ======//
void Node::callElevator(){
    // Checks if the elevator is already called.
    if(!elevatorCalled) {
        elevatorCalled = true;
        timeCalled = Elevator::getTime();
        Elevator::nodeBtnBuff_push_back(this);
        Elevator::incrementTime();
    }
}
