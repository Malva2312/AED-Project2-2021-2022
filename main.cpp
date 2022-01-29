#include <iostream>


#include "Classes/Program.h"
/*
#include "MyGraph.h"
#include "MyGraph.cpp"
*/
#include <unordered_map>

template <class T> class MyGraph;
using namespace std;

int main() {

    //Graph<string> teste = Graph<string>
    //Program();
/*
    string malva = "Malva";
    string andre = "Andre";
    string fonso = "Fonso";

    string ruben = "Ruben";
    string simao = "Simao";
    string jorge = "Jorge";
    string tiago = "Tiago";

    string dunno = "dunno";
    MyGraph<string> convivio(malva);

    convivio.addNode(andre);
    convivio.addNode(fonso);
    convivio.addNode(ruben);
    convivio.addNode(simao);
    convivio.addNode(jorge);
    convivio.addNode(tiago);
    convivio.addNode(dunno);

    convivio.addEdge(malva, tiago,2);
    convivio.addEdge(tiago, malva,2);

    convivio.addEdge(malva, ruben, 5);
    convivio.addEdge(ruben, malva,5);

    convivio.addEdge(malva, andre, 1);
    convivio.addEdge(andre, malva,1);

    convivio.addEdge(andre, tiago,4);
    convivio.addEdge(tiago, andre,4);

    convivio.addEdge(andre, fonso,2);
    convivio.addEdge(fonso, andre,2);

    convivio.addEdge(fonso, ruben,1);
    convivio.addEdge(ruben, fonso,1);

    convivio.addEdge(fonso, jorge,2);
    convivio.addEdge(jorge, fonso,2);

    convivio.addEdge(jorge, simao,5);
    convivio.addEdge(simao, jorge,5);

    convivio.addEdge(ruben, simao,6);
    convivio.addEdge(simao, ruben,6);

    convivio.addEdge(tiago, jorge,4);
    convivio.addEdge(jorge, tiago,4);

    auto vec = convivio.valueToBFS(malva);

    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << (*it)->value << endl;
    }

    convivio.dijkstraForOriginValue(malva);
    //convivio.getAllNodesValues();
    auto vec = convivio.getAllNodesPtr();
    auto dij = convivio.dijkstraForOriginValue(malva);

    for(auto it = vec.begin(); it != vec.end(); it++){
        if (dij.second[*it] == nullptr){
            cout << (*it)->value << " --- " << dij.first[*it]  << " --- " << "origin" << endl;
        }
        else{
            cout << (*it)->value << " --- " << dij.first[*it]  << " --- " << dij.second[*it]->value << endl;
        }
    }*/
    Program prog = Program();
    prog.initializeProgram();
    /*
    Stop stop1 = Stop();
    stop1.setCode("1SBNT2");
    Stop stop2 = Stop();
    stop2.setCode("1AL2");
    auto vec = prog.shortestPath(prog.oportoMap_distance(), stop1, stop2);

    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << it->getCode() << "  :  " << it->getName() << "  ::  " << it->getCoordinates() - prog.allStops.at(0).getCoordinates()<< endl;
    }
*/
    return 0;
}
