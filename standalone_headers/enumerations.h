///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: enumerations.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining enumerations for direction of elevator, and the floors (verticality) and sections
//              (horizontality) of a 3x3 grid in which the elevator is allowed to traverse.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CPS_ELEVATOR_PROJECT_ENUMERATIONS_H
#define CPS_ELEVATOR_PROJECT_ENUMERATIONS_H

#include <iostream>

#endif //CPS_ELEVATOR_PROJECT_ENUMERATIONS_H


/******************************************************************************
 *
 * DIRECTION ENUMERATION
 *
******************************************************************************/
 enum Direction {
     Up,
     Down,
     Left,
     Right
 };


/******************************************************************************
 *
 * FLOOR ENUMERATION
 *
******************************************************************************/
enum Floor {
    First = 2,      // First floor will be indexed as 2 in C++ 2D array.
    Second = 1,     // Second floor will be indexed as 1 in C++ 2D array.
    Third = 0       // Third floor will be indexed as 0 in C++ 2D array.
};


/******************************************************************************
 *
 * SECTION ENUMERATION
 *
******************************************************************************/
enum Section {
    A = 0,      // A represents the leftmost column of nodes.
    B = 1,      // B represents the middle column of nodes.
    C = 2       // C represents the rightmost column of nodes.
};
