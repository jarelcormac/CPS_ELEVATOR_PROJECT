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
    peopleWaiting = 0;
    btnCalled = false;
    location = Location(A,First);
}

//====== Parameterized Constructor Implementation ======//
Node::Node(std::string ID, struct Location loc,
           Node *up, Node *down, Node *left, Node *right,
           unsigned int pplWaiting, bool buttonCalled) {
    id = ID;
    location.floor = loc.floor;
    location.section = loc.section;
    upNode = up;
    downNode = down;
    leftNode = left;
    rightNode = right;
    peopleWaiting = pplWaiting;
    btnCalled = buttonCalled;
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
//        << "\tUp Node: " << (node.upNode == nullptr ? ("-"):(node.upNode->id)) << std::endl
//        << "\tDown Node: " << (node.downNode == nullptr ? ("-"):(node.downNode->id)) << std::endl
//        << "\tLeft Node: " << (node.leftNode == nullptr ? ("-"):(node.leftNode->id)) << std::endl
//        << "\tRight Node: " << (node.rightNode == nullptr ? ("-"):(node.rightNode->id)) << std::endl
        << "\tPeople Waiting At " << node.id << ": " << node.peopleWaiting << std::endl
        << "\tButton Called At " << node.id << ": " << (node.btnCalled ? ("Yes"):("No")) << std::endl;
//        << "\tFloor Location of Node: " << node.location.floor << std::endl
//        << "\tSection Location of Node: " << node.location.section << std::endl << std::endl;
    return out;
}
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

// addNode() will add a node in the direction specified relative to the source node
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

// addNode() will add a node in the direction specified relative to the source node
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

void Node::callElevator(){
    if(!elevatorCalled) { // checks if the elevator is already called
        elevatorCalled = true;
        timeCalled = Elevator::getTime();
        Elevator::nodeBtnBuff_push_back(this);
        Elevator::incrementTime();
    }
}
