//
// Created by asus on 25/01/2022.
//

#ifndef TRABALHOAED2_MENU_H
#define TRABALHOAED2_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "../Classes/Coordinates.h"
#include "../Classes/Time.h"

class Program;

using namespace std;

class Menu {
private:
    Program *program;

    bool inVector(char sel, vector<char> options);

    double readDoubleInput();

    Coordinates readCoordInput();

    string readTextInput();

    static int readIntInput();

    Time readTimeInput();

    Time readDateInput();

    char readOptionInput(const vector<char>& options);

    void askForLocation();

    void stopsNearLocation();

public:
    Menu(Program *program_);

    void programMenu();

    bool insertCoordinates();

    bool searchStopName();

    bool searchStopCode();
};


#endif //TRABALHOAED2_MENU_H
