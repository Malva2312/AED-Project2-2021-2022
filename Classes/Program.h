//
// Created by asus on 25/01/2022.
//

#ifndef TRABALHOAED2_PROGRAM_H
#define TRABALHOAED2_PROGRAM_H

#include "Coordinates.h"

class Menu;

class Program {
private:
    void initializeProgram();

    Menu *menu;

    Coordinates userCoordinates = Coordinates(0,0,0,0,0,0);

public:
    Program();

    void setUserLocation(Coordinates coordinates);

    Coordinates getUserLocation();
};


#endif //TRABALHOAED2_PROGRAM_H
