//
// Created by asus on 25/01/2022.
//

#include "Program.h"


Program::Program(){
     Menu newMenu = Menu(this);
    this-> menu = newMenu;
    this->userCoordinates = Coordinates(0,0);
    //initializeProgram();
}

/**
 * Initializes every data necessary for executing tasks and the UI.
 * TODO: Malva, usa esta funcao para ler os ficheiros e guardar em graphs.
 */
void Program::initializeProgram() {
    for (vector<string> stp : Stop().read_stops("../dataset/stops.csv")) {
        allStops.emplace_back(stp[1], stp[0], stp[2], stod(stp[3]), stod(stp[4]));
    }

    ifstream file("../dataset/lines.csv");

    if(!file.good()) {
        string FileNotGood = "Unable to read the lines file.";
        throw FileNotGood;
    }
    vector<string> linesText;
    string line;
    getline(file, line); //clean header
    while(getline(file, line)){
        linesText.push_back(line);
    }

    for (string busLine : linesText) {
        bool nocturn = false;
        std::size_t pos1 = busLine.find(",");      // position of the first "," in str
        std::string code = busLine.substr(0, pos1);
        std::size_t pos2 = busLine.find("-");
        std::size_t pos3 = busLine.substr(pos2).find("-");

        if (code.at(code.length()-1) == 'M')
            nocturn = true;

        Line thisLine(code, busLine.substr(pos3));
        ifstream file1("../dataset/line_" + code + "_0.csv");
        if(!file1.good()) {
            Line thisLine(code, busLine.substr(pos3));
            ifstream file1("../dataset/line_" + code + "_0.csv");
            if(!file1.good()) continue;
        }

        string lastStop = "";
        getline(file1, line); //clean header
        while(getline(file1, line)){
            Stop * stop = findStopPtr(line);
            stop->addLine(code);

            if (lastStop != "")
                thisLine.addConnection(lastStop, line, 0);

            lastStop = line;
        }


        ifstream file2("../dataset/line_" + code + "_1.csv");
        if(!file2.good()) continue;

        lastStop = "";
        getline(file2, line); //clean header
        while(getline(file2, line)){
            Stop * stop = findStopPtr(line);
            stop->addLine(code);

            if (lastStop != "")
                thisLine.addConnection(lastStop, line, 0);

            lastStop = line;
        }
        if (!nocturn)
            this->dayLines.push_back(thisLine);
        else
            this->nightLines.push_back(thisLine);
    }

    this->menu.programMenu();
}

void Program::setUserLocation(Coordinates coordinates) {
    this->userCoordinates = coordinates;
}

Coordinates Program::getUserLocation() {
    return this->userCoordinates;
}

bool Program::getNightSchedule() {
    return this->nightSchedule;
}

void Program::setNightSchedule(bool nightSchedule_) {
    this->nightSchedule = nightSchedule_;
}

MyGraph<Stop> Program::loadStopsToNodes(MyGraph<Stop> &emptyGraph){

    for (Stop stp : this->allStops)
        emptyGraph.addNode(stp);
    return emptyGraph;
}

MyGraph<Stop> Program::loadLineEdges_minDist(MyGraph<Stop> &graph){

    for (Line line : ((getNightSchedule()) ? this->nightLines : this->dayLines)) {
        if (line.available){loadConnectionsEdges_minDist(graph, line);}
    }
    return graph;
}
void Program::loadConnectionsEdges_minDist(MyGraph<Stop> &graph, Line line){
    for (Connection con : line.connections) {
        Stop org = findStop(con.org);
        Stop dest = findStop(con.dest);
        if (dest.getCode() == "" || org.getCode() == "")
            continue;
        graph.addEdge(org, dest, org.getCoordinates() - dest.getCoordinates());
    }
}
MyGraph<Stop> Program::oportoMap_minDist(){
    MyGraph<Stop> newGraph = MyGraph<Stop>();
    loadStopsToNodes(newGraph);

    loadLineEdges_minDist(newGraph);
    return newGraph;
}

MyGraph<Stop> Program::loadLineEdges_minStops(MyGraph<Stop> &graph){
    for (Line line : ((getNightSchedule()) ? this->nightLines : this->dayLines)) {
        if (line.available){loadConnectionsEdges_minStops(graph, line);}
    }
    return graph;
}
void Program::loadConnectionsEdges_minStops(MyGraph<Stop> &graph, Line line){
    for (Connection con : line.connections) {
        Stop org = findStop(con.org);
        Stop dest = findStop(con.dest);
        if (dest.getCode() == "" || org.getCode() == "")
            continue;
        graph.addEdge(org, dest, 1);
    }
}
MyGraph<Stop> Program::oportoMap_minStops(){
    MyGraph<Stop> newGraph = MyGraph<Stop>();
    loadStopsToNodes(newGraph);

    loadLineEdges_minStops(newGraph);
    return newGraph;
}

