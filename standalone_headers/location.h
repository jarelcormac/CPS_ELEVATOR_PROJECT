///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: location.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining location structure of nodes/elevator.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CPS_ELEVATOR_PROJECT_LOCATION_H
#define CPS_ELEVATOR_PROJECT_LOCATION_H

struct Location {
    unsigned int locX; // Defines which column a node resides
    unsigned int locY; // Defines which floor a node resides in
};

#endif //CPS_ELEVATOR_PROJECT_LOCATION_H
