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
    /**
     * Cretes an object of the stuct Connection
     * @param org_
     * @param dest_
     * @param dir_
     */
    Connection(std::string org_, std::string dest_, int dir_) : org(org_), dest(dest_), dir(dir_) {}
    std::string org;
    std::string dest;
    int dir;
};

struct Line {
    /**
     * Creates an object of the struct Line
     * @param code_
     * @param name_
     */
    Line(std::string code_, std::string name_) : code(code_), name(name_) {}
    /**
     * Adds a new connection between two stops in a Line
     * @param org_
     * @param dest_
     * @param dir_
     */
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

    double range = 0; //m //changeable but not on running

public:
    /**
     * Initializes the menu
     */
    Program();
    /**
     * Reads the files from the dataset so that they are ready to use
     */
    void initializeProgram();

    /**
     * Returns all Stops in a vector
     * @return
     */
    std::vector<Stop> getAllStops();
    /**
     * Returns all Stops' pointers
     * @return
     */
    std::vector<Stop *>getAllStopsPtr();

    /**
     * Sets the location of the user given its coordinates
     * @param coordinates
     */
    void setUserLocation(Coordinates coordinates);

    /**
     * Returns the user's location
     * @return
     */
    Coordinates getUserLocation();

    /**
     * Returns the available lines at night
     * @return
     */
    bool getNightSchedule();

    /**
     * Sets the night schedule to 'true' or 'false'
     * @param nightSchedule_
     */
    void setNightSchedule(bool nightSchedule_);

    /**
     * Returns the Stop's pointer given its code
     * @param code
     * @return
     */
    Stop* findStopPtr(string code);

    /**
     * Returns the Stop's value given its code
     * @param code
     * @return
     */
    Stop findStop(string code); //BinarySearch so para o professor gostar lololololol

    /**
     * Returns the Stop's value given its name
     * @param name
     * @return
     */
    Stop findStopByName(string name);

    // TODO: Um graph para o mapa todo, linhas incluidas. Planeias colocar uma variavel dentro de cada Node com a linha?
    /**
     * Returns the map's graph in order to after obtain the minimum distance between stops
     * @return
     */
    MyGraph<Stop> oportoMap_minDist(); //= new Graph<Stop> (new Stop());
    /**
     * Returns the map's graph in order to after obtain a trip with minimum stops
     * @return
     */
    MyGraph<Stop> oportoMap_minStops();

    /**
     * Returns a vector of the closest Stops sorted by distance
     * @return
     */
    vector<Stop *> closestStops(Coordinates userCoord);

    /**
     * Returns a certain Line given its code
     * @param code
     * @return
     */
    Line getLineByCode(std::string code);

    /**
     * Returns all Lines
     * @return
     */
    vector<Line> getLines();

    /**
     * Returns the shortest path between two stops
     * @param graph
     * @param origin
     * @param dest
     * @return
     */
    vector<Stop> shortestPath(MyGraph<Stop> graph, Stop origin, Stop dest);

    /**
     * Loads all stops into a graph's nodes
     * @param emptyGraph
     * @return
     */
    MyGraph<Stop> loadStopsToNodes(MyGraph<Stop> &emptyGraph);

    /**
     * Checks if a line is available in order to load the edges of a node
     * @param graph
     * @return
     */
    MyGraph<Stop> loadLineEdges_minStops(MyGraph<Stop> &graph);
    /**
     * Loads all edges as a unitary value between Stops in order to get the path with minimum stops
     * @param graph
     * @param line
     */
    void loadConnectionsEdges_minStops(MyGraph<Stop> &graph, Line line);

    /**
     * Checks if a line is available in order to load the edges of a node
     * @param graph
     * @return
     */
    MyGraph<Stop> loadLineEdges_minDist(MyGraph<Stop> &graph);
    /**
     * Loads all edges as the distance between two stops in order to get the shortest path
     * @param graph
     * @param line
     */
    void loadConnectionsEdges_minDist(MyGraph<Stop> &graph, Line line);

    /**
     * Returns a vector with all Stops close to given coordinates within a certain range
     * @param coord
     * @param range
     * @return
     */
    vector<Stop *> closestInRange(Coordinates coord, double range);

    /**
     * Chooses the option to filter the kind of path someone wants
     * @param x
     * @return
     */
    MyGraph<Stop> choosePath(int x);

    /**
     *
     * @param orig
     * @param dest
     * @param rangeStart
     * @param rangeEnd
     * @param opt
     * @return
     */
    pair<double, pair<Stop, Stop>> bestPath(Coordinates orig, Coordinates dest, double rangeStart, double rangeEnd, int opt);

    /**
     * Adds edges to a graph representing walking paths
     * @param opt
     * @param graph
     * @param start
     * @return
     */
    void addWalk(int opt, MyGraph<Stop> &graph, Stop start);
};


#endif //TRABALHOAED2_PROGRAM_H
