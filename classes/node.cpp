///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: node.cpp
// Project Name: CPS_ELEVATOR_PROJECT
// Description:
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "node.h"
#include "elevator.h"

bool Node::isElevatorHere(Elevator * elevator){
    if(elevator->location == this->location) return true;
    else return false;
}