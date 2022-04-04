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

#include "enumerations.h"

#ifndef CPS_ELEVATOR_PROJECT_LOCATION_H
#define CPS_ELEVATOR_PROJECT_LOCATION_H

/******************************************************************************
 *
 * LOCATION STRUCTURE
 *
 * Notes: This structure combines the section and floor enumerations to
 *        calculate the current location of the elevator. Additionally, it is
 *        used to keep track of create node locations that the elevator may
 *        traverse to.
 *
******************************************************************************/
struct Location {
public:
    enum Section section;
    enum Floor floor;
};

#endif //CPS_ELEVATOR_PROJECT_LOCATION_H
