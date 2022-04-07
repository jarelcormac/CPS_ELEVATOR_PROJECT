#include <iostream>
#include "classes/elevator.h"


int main() {
    std::cout << "********** STARTING TEST APPLICATION **********" << std::endl << std::endl;
    std::cout << "-CREATING TEST NODE..." << std::endl;

    Node testNode = Node();

    std::cout << "\t- TEST NODE SUCCESSFULLY CREATED" << std::endl;
    std::cout << "- PRINTING TEST NODE STATUS..." << std::endl;
    std::cout << testNode;
    return 0;
}
