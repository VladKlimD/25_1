#include <iostream>
#include <string>
#include "operational-tools.h"

void input_Command(std::string& command) {
    std::cout << "Input command:" << std::endl;
    std::cin >> command;
}

int main() {
    std::string command;

    for (;;) {
        input_Command(command);
        if (command == "scalpel") {
            scalpel_Uses.push_back(scalpel());
            break;
        }
        std::cout << "You should use scalpel at first\n";
    }

    while (scalpel_Uses.size() != 0) {
        input_Command(command);
        if (command == "scalpel") {
            scalpel_Uses.push_back(scalpel());
        }
        else if (command == "hemostat") {
            hemostat_Uses.push_back(hemostat());
        }
        else if (command == "tweezers") {
            tweezers_Uses.push_back(tweezers());
        }
        else if (command == "suture") {
            suture_Uses.push_back(suture());
        }
        else std::cout << "Unknown command. Retry your enter\n";
    }

    std::cout << "Operation is over!\n";
}
