#include <cstring>
#include "classes/elevator.h"
#include "classes/person.h"


//====== FUNCTION PROTOTYPES ======//

/*
 * <createLocationArray() Function Prototype>
 *      Function that creates a 2D Array of the nine possible node locations the elevator can traverse to.
 *      First letter indicates column which node resides in.
 *      Second number indicates floor which node resides in.
 */
void createLocationArray(Location locArray[3][3]);

/*
 * <createNodes() Function Prototype>
 *      Function creates all nine possible nodes only using parameterized constructor.
 */
void createNodes(Node nodesArray[3][3], Location locArray[3][3]);

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
void createNodeGrid(Node nodes[3][3]);

/****************** BEGIN MAIN EXECUTION ******************/
int main() {
    std::cout << "********** STARTING TEST APPLICATION **********" << std::endl << std::endl;

    // Create an array holding all possible node locations
    std::cout << "- CREATING LOCATION ARRAY..." << std::endl;
    Location locationArray[3][3];
    createLocationArray(locationArray);
    std::cout << "\t- LOCATION ARRAY SUCCESSFULLY CREATED" << std::endl;

    // Form the grid system
    std::cout << "- CREATING NODE GRID SYSTEM..." << std::endl;
    std::cout << "\t- CREATING NODES..." << std::endl;
    Node nodeArray[3][3];
    createNodes(nodeArray, locationArray);
    std::cout << "\t\t- NODES AND GRID SYSTEM SUCCESSFULLY CREATED" << std::endl;

    // Print out all current node statuses
    std::cout << "- PRINTING ALL NODES' STATUSES..." << std::endl;
    for(Floor x = First; x >= Third; x = (Floor)(x - 1)) {
        for(Section y = A; y <= C; y = (Section)(y + 1)) {
            std::cout << nodeArray[x][y] << std::endl;
        }
    }

    // Initialize a buttonPressed array
    bool buttonPressed[3][3] = {
            false, false, false,
            false, false, false,
            false, false, false
    };

    // Instantiate an elevator object at Node 2B
    std::cout << "- CREATING INSTANCE OF ELEVATOR AT NODE 2B..." << std::endl;
    Elevator elevator = Elevator(&nodeArray[Second][B], buttonPressed);
    Elevator::initializeCurrentTime();
    Elevator::getTime();
    std::cout << "\t- ELEVATOR INSTANTIATED AT NODE 2B" << std::endl;
    std::cout << "- PRINTING ELEVATOR'S STATUS..." << std::endl;
    std::cout << elevator << std::endl;

    // Instantiate a Patron into the node system.
    std::cout << "- INSTANTIATING A PATRON INTO THE ELEVATOR SYSTEM..." << std::endl;
    auto patron1 = new Person(&nodeArray[First][A], &nodeArray[Second][A],
                              &elevator, Elevator::getTime(), false);
    std::cout << "\t- SUCCESSFULLY INSTANTIATED PATRON W/ NODE START 1A" << std::endl;

    // Print Patron 1's Information
    std::cout << "- PRINTING PATRON 1 INFORMATION..." << std::endl;
    std::cout << *patron1 << std::endl;

    /*
     * System Test designed to test the movement, pick-up, and drop-off functionalities of the elevator
     */
    std::cout << "- SYSTEM TEST: PICK UP PATRON 1 AT NODE 1A/DROP PATRON OFF AT NODE 2A" << std::endl;

    // Pick up Patron 1
    std::cout << "\t- PICKING UP PATRON 1..." << std::endl;
    elevator.moveHere(&nodeArray[First][A]);
    std::cout << "\t- PATRON 1 SUCCESSFULLY PICKED UP" << std::endl;
    // Reprint Patron 1's information with after it gets picked up
    std::cout << "\t- PATRON 1:" << std::endl;
    std::cout << *patron1 << std::endl;

    // Introduce another patron into the system BEFORE the elevator is sent to the destination node.
    std::cout << "- INTRODUCING ANOTHER PATRON TO SYSTEM AT W/ PICKUP AT NODE 1B/DROPOFF AT NODE 2A" << std::endl;
    auto patron2 = new Person(&nodeArray[First][B], &nodeArray[Second][A],
                              &elevator, Elevator::getTime(), false);
    // Print out Patron 2's information
    std::cout << "\t- PATRON 2:" << std::endl;
    std::cout << *patron2 << std::endl;

    /*
     * Since Patron 2's node is on the way to Patron 1's destination node, the elevator picks up Patron 2 on the way
     */

    // Attempt to drop off Patron 1 and Patron 2 at Node 2A
    std::cout << "- ATTEMPTING TO DROPOFF BOTH PATRON 1 AND 2 AT NODE 2A..." << std::endl;
    elevator.moveHere(&nodeArray[Second][A]);
    std::cout << "\t- DROPOFF SUCCESSFUL!" << std::endl;

    // Reprint Patron 1 and Patron 2's statuses
    std::cout << "\t- PATRON 1:" << std::endl;
    std::cout << *patron1 << std::endl;
    std::cout << "\t- PATRON 2:" << std::endl;
    std::cout << *patron2 << std::endl;




//    while(!Elevator::isNodeBtnBuffEmpty()) {
//        if(!Elevator::isNodeBtnBuffEmpty()){
//            elevator.move();
//        }
//        // Statement that creates a new person and adds them to the system using variable iterations.
//        // autonomous system runs in while loop.
//        // everytime the while-loop restarts, add another person.
//    }

    // Detect if there's any people in the system; if so, run the algorithm


    std::cout << "\n\n********** TEST APPLICATION COMPLETED **********" << std::endl;

return 0;
}
/****************** END MAIN EXECUTION ******************/


//====== FUNCTION IMPLEMENTATIONS ======//

/*
 *
 * <createLocationArray(...) Function Implementation>
 *
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