//
// Created by asus on 25/01/2022.
//

#ifndef TRABALHOAED2_PROGRAM_H
#define TRABALHOAED2_PROGRAM_H

#include "Coordinates.h"
#include "Program.h"
#include "../UI/Menu.h"
#include "Graph.h"


class Menu;
class Stop;

class Program {
private:
    Menu *menu;

    Coordinates userCoordinates = Coordinates(0,0);

    vector<Stop> stops;

    // TODO: Um graph para o mapa todo, linhas incluidas. Planeias colocar uma variavel dentro de cada Node com a linha?
    static Graph<Stop> oportoMap(); //= new Graph<Stop> (new Stop());

    void initializeProgram();

public:
    Program();

    void setUserLocation(Coordinates coordinates);

    Coordinates getUserLocation();
};


#endif //TRABALHOAED2_PROGRAM_H
