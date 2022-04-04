///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: nodedirection.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file containing structures that define the direction of nodes
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "enumerations.h"
#include "../classes/node.h"
#ifndef CPS_ELEVATOR_PROJECT_NODEDIRECTION_H
#define CPS_ELEVATOR_PROJECT_NODEDIRECTION_H

/******************************************************************************
 *
 * NODE DIRECTION STRUCTURE
 *
 * Notes: ADD STUFF HERE
 *
******************************************************************************/
struct NodeDirection {
public:
    Node* node;
    enum Direction direction;
};
#endif //CPS_ELEVATOR_PROJECT_NODEDIRECTION_H