Stop * Program::findStopPtr(string code){
   int high = allStops.size() -1;
    unsigned int low = 0;

    while (low <= high) {
        unsigned int mid = low + (high - low) / 2;

        if (allStops.at(mid).getCode() == code)
            return &allStops.at(mid);

        else if (allStops.at(mid).getCode() < code)
            low = mid + 1;
        else if (code < allStops.at(mid).getCode())
            high = mid - 1;
    }
    return nullptr;
}

Stop Program::findStop(string code){
    unsigned int high = allStops.size() -1;
    unsigned int low = 0;
    unsigned int mid;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (allStops.at(mid).getCode() == code)
            return allStops.at(mid);

        else if (allStops.at(mid).getCode() < code)
            low = mid + 1;
        else if (code < allStops.at(mid).getCode())
            high = mid - 1;
    }
    return {"", "", "", Coordinates(0, 0)};
}


Stop Program::findStopByName(string name){
    for (auto stop: allStops) {
        if(stop.getName() == name)
            return stop;
    }
    return {"", "", "", Coordinates(0, 0)};
}

vector<Stop *> Program::closestStops(){
    Coordinates userCoord = this->getUserLocation();

    vector<Stop *> res;
    for (auto it = allStops.begin(); it != allStops.end(); it++){
        res.push_back(&(*it));
    }
    sort(res.begin(), res.end(),
         [&userCoord ](const Stop * A, const Stop * B){
                return (A->getCoordinates() - userCoord) < (B->getCoordinates() - userCoord) ;
    } );

    return res;
}

Line Program::getLineByCode(std::string code) {
    for (auto line : this->dayLines)
        if (line.code == code)
            return line;
    for (auto line : this->nightLines)
        if (line.code == code)
            return line;
    return {"", ""};
}

/*
void addLineToGraph(string file_line){

}
*/
vector<Stop> Program::shortestPath(MyGraph<Stop> graph, Stop origin, Stop dest){
    //graph.dijkstraForOriginValue(origin);
    auto var = graph.dijkstraForOriginValue(origin);
    auto path = var.second;


    vector<Stop> res;

    int idx = graph.findNodeIndex(dest);
    if (idx < 0) return res;
    Node<Stop> * nodePtr = graph.getAllNodesPtr().at(idx);
    cout<<nodePtr->value.getCode();
    while(path[nodePtr] != nullptr){

        res.push_back(nodePtr->value);
        nodePtr = path[nodePtr];
    }
    res.push_back(nodePtr->value);
    return res;
}

std::vector<Stop> Program::getAllStops() {
    return allStops;
}

vector<Line> Program::getLines() {
    return ((getNightSchedule()) ? this->nightLines : this->dayLines);
}

std::vector<Stop *> Program::getAllStopsPtr() {
    vector<Stop * > temp;

    for (auto it = allStops.begin(); it != allStops.end(); it++){
        temp.push_back(&(*it));
    }
    return temp;
}

vector<Stop * > Program::closestInRange(Coordinates coord, double range){
    vector<Stop *> orderedByDistance = closestStops();
    vector<Stop *> res;

    copy_if(closestStops().begin(), closestStops().end(), back_inserter(res), [&coord,&range](const Stop * A){
        return Stop().getCoordinates() - coord <= range;
    });
    return res;
}


MyGraph<Stop> Program::choosePath(int x){
    switch (x) {
        case 1:
            return oportoMap_minDist();
        case 2:
            return oportoMap_minStops();
        default:
            return MyGraph<Stop>();
    }
}

pair<double, pair<Stop, Stop>> Program::bestPath(Coordinates orig, Coordinates dest, double rangeStart, double rangeEnd, int opt){
    MyGraph<Stop> graph = choosePath(opt);
    vector<Stop *> allStarts = closestInRange(orig, rangeStart);
    vector<Stop *> allEnds = closestInRange(dest, rangeEnd);

    pair<double, pair<Stop, Stop>> minDis;

    minDis.first = DBL_MAX;

    for(Stop* i : allStarts){
        for(Stop* ii : allEnds){
            if (graph.pathValues(*i, *ii).at(0).second < minDis.first){
                minDis.second.first = *i;
                minDis.second.second = *ii;
            }
        }
    }
    return pair<double, pair<Stop, Stop>>();
}

