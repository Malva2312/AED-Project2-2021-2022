#include <iostream>


#include "Classes/Stop.h"
#include "UI/Menu.h"
#include "Classes/Program.h"

#include "Classes/Graph.h"
#include "Classes/Graph.cpp"

template <class T> class Graph;
class Stop;
using namespace std;

int main() {/*
    vector<vector<string>> test = Stop().read("../dataset/stops.csv");

    for (auto it = test.begin(); it != test.end(); it++){
        for (auto ii = it->begin(); ii!= it->end(); ii++){
            cout << (*ii) << " , ";
        }
        cout << endl;
    }

    Program();
*/
    string nodeVal1 = "Malva";
    string nodeVal2 = "Andre";
    string nodeVal3 = "Fonso";

    string nodeVal4 = "Ruben";
    string nodeVal5 = "Simao";
    string nodeVal6 = "Jorge";
    string nodeVal7 = "Tiago";


    Graph<string> convivio(&nodeVal1);

    convivio.addNode(&nodeVal2);
    convivio.addNode(&nodeVal3);
    convivio.addNode(&nodeVal4);
    convivio.addNode(&nodeVal5);
    convivio.addNode(&nodeVal6);
    convivio.addNode(&nodeVal7);

    /* simple test
     * Malva <-> Andre <-> Fonso <-> Ruben <->Simao <->Jorge <-> Tiago
     * com peso crescente
     * 1, 2, 3, 4, 5, 6
     */
    convivio.addEdge(&nodeVal1, &nodeVal2, 1);
    convivio.addEdge(&nodeVal2, &nodeVal1, 1);
    convivio.addEdge(&nodeVal2, &nodeVal3, 2);
    convivio.addEdge(&nodeVal3, &nodeVal2, 2);
    convivio.addEdge(&nodeVal3, &nodeVal4, 3);
    convivio.addEdge(&nodeVal4, &nodeVal3, 3);
    convivio.addEdge(&nodeVal4, &nodeVal5, 4);
    convivio.addEdge(&nodeVal5, &nodeVal4, 4);
    convivio.addEdge(&nodeVal5, &nodeVal6, 5);
    convivio.addEdge(&nodeVal6, &nodeVal5, 5);
    convivio.addEdge(&nodeVal6, &nodeVal7, 6);
    convivio.addEdge(&nodeVal7, &nodeVal6, 6);
    /**/
    convivio.addEdge(&nodeVal1, &nodeVal7, 1);
    convivio.addEdge(&nodeVal7, &nodeVal1, 1);
    /* simple test for graph
     * without weight
     */
    /*
    convivio.addEdge(&nodeVal1, &nodeVal2, 0);
    convivio.addEdge(&nodeVal1, &nodeVal3, 0);

    convivio.addEdge(&nodeVal2, &nodeVal3, 0);
    convivio.addEdge(&nodeVal2, &nodeVal1, 0);

    convivio.addEdge(&nodeVal3, &nodeVal1, 0);
    convivio.addEdge(&nodeVal3, &nodeVal2, 0);

    convivio.addEdge(&nodeVal1, &nodeVal4, 0);

    convivio.addEdge(&nodeVal4, &nodeVal5, 0);
    convivio.addEdge(&nodeVal4, &nodeVal7, 0);
    convivio.addEdge(&nodeVal5, &nodeVal6, 0);
    */

    vector<string *> teste = convivio.BFS(convivio.getAllNodes().at(0));
/*
    for (auto it = teste.begin(); it != teste.end(); it++) {
        cout << *(*it) << endl;
    }*/

    auto res = convivio.dijkstraForOriginValue(&nodeVal1);

    auto allNodes = convivio.getAllNodes();

    for (auto it = allNodes.begin(); it != allNodes.end(); it++){
        if ((*it)->value == &nodeVal1) continue;  //skip a origem pq o node precedente é nullptr
        //valor do node --- distancia ao nó de origem do algoritmo --- valor do node precedente
        cout << *(*it)->value << " --- " << *res.first[*it] << " --- "  << *res.second[*it]->value << endl;
    }

}