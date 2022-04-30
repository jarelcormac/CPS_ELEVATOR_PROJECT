///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 31 MAR 2022
// Filename: node.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Header file defining properties and prototyping methods of class elevator.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef CPS_ELEVATOR_PROJECT_LOCATION_H
#define CPS_ELEVATOR_PROJECT_LOCATION_H

#include "enumerations.h"

#endif //CPS_ELEVATOR_PROJECT_LOCATION_H

// Location Structure
struct Location {
    enum Section section;
    enum Floor floor;

    // Constructors
    Location():section(A), floor(First){}
    Location(enum Section sec, enum Floor flr) :section(sec), floor(flr){}

    // Overloaded == Operator
    bool operator==(Location const &other) const {
        if(floor == other.floor && section == other.section) return true;
        else return false;
    }

    // Overloaded << Operator
    friend std::ostream &operator<<(std::ostream &out, Location const &loc) {
        char flr, sec;
        switch(loc.floor){
            case First: flr = '1'; break;
            case Second: flr = '2'; break;
            case Third: flr = '3'; break;
        }
        switch(loc.section){
            case A: sec = 'A'; break;
            case B: sec = 'B'; break;
            case C: sec = 'C'; break;
        }
        out << flr << sec;
        return out;
    }
};


