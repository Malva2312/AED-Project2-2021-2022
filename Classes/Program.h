//
// Created by asus on 25/01/2022.
//

#ifndef TRABALHOAED2_PROGRAM_H
#define TRABALHOAED2_PROGRAM_H

#include "Coordinates.h"
#include "../UI/Menu.h"
#include "../MyGraph.h"
#include "../MyGraph.cpp"
#include "../Classes/Stop.h"

class Menu;
class Stop;
template <class T> class MyGraph;

struct Connection {
    Connection(std::string org_, std::string dest_, int dir_) : org(org_), dest(dest_), dir(dir_) {}
    std::string org;
    std::string dest;
    int dir;
};

struct Line {
    Line(std::string code_, std::string name_) : code(code_), name(name_) {}
    void addConnection(std::string org_, std::string dest_, int dir_) {
        connections.emplace_back(org_, dest_, dir_);
    }
    std::string code;
    std::string name;
    vector<Connection> connections;
    bool available = true;
};

class Program {
private:
    bool nightSchedule = false;

    std::vector<Stop> allStops;

    Menu menu = Menu(nullptr);

    Coordinates userCoordinates = Coordinates(0,0);

    std::vector<Line> dayLines;

    std::vector<Line> nightLines;

public:
    Program();
    void initializeProgram();

    std::vector<Stop> getAllStops();
    std::vector<Stop *>getAllStopsPtr();

    void setUserLocation(Coordinates coordinates);

    Coordinates getUserLocation();

    bool getNightSchedule();

    void setNightSchedule(bool nightSchedule_);

    Stop* findStopPtr(string code);

    Stop findStop(string code); //BinarySearch so para o professor gostar lololololol

    Stop findStopByName(string name);

    // TODO: Um graph para o mapa todo, linhas incluidas. Planeias colocar uma variavel dentro de cada Node com a linha?
    MyGraph<Stop> oportoMap_minDist(); //= new Graph<Stop> (new Stop());
    MyGraph<Stop> oportoMap_minStops();


    vector<Stop *> closestStops();

    Line getLineByCode(std::string code);

    vector<Line> getLines();

    vector<Stop> shortestPath(MyGraph<Stop> graph, Stop origin, Stop dest);

    MyGraph<Stop> loadStopsToNodes(MyGraph<Stop> &emptyGraph);

    MyGraph<Stop> loadLineEdges_minStops(MyGraph<Stop> &graph);
    void loadConnectionsEdges_minStops(MyGraph<Stop> &graph, Line line);

    MyGraph<Stop> loadLineEdges_minDist(MyGraph<Stop> &graph);
    void loadConnectionsEdges_minDist(MyGraph<Stop> &graph, Line line);

    vector<Stop *> closestInRange(Coordinates coord, double range);

    MyGraph<Stop> choosePath(int x);

    pair<double, pair<Stop, Stop>> bestPath(Coordinates orig, Coordinates dest, double rangeStart, double rangeEnd, int opt);
};


#endif //TRABALHOAED2_PROGRAM_H
