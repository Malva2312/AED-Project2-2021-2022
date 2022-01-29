#include <iostream>
#include "MyGraph.h"


#include "Classes/Program.h"
/*
#include "MyGraph.h"
#include "MyGraph.cpp"

#include <unordered_map>
*/
template <class T> class MyGraph;
using namespace std;

int main() {

    Program prog = Program();
    prog.initializeProgram();
/*
    int min = 0;
    auto temp = prog.getAllStops();
    for(unsigned idx = 0;idx < temp.size(); idx++){
        if(temp.at(idx).getLines().size() > 1) min = min+1;
    }
    cout << endl << min << endl;
    */
/*
    //MyGraph<Stop> graph1 = prog.oportoMap_minDistance();
    Stop * stop1 = prog.findStopPtr("1AL2");
    //Stop * stop2 = prog.findStopPtr("ACNT2");
    MyGraph<Stop> graph = prog.oportoMap_minDist();
    auto bfs = graph.valueToBFS(*stop1);
    auto dijks = graph.dijkstraForOriginValue(*stop1);
    auto dist = dijks.first;
    auto pred = dijks.second;

    for (auto it : bfs){
        if (dist[it] == 0 && pred[it] == nullptr) cout << it->value.getCode() << " --- " << it->value.getName() << " --- " << "origin" << " --- " << dist[it] << endl;
        else{
            cout << it->value.getCode() << " --- " << it->value.getName() << " --- " << pred[it]->value.getName() << " --- " << dist[it] << endl;
        }
    }*/

/*
    string malva = "Malva";
    string andre = "Andre";
    string fonso = "Fonso";

    string ruben = "Ruben";
    string simao = "Simao";
    string jorge = "Jorge";
    string tiago = "Tiago";

    string dunno = "dunno";
    MyGraph<string> convivio = MyGraph<string>(malva);

    convivio.addNode(andre);
    convivio.addNode(fonso);
    convivio.addNode(ruben);
    convivio.addNode(simao);
    convivio.addNode(jorge);
    convivio.addNode(tiago);
    convivio.addNode(dunno);

    convivio.addEdge(malva, tiago,2);
    //convivio.addEdge(tiago, malva,2);

    //convivio.addEdge(malva, ruben, 5);
    convivio.addEdge(ruben, malva,5);

    convivio.addEdge(malva, andre, 1);
    //convivio.addEdge(andre, malva,1);

    //convivio.addEdge(andre, tiago,4);
    convivio.addEdge(tiago, andre,4);

    convivio.addEdge(andre, fonso,2);
    //convivio.addEdge(fonso, andre,2);

    convivio.addEdge(fonso, ruben,1);
    //convivio.addEdge(ruben, fonso,1);

    convivio.addEdge(fonso, jorge,2);
    //convivio.addEdge(jorge, fonso,2);

    //convivio.addEdge(jorge, simao,5);
    convivio.addEdge(simao, jorge,5);

    convivio.addEdge(ruben, simao,6);
    //convivio.addEdge(simao, ruben,6);

    convivio.addEdge(tiago, jorge,4);
    //convivio.addEdge(jorge, tiago,4);
/*
    auto vec = convivio.valueToBFS(malva);

    for (auto it = vec.begin(); it != vec.end(); it++){
        cout << (*it)->value << endl;
    }
*/
    //convivio.getAllNodesValues();
    //auto vec = convivio.getAllNodesPtr();
    //auto primo = convivio.prims(malva);

    //cout << primo.first;

    //auto dij = convivio.dijkstraForOriginValue(malva);
/*
    for(auto it = vec.begin(); it != vec.end(); it++){
        if (primo.second[(*it)->value] == (*it)->value ){
            cout << (*it)->value << " --- " << (*it)->value  << " --- " << "origin" << endl;
        }
        else{
            cout << (*it)->value << " --- " << primo.second[(*it)->value]  <<endl;// << " --- " << dij.second[*it]->value << endl;
        }
    }

    auto path = convivio.pathValues(malva, ruben);
    for (auto it : path){
        cout << it.first<< " ---" << it.second <<endl;
    }*/
    return 0;
}
