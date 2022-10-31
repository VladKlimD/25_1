#include <iostream>
#include <string>
#include <vector>
#include "operational-tools.h"

void input_Command(std::string& command) {
    std::cout << "Input command:" << std::endl;
    std::cin >> command;
}

int main() {
    std::string command;
    std::vector<coordinates> scalpel_Uses, hemostat_Uses, tweezers_Uses, suture_Uses;

    for (;;) {
        input_Command(command);
        if (command == "scalpel") {
            scalpel(scalpel_Uses);
            break;
        }
        std::cout << "You should use scalpel at first\n";
    }

    while (scalpel_Uses.size() != 0) {
        input_Command(command);
        if (command == "scalpel") {
            scalpel(scalpel_Uses);
        }
        else if (command == "hemostat") {
            hemostat(hemostat_Uses);
        }
        else if (command == "tweezers") {
            tweezers(tweezers_Uses);
        }
        else if (command == "suture") {
            suture(suture_Uses, scalpel_Uses);
        }
        else std::cout << "Unknown command. Retry your enter\n";
    }

    std::cout << "Operation is over!\n";
}
