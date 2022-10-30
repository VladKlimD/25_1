#pragma once
#include <iostream>
#include <vector>

enum operation_Types {
    SCALPEL,
    HEMOSTAT,
    TWEEZERS,
    SUTURE
};

struct coordinates {
    double coordinate_X, coordinate_Y;
    operation_Types operation_Type;
};

std::vector<coordinates> scalpel_Uses, hemostat_Uses, tweezers_Uses, suture_Uses;

int operation_Check(coordinates& planning_Operation, std::vector<coordinates>& operation_Uses) {
    for (int i = 0; i < operation_Uses.size(); i++) {
        if ((planning_Operation.operation_Type == SCALPEL || planning_Operation.operation_Type == SUTURE)
            && operation_Uses[i].coordinate_X == planning_Operation.coordinate_X &&
            operation_Uses[i].coordinate_Y == planning_Operation.coordinate_Y) return i;

        if ((planning_Operation.operation_Type == HEMOSTAT || planning_Operation.operation_Type == TWEEZERS)
            && operation_Uses[i].coordinate_X == planning_Operation.coordinate_X) return i;
    }
    return -1;
}

coordinates scalpel() {
    coordinates scalpel_Coordinates = {.operation_Type = SCALPEL};
    for (;;) {
        std::cout << "Enter coordinates of the incision:\n";
        std::cin >> scalpel_Coordinates.coordinate_X >> scalpel_Coordinates.coordinate_Y;
        if (operation_Check(scalpel_Coordinates, scalpel_Uses) == -1) break;
        std::cout << "Scalpel was already used here. Retry your enter\n";
    }
    std::cout << "Scalpel was used in coordinates: ";
    std::cout << scalpel_Coordinates.coordinate_X << " " << scalpel_Coordinates.coordinate_Y << "\n";
    return scalpel_Coordinates;
}

coordinates hemostat() {
    coordinates hemostat_Coordinates = {.operation_Type = HEMOSTAT};
    for (;;) {
        std::cout << "Enter coordinate:\n";
        std::cin >> hemostat_Coordinates.coordinate_X;
        if (operation_Check(hemostat_Coordinates, hemostat_Uses) == -1) break;
        std::cout << "Hemostat was already used here. Retry your enter\n";
    }
    std::cout << "Hemostat was used in coordinate: " << hemostat_Coordinates.coordinate_X << "\n";
    return hemostat_Coordinates;
}

coordinates tweezers() {
    coordinates tweezers_Coordinates = {.operation_Type = TWEEZERS};
    for (;;) {
        std::cout << "Enter coordinate:\n";
        std::cin >> tweezers_Coordinates.coordinate_X;
        if (operation_Check(tweezers_Coordinates, tweezers_Uses) == -1) break;
        std::cout << "Tweezers were already used here. Retry your enter\n";
    }
    std::cout << "Tweezers were used in coordinate: " << tweezers_Coordinates.coordinate_X << "\n";
    return tweezers_Coordinates;
}

coordinates suture() {
    coordinates suture_Coordinates = {.operation_Type = SUTURE};
    int num_Of_Incision;
    for (;;) {
        std::cout << "Enter coordinates of the incision:\n";
        std::cin >> suture_Coordinates.coordinate_X >> suture_Coordinates.coordinate_Y;
        num_Of_Incision = operation_Check(suture_Coordinates, scalpel_Uses);
        if (num_Of_Incision != -1) break;
        std::cout << "Wrong coordinates for suturing. Incisions are on:\n";
        for (int i = 0; i < scalpel_Uses.size(); i++) {
            std::cout << "X:" << scalpel_Uses[i].coordinate_X << " ";
            std::cout << "Y:" << scalpel_Uses[i].coordinate_Y << std::endl;
        }
        std::cout << "Retry your enter\n";
    }
    std::cout << "Suture was used in coordinates: ";
    std::cout << suture_Coordinates.coordinate_X << " " << suture_Coordinates.coordinate_Y << "\n";
    std::vector<coordinates>::iterator it = scalpel_Uses.begin();
    it += num_Of_Incision;
    scalpel_Uses.erase(it);
    return suture_Coordinates;
}