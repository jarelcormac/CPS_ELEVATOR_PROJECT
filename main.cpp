#include <iostream>
#include "classes/elevator.h"


int main() {
    std::cout << "********** STARTING TEST APPLICATION **********" << std::endl << std::endl;
    std::cout << "-CREATING TEST NODE (DEFAULT CONSTRUCTOR)..." << std::endl;

    Node testNode1 = Node();

    std::cout << "\t- TEST NODE SUCCESSFULLY CREATED" << std::endl;
    std::cout << "- PRINTING TEST NODE (DEFAULT CONSTRUCTOR) STATUS..." << std::endl;
    std::cout << testNode1;

    std::cout << "-CREATING TEST NODE (PARAMETERIZED CONSTRUCTOR)..." << std::endl;
    Node::Location tempLoc = {
            A,
            First
    };

    Node testNode2 = Node(22, tempLoc, nullptr, nullptr, nullptr, nullptr, 27, false);
    std::cout << "\t- TEST NODE (DEFAULT CONSTRUCTOR) SUCCESSFULLY CREATED" << std::endl;
    std::cout << "- PRINTING TEST NODE (PARAMETERIZED CONSTRUCTOR) STATUS..." << std::endl;
    std::cout << testNode2;
    return 0;
}
