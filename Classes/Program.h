//
// Created by asus on 25/01/2022.
//

#ifndef TRABALHOAED2_PROGRAM_H
#define TRABALHOAED2_PROGRAM_H

#include "Coordinates.h"
#include "Program.h"
#include "../UI/Menu.h"
#include "../Classes/Graph.h"

class Menu;

class Program {
private:
    Menu *menu;

    Coordinates userCoordinates = Coordinates(0,0);

    // TODO: Um graph para o mapa todo, linhas incluidas. Planeias colocar uma variavel dentro de cada Node com a linha?
    Graph<string, int> oportoMap = NULL;
    //TODO: vector de graphs para as linhas, pode vir a ser util para planear
    vector<Graph<string, int>> lines;

    void initializeProgram();

public:
    Program();

    void setUserLocation(Coordinates coordinates);

    Coordinates getUserLocation();
};


#endif //TRABALHOAED2_PROGRAM_H
