///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 2 MAY 2022
// Filename: elevator.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Main source file which contains the system tests required to show that the elevator system is fully
//              functional in respect to movement across nodes, pick-up/drop-off capabilities, bookkeeping of elevator
//              patrons, and proper elevator pathfinding throughout the node system.
//
//
// Version 1.00 - File Created
// Additional Comments: This file also includes required headers from the Elevator and Person classes.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "standalone_headers/mainFunctions.h"


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



    std::cout << "\n\n********** TEST APPLICATION COMPLETED **********" << std::endl;

    printElevatorSystem(elevator, nodeArray);

return 0;
}
/****************** END MAIN EXECUTION ******************/


