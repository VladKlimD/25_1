#pragma once
#include <iostream>
#include <vector>

struct coordinates {
    double coordinate_X = 0, coordinate_Y = 0;
};

int used_Coordinates_Check (coordinates& input_Coordinates, std::vector<coordinates>& used_Coordinates) {
    for (int i = 0; i < used_Coordinates.size(); i++) {
        if (used_Coordinates[i].coordinate_X == input_Coordinates.coordinate_X &&
            used_Coordinates[i].coordinate_Y == input_Coordinates.coordinate_Y) {
            return i;
        }
    }
    return -1;
}

void scalpel(std::vector<coordinates>& scalpel_Uses) {
    coordinates scalpel_Coordinates;
    for (;;) {
        std::cout << "Enter coordinates for scalpel:\n";
        std::cin >> scalpel_Coordinates.coordinate_X >> scalpel_Coordinates.coordinate_Y;
        if (used_Coordinates_Check(scalpel_Coordinates, scalpel_Uses) == -1) break;
        std::cout << "Those coordinates have already used by scalpel\n";
    }
    scalpel_Uses.push_back(scalpel_Coordinates);
    std::cout << "Scalpel is successfully used!\n";
}

void hemostat(std::vector<coordinates>& hemostat_Uses) {
    coordinates hemostat_Coordinates;
    for (;;) {
        std::cout << "Enter coordinates for scalpel:\n";
        std::cin >> hemostat_Coordinates.coordinate_X;
        if (used_Coordinates_Check(hemostat_Coordinates, hemostat_Uses) == -1) break;
        std::cout << "This coordinate has already used by hemostat\n";
    }
    hemostat_Uses.push_back(hemostat_Coordinates);
    std::cout << "Hemostat is successfully used!\n";
}

void tweezers(std::vector<coordinates>& tweezers_Uses) {
    coordinates tweezers_Coordinates;
    for (;;) {
        std::cout << "Enter coordinates for scalpel:\n";
        std::cin >> tweezers_Coordinates.coordinate_X;
        if (used_Coordinates_Check(tweezers_Coordinates, tweezers_Uses) == -1) break;
        std::cout << "This coordinate has already used by tweezers\n";
    }
    tweezers_Uses.push_back(tweezers_Coordinates);
    std::cout << "Tweezers are successfully used!\n";
}

void suture(std::vector<coordinates>& suture_Uses, std::vector<coordinates>& scalpel_Uses) {
    coordinates suture_Coordinates;
    int num_Of_Scalpel;
    for (;;) {
        std::cout << "Enter coordinates for scalpel:\n";
        std::cin >> suture_Coordinates.coordinate_X >> suture_Coordinates.coordinate_Y;
        num_Of_Scalpel = used_Coordinates_Check(suture_Coordinates, scalpel_Uses);
        if (num_Of_Scalpel != -1) break;
        std::cout << "Those coordinates haven't used by scalpel yet\n";
        std::cout << "You have cuts on the coordinates:\n";
        for (int i = 0; i < scalpel_Uses.size(); i++) {
            std::cout << scalpel_Uses[i].coordinate_X << " " << scalpel_Uses[i].coordinate_X << "\n";
        }
    }
    suture_Uses.push_back(suture_Coordinates);
    std::vector<coordinates>::iterator it = scalpel_Uses.begin();
    it += num_Of_Scalpel;
    scalpel_Uses.erase(it);
    std::cout << "Suture is successfully used!\n";
}