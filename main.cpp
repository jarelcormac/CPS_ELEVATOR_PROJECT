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

    // Create an array holding all possible node locations.
    std::cout << "- CREATING LOCATION ARRAY..." << std::endl;
    Location locationArray[3][3];
    createLocationArray(locationArray);
    std::cout << "\t- LOCATION ARRAY SUCCESSFULLY CREATED" << std::endl;

    // Form the grid system.
    std::cout << "- CREATING NODE GRID SYSTEM..." << std::endl;
    std::cout << "\t- CREATING NODES..." << std::endl;
    Node nodeArray[3][3];
    createNodes(nodeArray, locationArray);
    std::cout << "\t\t- NODES AND GRID SYSTEM SUCCESSFULLY CREATED" << std::endl;

    // Print out all current node statuses.
    std::cout << "- PRINTING ALL NODES' STATUSES..." << std::endl;
    for(Floor x = First; x >= Third; x = (Floor)(x - 1)) {
        for(Section y = A; y <= C; y = (Section)(y + 1)) {
            std::cout << nodeArray[x][y] << std::endl;
        }
    }

    // Initialize a buttonPressed array.
    bool buttonPressed[3][3] = {
            false, false, false,
            false, false, false,
            false, false, false
    };

    // Instantiate Elevator at Node 2B.
    std::cout << "- CREATING INSTANCE OF ELEVATOR AT NODE 2B..." << std::endl;
    Elevator elevator = Elevator(&nodeArray[Second][B], buttonPressed);
    Elevator::initializeCurrentTime();
    Elevator::getTime();
    std::cout << "\t- ELEVATOR INSTANTIATED AT NODE 2B" << std::endl;
    std::cout << "- PRINTING ELEVATOR'S STATUS..." << std::endl;
    std::cout << elevator << std::endl;

/*
    std::cout << "- TESTING ELEVATOR MOVEMENT/DOOR FUNCTIONALITIES..." << std::endl;

    // Move Up
    std::cout << "\t- MOVING UP..." << std::endl;
    elevator.moveUp();
    std::cout  << elevator << std::endl;
    // Move Down
    std::cout << "\t- MOVING DOWN..." << std::endl;
    elevator.moveDown();
    std::cout  << elevator << std::endl;
    // Move Left
    std::cout << "\t- MOVING LEFT..." << std::endl;
    elevator.moveLeft();
    std::cout  << elevator << std::endl;
    // Move Right
    std::cout << "\t- MOVING RIGHT..." << std::endl;
    elevator.moveRight();
    std::cout  << elevator << std::endl;
    // Open Doors
    std::cout << "\t- OPENING ELEVATOR DOORS..." << std::endl;
    elevator.openDoors();
    std::cout  << elevator << std::endl;
    // Move Right
    std::cout << "\t- MOVING RIGHT..." << std::endl;
    elevator.moveRight();
    std::cout  << elevator << std::endl;
    // Close Doors
    std::cout << "\t- CLOSING ELEVATOR DOORS..." << std::endl;
    elevator.closeDoors();
    std::cout  << elevator << std::endl;
*/

