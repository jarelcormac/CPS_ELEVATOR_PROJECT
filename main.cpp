#include <iostream>
#include <cstring>
#include "classes/elevator.h"
#include "standalone_headers/enumerations.h"


//====== FUNCTION PROTOTYPES ======//

/*
 * <createLocationArray() Function Prototype>
 *      Function that creates a 2D Array of the nine possible node locations the elevator can traverse to.
 *      First letter indicates column which node resides in.
 *      Second number indicates floor which node resides in.
 */
void createLocationArray(Node::Location locArray[3][3]);

/*
 * <createNodes() Function Prototype>
 *      Function creates all nine possible nodes only using parameterized constructor.
 */
void createNodes(Node nodesArray[3][3], Node::Location locArray[3][3]);

/*
 * <createNodeGrid(...) Function Prototype>
 *      Function creates the 2D Grid in which the elevator is able to traverse.
 *      The nine nodes created by the createNodes(...) function are organized into a 3x3 grid fashion
 *      and their locations are also related to each other in respect to their current positions.
 *      Links the 3x3 grid of nodes to have the following linked structure:
 *      3A---3B---3C
 *           |
 *      2A---2B---2C
 *           |
 *      1A---2B---2C
 */
void createNodeGrid(Node nodeArray[3][3]);

// BEGIN MAIN EXECUTION
int main() {
    std::cout << "********** STARTING TEST APPLICATION **********" << std::endl << std::endl;

    // Create an array holding all possible node locations.
    std::cout << "- CREATING LOCATION ARRAY..." << std::endl;
    Node::Location locationArray[3][3];
    createLocationArray(locationArray);
    std::cout << "\t- LOCATION ARRAY SUCCESSFULLY CREATED" << std::endl;

    // Form the grid system.
    std::cout << "- CREATING NODE GRID SYSTEM..." << std::endl;
    std::cout << "\t- CREATING NODES..." << std::endl;
    Node nodeArray[3][3];
    createNodes(nodeArray, locationArray);
    std::cout << "\t\t- NODES AND GRID SYSTEM SUCCESSFULLY CREATED" << std::endl;


    std::cout << "- PRINTING ALL NODE STATUSES..." << std::endl;
    for(Floor x = First; x >= Third; x = (Floor)(x - 1)) {
        for(Section y = A; y <= C; y = (Section)(y + 1)) {
            std::cout << nodeArray[x][y] << std::endl;
        }
    }

    std::cout << "********** STARTING TEST APPLICATION **********" << std::endl;

return 0;
}


//====== FUNCTION IMPLEMENTATIONS ======//

/*
 *
 * <createLocationArray(...) Function Implementation>
 *
 */
void createLocationArray(Node::Location locArray[3][3]) {
    int column = A;
    int floor = First;
    for(Floor x = First; x >= Third; x = (Floor)(x - 1)) {
        for(Section y = A; y <= C; y = (Section)(y + 1)) {
            locArray[floor][column].floor = x;
            locArray[floor][column].section = y;
            column++;
        }
        floor--;
        column = 0;
    }
}

/*
 * <createNodes(...) Function Implementation>
 */
void createNodes(Node nodesArray[3][3], Node::Location locArray[3][3]) {
    int column = A;
    int floor = First;
    char col = 'A';
    char flr = '1';
    for(Floor x = First; x >= Third; x = (Floor)(x - 1)) {
        for(Section y = A; y <= C; y = (Section)(y + 1)) {
            auto locName = std::string(1, flr) + col;
            nodesArray[floor][column] = Node(locName, locArray[floor][column]);
            column++;
            col++;
        }
        floor--;
        flr++;
        column = 0;
        col = 'A';
    }

    // Add positional relationships for each node.
    createNodeGrid(nodesArray);
};

/*
 * <createNodeGrid(...) Function Implementation>
 *  *  // Links the 3x3 grid of nodes to have the following linked structure:
 *      3A---3B---3C
 *           |
 *      2A---2B---2C
 *           |
 *      1A---1B---1C
 */
void createNodeGrid(Node nodes[3][3]) {
    // Creates horizontal section connections every floor
    nodes[Third][A].addNode(&nodes[Third][B], Right);
    nodes[Third][B].addNode(&nodes[Third][C], Right);
    nodes[Second][A].addNode(&nodes[Second][B], Right);
    nodes[Second][B].addNode(&nodes[Second][C], Right);
    nodes[First][A].addNode(&nodes[First][B], Right);
    nodes[First][B].addNode(&nodes[First][C], Right);\

    // Creates vertical section connections for only the center column
    nodes[Second][B].addNode(&nodes[Third][B], Up);
    nodes[Second][B].addNode(&nodes[First][B], Down);

};