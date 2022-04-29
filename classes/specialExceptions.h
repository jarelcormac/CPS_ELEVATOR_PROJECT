///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Company: San Diego State University
// Engineer: Jarel-John Cortel Macanas
//           Shoh Allan Sewell
//
// Create Date: 29 APR 2022
// Filename: specialExceptions.h
// Project Name: CPS_ELEVATOR_PROJECT
// Description: Contains class for custom exceptions.
//
//
// Version 1.00 - File Created
// Additional Comments:
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdexcept>
#include <iostream>

#ifndef CPS_ELEVATOR_PROJECT_SPECIALEXCEPTIONS_H
#define CPS_ELEVATOR_PROJECT_SPECIALEXCEPTIONS_H

/****************************************************
 *
 * SPECIAL EXCEPTIONS CLASS
 *
 ***************************************************/
class MoveUpException : public std::exception {
public:
    const char* what () const noexcept override {
        return "Error: Elevator cannot move upwards!";
    }
};

class MoveDownException : public std::exception {
public:
    const char* what () const noexcept override {
        return "Error: Elevator cannot move downwards!";
    }
};

class MoveLeftException : public std::exception {
public:
    const char* what () const noexcept override {
        return "Error: Elevator cannot move left!";
    }
};

class MoveRightException : public std::exception {
public:
    const char* what () const noexcept override {
        return "Error: Elevator cannot move right!";
    }
};

class OpenDoorsException : public std::exception {
public:
    const char* what () const noexcept override {
        return "Error: Elevator doors cannot open!";
    }
};

class CloseDoorsException : public std::exception {
public:
    const char* what () const noexcept override {
        return "Error: Elevator doors cannot close!";
    }
};

#endif //CPS_ELEVATOR_PROJECT_SPECIALEXCEPTIONS_H
