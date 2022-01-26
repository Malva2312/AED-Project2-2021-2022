
#include "Graph.h"

template <class T, class W>
Graph<T, W>::Graph(T * firstNodeValue){

    Node<T, W> *firstNode = new Node<T, W>;
    firstNode->value = firstNodeValue;

    allNodes.push_back(firstNode);
    graphSize = allNodes.size();

}

template <class T, class W>
void Graph<T, W>::setAllNotVisited(){
    for (auto it = allNodes.begin(); it != allNodes.end(); it++){
        (*it)->visited = false;
    }
}

template<class T, class W>
std::vector<T *> Graph<T, W>::getAllNodesValues() const{

    std::vector<T *> allNodesValues;
    for (auto it = allNodes.begin(); it != allNodes.end(); it++){
        allNodesValues.push_back((*it)->value);
    }
    return allNodesValues;
}

template<class T, class W>
std::vector<Node<T, W> *> Graph<T, W>::getAllNodes() const {
    return allNodes;
}

template<class T, class W>
unsigned int Graph<T, W>::size() {
    return graphSize;
}

template<class T, class W>
void Graph<T, W>::addNode(Node<T, W> node) {
    allNodes.push_back(node);
    graphSize = allNodes.size();
}

template<class T, class W>
void Graph<T, W>::addNode(T *newNodeValue) {

    Node<T, W> *newNode = new Node<T, W>;
    newNode->value = newNodeValue;

    addNode(newNode);
}

template<class T, class W>
int Graph<T, W>::findNodeIndex(T * NodeValue) {
    for (int idx = 0; idx < size(); idx++){
        if( allNodes.at(idx)->value == NodeValue) return idx;
    }
    return -1;
}

template<class T, class W>
int Graph<T, W>::findNodeIndex(Node<T, W> node) {
    for (int idx = 0; idx < size(); idx++){
        if(node == allNodes.at(idx)) return idx;
    }
    return -1;
}

template<class T, class W>
bool Graph<T, W>::addEdge(T *nodeValue, T *  destNodeValue, W weight) {
    int idxOrigin = findNodeIndex(nodeValue);
    int idxDest = findNodeIndex(destNodeValue);

    if (idxOrigin < 0 || idxDest < 0){return false;}

    Edge<T, W> newEdge;
    newEdge.dest = allNodes.at(idxDest);
    newEdge.weight = weight;
    allNodes.at(idxOrigin)->adj.push_back(newEdge);
    return true;
}

template<class T, class W>
bool Graph<T, W>::addEdge(Node<T, W> *nodeOrigin, Node<T, W> nodeDest, W weight) {
    int idxOrigin = findNodeIndex(nodeOrigin);
    int idxDest = findNodeIndex(nodeOrigin);

    if (idxOrigin < 0 || idxDest < 0){return false;}

    Edge<T, W> newEdge;
    newEdge.dest = nodeDest;
    newEdge.weight = weight;

    allNodes.at(idxOrigin)->adj.push_back(newEdge);

    return true;
}

template<class T, class W>
void Graph<T, W>::removeNode(Node<T, W> node) {
    //TODO
}

template<class T, class W>
void Graph<T, W>::removeNode(T *value) {
    //TODO
}
