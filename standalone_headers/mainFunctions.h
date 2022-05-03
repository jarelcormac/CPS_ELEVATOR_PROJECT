///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: elevator.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining and implementing methods required in main.
//              Additionally, this file includes headers for the Elevator and Person classes.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CPS_ELEVATOR_PROJECT_MAINFUNCTIONS_H
#define CPS_ELEVATOR_PROJECT_MAINFUNCTIONS_H

#include "../classes/elevator.h"
#include "../classes/person.h"


//====== FUNCTION PROTOTYPES ======//

/*
 * <createLocationArray() Function Prototype>
 *      Function will create a 2D array of positions a node may reside at. Each position has its own unique floor
 *       number and column letter assigned to it.
 *      This is used to assist in building the node grid system without much challenge or unnecessary code.
 */
void createLocationArray(Location locArray[3][3]);

/*
 * <createNodes() Function Prototype>
 *      Function creates all nine possible nodes only using parameterized constructor for class Node.
 *      This does NOT give the nodes any positional relationships or connections to each other - it only creates the
 *       nodes at each of the nine locations.
 *      The location array is used to assist in developing the nodes as a node's location will be based on where
 *       in the location array the node is built.
 */
void createNodes(Node nodesArray[3][3], Location locArray[3][3]);

/*
 * <createNodeGrid(...) Function Prototype>
 *      Function creates the 2D Grid in which the elevator is able to traverse.
 *      The nine nodes created by the createNodes(...) function are organized into a 3x3 grid fashion
 *       and their locations are also related to each other in respect to their current positions.
 *      Links the 3x3 grid of nodes to have the following linked structure:
 *          3A---3B---3C
 *               |
 *          2A---2B---2C
 *               |
 *          1A---2B---2C
 */
void createNodeGrid(Node nodes[3][3]);

/*
 * <printElevatorSystem(...) Function Prototype>
 *      Function will print out a 2D visualization of the elevator system in an easy-to-understand way onto the
 *       console.
 */
void printElevatorSystem(Elevator & elevator, Node nodes[3][3]);


/**********************************************************************************************************************
 *********************************************************************************************************************/


//====== FUNCTION IMPLEMENTATIONS ======//

/*
 * <createLocationArray(...) Function Implementation>
 */
void createLocationArray(Location locArray[3][3]) {
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
void createNodes(Node nodesArray[3][3], Location locArray[3][3]) {
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
    nodes[Third] [A].addNode(&nodes[Third] [B], Right);
    nodes[Third] [B].addNode(&nodes[Third] [C], Right);
    nodes[Second][A].addNode(&nodes[Second][B], Right);
    nodes[Second][B].addNode(&nodes[Second][C], Right);
    nodes[First] [A].addNode(&nodes[First] [B], Right);
    nodes[First] [B].addNode(&nodes[First] [C], Right);

    // Creates vertical section connections for only the center column
    nodes[Second][B].addNode(&nodes[Third][B], Up);
    nodes[Second][B].addNode(&nodes[First][B], Down);
};

/*
 * Will print out a 2D visualization of the elevator system in an easy-to-understand way.
 * Should look similar to this:
 *      3A=====3B=====3C
 *    [ {} ] [    ] [    ]
 *             ||
 *      2A=====2B=====2C
 *    [    ] [    ] [    ]
 *             ||
 *      1A=====1B=====1C
 *    [    ] [    ] [    ]
 */
void printElevatorSystem(Elevator & elevator, Node nodes[3][3]) {
    Floor tempFloor = elevator.getCurrentNode()->location.floor;
    Section tempSection = elevator.getCurrentNode()->location.section;
    elevator.printSystem(nodes, tempFloor, tempSection);
}

#endif //CPS_ELEVATOR_PROJECT_MAINFUNCTIONS_H
