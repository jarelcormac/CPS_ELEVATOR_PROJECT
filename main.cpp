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
#include <random>
#include "standalone_headers/mainFunctions.h"


/****************** BEGIN MAIN EXECUTION ******************/
int main() {
    std::cout << "********** STARTING TEST APPLICATION **********" << std::endl << std::endl;

    //======== Start system initialization stage. ========//
    std::cout << "=== INITIALIZING SYSTEM ===" << std::endl << std::endl;

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
    Elevator elevator = Elevator(&nodeArray[Second][B], buttonPressed, nodeArray);
    Elevator::initializeCurrentTime();
    Elevator::getTime();
    std::cout << "\t- ELEVATOR INSTANTIATED AT NODE 2B" << std::endl;
    std::cout << "- PRINTING ELEVATOR'S STATUS..." << std::endl;
    std::cout << elevator << std::endl;

    // Print out all current node statuses
    std::cout << "- PRINTING ALL NODES' STATUSES..." << std::endl;
    for(Floor x = First; x >= Third; x = (Floor)(x - 1)) {
        for(Section y = A; y <= C; y = (Section)(y + 1)) {
            std::cout << nodeArray[x][y] << std::endl;
        }
    }
    std::cout << "=== SYSTEM INITIALIZATION DONE ===" << std::endl << std::endl << std::endl;
    //========= FINISHED SYSTEM INITIALIZATION ========//


    //======== BEGIN SYSTEM TEST #1 ========//
    std::cout << "SYSTEM TEST #1 | MOVEMENT FROM ONE NODE TO ANOTHER NODE (ONE HOP)" << std::endl;
    std::cout << "- MOVING ELEVATOR FROM NODE 2B to 2C" << std::endl;
    elevator.moveHere({C, Second});
    std::cout << "~SYSTEM TEST #1 SUCCESSFUL~" << std::endl << std::endl;
    //======== END SYSTEM TEST #1 ========//


    //======== BEGIN SYSTEM TEST #2 ========//
    std::cout << "SYSTEM TEST #2 | MOVEMENT FROM ONE NODE TO ANOTHER NODE OF MORE THAN ONE HOP" << std::endl;
    std::cout << "- MOVING ELEVATOR FROM NODE 2C to 2B" << std::endl;
    elevator.moveHere({B, Second});
    std::cout << "- MOVING ELEVATOR FROM NODE 2B to 3B" << std::endl;
    elevator.moveHere({B, Third});
    std::cout << "~SYSTEM TEST #2 SUCCESSFUL~" << std::endl << std::endl;
    //======== BEGIN SYSTEM TEST #2 ========//


    //======== BEGIN SYSTEM TEST #3 ========//
    std::cout << "SYSTEM TEST #3 | CALLING THE ELEVATOR CAR FROM ANY NODE TO A DESTINATION NODE OF N HOPS MULTIPLE TIMES" << std::endl;
    std::cout << "- MOVING ELEVATOR FROM NODE 3B TO 1A" << std::endl;
    elevator.moveHere({A, First});
    std::cout << "~SYSTEM TEST #3 SUCCESSFUL~" << std::endl << std::endl;
    //======== END SYSTEM TEST #3 ========//


    //======== BEGIN SYSTEM TEST #4 ========//
    std::cout << "SYSTEM TEST #4 | CALLING THE ELEVATOR CAR FROM ANY NODE TO A DESTINATION NODE IN A COMPLEX ARRANGEMENT OF NODES" << std::endl;
    std::cout << "- MOVING ELEVATOR FROM NODE 1A to 3C" << std::endl;
    elevator.moveHere({C, Third});
    std::cout << "~SYSTEM TEST #4 SUCCESSFUL~" << std::endl << std::endl;
    //======== END SYSTEM TEST #4 ========//


    //======== BEGIN SYSTEM TEST #5 ========//
    std::cout << "SYSTEM TEST #5 | PICK-UP AND DROP-OFF MULTIPLE PATRONS IN A COMPLEX ARRANGEMENT OF NODES" << std::endl;
    std::cout << "- CREATING A SET OF 10 PATRONS..." << std::endl;
    // Random number generator code used from Microsoft c++ documentation
    // https://docs.microsoft.com/en-us/cpp/standard-library/random?view=msvc-170
    std::random_device rdNum;    // Creates a non-deterministic generator
//    std::mt19937 gen(rdNum());// Seeds mersenne twister
    std::uniform_int_distribution<> dist(0,2); // Will distribute a result between 0 and 2 inclusive
    // To generate a random number use dist(gen).
    std::vector<class Person> personVector;
    personVector.reserve(10);
    for(int i = 0; i < 10; i++) {
        personVector.emplace_back(&nodeArray[dist(rdNum)][dist(rdNum)], &nodeArray[dist(rdNum)][dist(rdNum)],
                                      &elevator, 0, false, false);
    }
    std::cout << "- 10 PATRONS SPAWNED. PRINTING PATRON INFORMATION..." << std::endl;
    for(int i = 0; i < 10; i++) {
        std::cout << personVector.at(i) << std::endl;
    }

    // std::cout << "ORDER OF NODES:" << std::endl;
    elevator.printSystem();

    std::cout << "- MOVING ELEVATOR TO SERVICE EACH PATRON" << std::endl;
    while(!Elevator::nodeButtonBufferEmpty() || !Elevator::elevatorButtonBufferEmpty()){
        elevator.moveHere(Elevator::nextBufferLocation());
        for(int i = 0; i < 10; i++) {
            std::cout << personVector.at(i) << std::endl;
        }
    }
    std::cout << "~SYSTEM TEST #5 SUCCESSFUL~" << std::endl << std::endl;
    //======== END SYSTEM TEST #5 ========//

    elevator.printSystem();


    std::cout << "\n\n********** TEST APPLICATION COMPLETED **********" << std::endl;


return 0;
}
/****************** END MAIN EXECUTION ******************/


