//
// Created by asus on 25/01/2022.
//

#ifndef TRABALHOAED2_MENU_H
#define TRABALHOAED2_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "../Classes/Coordinates.h"


class Program;
class Stop;

using namespace std;

class Menu {
private:
    Program *program;

    /**
     * Checks if a certain char is in the vector
     * @param sel
     * @param options
     * @return
     */
    bool inVector(char sel, vector<char> options);

    /**
     * Reads a double from the terminal
     * @return
     */
    double readDoubleInput();

    /**
     * Reads coordinates from the terminal
     * @return
     */
    Coordinates readCoordInput();

    /**
     * Reads tet input from the terminal
     * @return
     */
    string readTextInput();

    /**
     * Reads an option input  from the terminal
     * @param options
     * @return
     */
    char readOptionInput(const vector<char>& options);

    /**
     * Asks for the user's location
     */
    void askForLocation();

    /**
     * Returns the Stops near a certain location
     * @param viewMode_
     * @return
     */
    string stopsNearLocation(bool viewMode_);

    /**
     * Select from the Stop's menu
     * @return
     */
    string stopSelecting();

    /**
     * Select a Stop from a certain line, which is shown on screen
     * @param lineName_
     * @return
     */
    string stopSelector(string lineName_);

    /**
     * Selects an option on the Line menu
     * @return
     */
    string lineSelector();

    /**
     * Shows the Stop's info
     * @param stop_
     */
    void stopInfo(string code_);

    /**
     * Shows information about the map
     */
    void seeMap();

    /**
     * Selects a path for the user
     * @param orgCode
     * @param destCode
     */
    void travel(string orgCode, string destCode);

    /**
     * Allows the user to choose what to prioritize in his trip (distance, minimum stops, minimum lines, minimum zones)
     * @param orgCode
     * @param destCode
     */
    void displayBestAlternatives(string orgCode, string destCode);

public:
    /**
     * Sets the program value
     * @param program_
     */
    Menu(Program *program_);

    /**
     * Sets the Initial menu
     */
    void programMenu();

    /**
     * Checks if coordinates were inserted
     * @return
     */
    bool insertCoordinates();

    /**
     * Finds a stop by its name
     * @return
     */
    bool searchStopName();

    /**
     * Finds a Stop code
     * @return
     */
    bool searchStopCode();

};


#endif //TRABALHOAED2_MENU_H