/*
    // Introduce some people into the elevator.
    std::cout << "- INSTANTIATING A PATRON INTO THE ELEVATOR SYSTEM..." << std::endl;
    auto patron1 = new Person(&nodeArray[Second][B], &nodeArray[Second][B],
                              &elevator, Elevator::getTime(), false);
    auto patron2 = new Person(&nodeArray[Second][B], &nodeArray[Third][B],
                              &elevator, Elevator::getTime(), false);
    std::cout << "\t- TWO PEOPLE SUCCESSFULLY INSTANTIATED AT NODE 2B W/ END LOCATION OF NODE 2B" << std::endl;
    std::cout << "- PRINTING PATRON INFORMATION..." << std::endl;
    std::cout << *patron1 << std::endl;
    patron1->callElevator();
    std::cout << *patron2 << std::endl;
    patron2->callElevator();

    // Test elevator pick-up/drop-off functions.
    std::cout << "- TESTING ELEVATOR PICK-UP/DROP-OFF FUNCTIONALITIES..." << std::endl;
    std::cout << "\t- PICKING UP PATRONS..." << std::endl;
    elevator.pickUp();
    std::cout << *patron1 << std::endl;
    std::cout << *patron2 << std::endl;
    std::cout << "\t- DROPPING OFF PATRONS..." << std::endl;
    elevator.dropOff();
    std::cout << "\t- THIS IS THE FIRST PATRON" << std::endl;
    std::cout << *patron1 << std::endl;
    std::cout << "\t- THIS IS THE SECOND PATRON" << std::endl;
    std::cout << *patron2 << std::endl;
    std::cout << "\t- INTRODUCING THIRD PATRON..." << std::endl;
    auto patron3 = new Person(&nodeArray[Second][B], &nodeArray[First][B],
                              &elevator, Elevator::getTime(), false);
    patron3->callElevator();
    std::cout << "- PRINTING PATRON 3 INFORMATION..." << std::endl;
    std::cout << *patron3 << std::endl;
    std::cout << "- PICKING UP THIRD PATRON..." << std::endl;
    elevator.pickUp();
    std::cout << *patron3 << std::endl;
    elevator.dropOff();
    std::cout << "- DROPPING OFF THIRD PATRON..." << std::endl;
    std::cout << *patron3 << std::endl;
    std::cout << "\t\t- PICK-UP/DROP-OFF FUNCTIONALITIES PASSED\n\n" << std::endl;
*/

    std::cout << "- INSTANTIATING A PATRON INTO THE ELEVATOR SYSTEM..." << std::endl;
    auto patron1 = new Person(&nodeArray[First][A], &nodeArray[Second][A],
                              &elevator, Elevator::getTime(), false);
    std::cout << "\t- SUCCESSFULLY INSTANTIATED PATRON W/ NODE START 1A" << std::endl;
    std::cout << "- PRINTING PATRON 1 INFORMATION..." << std::endl;
    std::cout << *patron1 << std::endl;
    std::cout << "- SYSTEM TEST: PICK UP PATRON 1 AT NODE 1A/DROP PATRON OFF AT NODE 2A" << std::endl;
    std::cout << "\t- PICKING UP PATRON 1..." << std::endl;
    elevator.moveHere(&nodeArray[First][A]);
    std::cout << "\t- PATRON 1 SUCCESSFULLY PICKED UP" << std::endl;
    std::cout << "\t- PATRON 1:" << std::endl;
    std::cout << *patron1 << std::endl;
    std::cout << "- INTRODUCING ANOTHER PATRON TO SYSTEM AT W/ PICKUP AT NODE 1B/DROPOFF AT NODE 2A" << std::endl;
    auto patron2 = new Person(&nodeArray[First][B], &nodeArray[Second][A],
                              &elevator, Elevator::getTime(), false);
    std::cout << "\t- PATRON 2:" << std::endl;
    std::cout << *patron2 << std::endl;
    std::cout << "\t- PICKING UP PATRON 2..." << std::endl;
    elevator.moveHere(&nodeArray[First][B]);
    std::cout << "\t- PATRON 2 SUCCESSFULLY PICKED UP" << std::endl;
    std::cout << "\t- PATRON 1:" << std::endl;
    std::cout << *patron1 << std::endl;
    std::cout << "\t- PATRON 2:" << std::endl;
    std::cout << *patron2 << std::endl;
    std::cout << "- ATTEMPTING TO DROPOFF BOTH PATRON 1 AND 2 AT NODE 2A..." << std::endl;
    elevator.moveHere(&nodeArray[Second][A]);
    std::cout << "\t- DROPOFF SUCCESSFUL!" << std::endl;
    std::cout << "\t- PATRON 1:" << std::endl;
    std::cout << *patron1 << std::endl;
    std::cout << "\t- PATRON 2:" << std::endl;
    std::cout << *patron2 << std::endl;






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