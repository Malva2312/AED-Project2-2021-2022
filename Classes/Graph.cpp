
#include "Graph.h"

template <class T, class W>
Graph<T, W>::Graph(T * firstNodeValue, unsigned int size){

    this->graphSize = size;
    Node<T, W> * firstNode;
    firstNode->value = firstNodeValue;
    allNodes.push_back(firstNode);

}

template <class T, class W>
void Graph<T, W>::setAllNotVisited(){
    for (auto it = allNodes.begin(); it != allNodes.end(); it++){
        (*it)->visited = false;
    }
}

template<class T, class W>
std::vector<T *> Graph<T, W>::getAllNodesValues(){

    std::vector<T *> allNodesValues;
    for (auto it = allNodes.begin(); it != allNodes.end(); it++){
        allNodesValues.push_back((*it)->value);
    }
    return allNodesValues;
}