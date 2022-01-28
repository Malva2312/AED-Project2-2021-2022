//
// Created by asus on 25/01/2022.
//


#include "Program.h"
#include "../Classes/Stop.h"

Program::Program(){
    Menu newMenu = Menu(this);
    this-> menu = &newMenu;
    initializeProgram();
}

/**
 * Initializes every data necessary for executing tasks and the UI.
 * TODO: Malva, usa esta funcao para ler os ficheiros e guardar em graphs.
 */
void Program::initializeProgram() {
    //TODO: read stops
    //Add stops to graph


    // read to lines for each line

    //A1, B1, C1

    /*
     * 56
     * A1
     * C1
     */




    this->menu->programMenu();
}

void Program::setUserLocation(Coordinates coordinates) {
    this->userCoordinates = coordinates;
}

Coordinates Program::getUserLocation() {
    return this->userCoordinates;
}


Graph<Stop> Program::oportoMap(){
    vector<Stop> thisStops;
    for (vector<string> stp : Stop().read_stops("../dataset/stops.csv")) {
        thisStops.emplace_back(stp[1], stp[0], stp[2], stod(stp[3]), stod(stp[4]));
    }
    Graph<Stop> gRes(&thisStops[0]);

    for (int i = 1; i < thisStops.size(); ++i) {
        gRes.addNode(&thisStops[i]);
    }

    ifstream file("../dataset/lines.csv");

    if(!file.good()) {
        string FileNotGood = "Unable to read the lines file.";
        throw FileNotGood;
    }

    vector<Stop> all_stops;
    string line;
    getline(file, line); //clean header
    while(getline(file, line)){

    }
    return gRes;
}