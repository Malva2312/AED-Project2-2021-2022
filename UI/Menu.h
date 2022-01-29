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
class Stop;

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

    string stopsNearLocation(bool viewMode_);

    string stopSelecting();

    string stopSelector(string lineName_);

    string lineSelector();

    void stopInfo(Stop* stop_);

    void seeMap();

    void travel(string orgCode, string destCode);


public:
    Menu(Program *program_);

    void programMenu();

    bool insertCoordinates();

    bool searchStopName();

    bool searchStopCode();

};


#endif //TRABALHOAED2_MENU_H
