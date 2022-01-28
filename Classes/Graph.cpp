
#include <map>
#include "Graph.h"

template <class T>
Graph<T>::Graph(){
    graphSize = 0;
}

template <class T>
Graph<T>::Graph(T * firstNodeValue){

    auto *firstNode = new Node<T>;
    firstNode->value = firstNodeValue;

    allNodes.push_back(firstNode);
    graphSize = allNodes.size();

}

template <class T>
void Graph<T>::setAllNotVisited(){
    for (auto it = allNodes.begin(); it != allNodes.end(); it++){
        (*it)->visited = false;
    }
}

template <class T>
std::vector<T *> Graph<T>::getAllNodesValues() const{

    std::vector<T *> allNodesValues;
    for (auto it = allNodes.begin(); it != allNodes.end(); it++){
        allNodesValues.push_back((*it)->value);
    }
    return allNodesValues;
}

template<class T>
std::vector<Node<T> *> Graph<T>::getAllNodes() const {
    return allNodes;
}

template<class T>
unsigned int Graph<T>::size() {
    return allNodes.size();
}

template<class T>
void Graph<T>::addNode(Node<T> * node) {
    allNodes.push_back(node);
    graphSize = size();
}

template<class T>
void Graph<T>::addNode(T * newNodeValue) {

    auto *newNode = new Node<T>;
    newNode->value = newNodeValue;

    addNode(newNode);
}

template<class T>
int Graph<T>::findNodeIndex(T * NodeValue) {
    for (int idx = 0; idx < size(); idx++){
        if( allNodes.at(idx)->value == NodeValue) return idx;
    }
    return -1;
}

template<class T>
int Graph<T>::findNodeIndex(Node<T> node) {
    for (int idx = 0; idx < size(); idx++){
        if(node == allNodes.at(idx)) return idx;
    }
    return -1;
}

template<class T>
bool Graph<T>::addEdge(T *nodeValue, T *  destNodeValue, double weight) {
    int idxOrigin = findNodeIndex(nodeValue);
    int idxDest = findNodeIndex(destNodeValue);

    if (idxOrigin < 0 || idxDest < 0){return false;}

    Edge<T> newEdge;
    newEdge.dest = allNodes.at(idxDest);
    newEdge.weight = weight;

    allNodes.at(idxOrigin)->adj.push_back(newEdge);

    return true;
}

template<class T>
bool Graph<T>::addEdge(Node<T> *nodeOrigin, Node<T> nodeDest, double weight) {
    //int idxOrigin = findNodeIndex(nodeOrigin);
    //int idxDest = findNodeIndex(nodeOrigin);

    //if (idxOrigin < 0 || idxDest < 0){return false;}

    Edge<T> newEdge;
    newEdge.dest = nodeDest;
    newEdge.weight = weight;

    nodeOrigin->adj.push_back(newEdge);

    return true;
}

template<class T>
void Graph<T>::removeNode(Node<T> node) {
    //TODO //graphsize = size()
}

template<class T>
void Graph<T>::removeNode(T *value) {
    //TODO //graphsize = size()
}

template<class T>
void Graph<T>::setVisitedTrue(Node<T> * node) {
    node->visited  = true;
}

template<class T>
void Graph<T>::addAdjToQueue(Node<T> *node, std::queue<Node<T>*>  &nodesQueue) {
    setVisitedTrue(node);

    for (auto it = node->adj.begin(); it != node->adj.end(); it++){
        if(it->dest->visited == false) {
            nodesQueue.push(it->dest);
        }
    }
}

template<class T>
std::vector<T *> Graph<T>::BFS(Node<T> * node) {
    //if (findNodeIndex(node) < 0) return {};

    setAllNotVisited();

    std::queue<Node<T> *> nodesQueue;
    std::vector<T * > nodeValuesPath = {node->value};

    addAdjToQueue(node,nodesQueue);

    while (nodesQueue.empty() == false){
        node = nodesQueue.front();
        nodesQueue.pop();

        addAdjToQueue(node,  nodesQueue);

        nodeValuesPath.push_back(node->value);
    }
    return nodeValuesPath;
}

template<class T>
std::vector<T *> Graph<T>::valueToBFS(T *nodeValue) {
    return BFS(allNodes.at(findNodeIndex(nodeValue)));
}

template<class T>
std::pair<
        std::unordered_map<Node<T>*, double * >,
        std::unordered_map<Node<T>*, Node<T> *>>
Graph<T>::dijkstraForOriginValue(T * originNode) {
    int idx = findNodeIndex(originNode);
    //if (idx < 0) return nullptr;

    return dijkstraForOrigin(allNodes.at(idx));
}

template<class T>
std::pair<
        std::unordered_map<Node<T>*, double * >,
        std::unordered_map<Node<T>*, Node<T> *>>
Graph<T>::dijkstraForOrigin(Node<T> *originNode) {
    //int idx = findNodeIndex(*originNode);
    //if (findNodeIndex(originNode) < 0) return nullptr;


    std::vector<std::pair <Node<T> *, double*>> myPriorityNodesQueue;
    std::unordered_map<Node<T>*, double * > distMap;
    std::unordered_map<Node<T>*, Node<T> *> predOfKey;

    for (auto it = allNodes.begin(); it != allNodes.end(); it++){

        double *x = new double;
        distMap[*it] = x;

        if (* it  == originNode){
            (*distMap[*it]) = 0;
            predOfKey[*it] = nullptr;
        }
        else (*distMap[*it]) = DBL_MAX;

        (*it)->visited = false;

        std::pair <Node<T> *, double *> temp;
        temp.first = *it;
        temp.second = x;

        myPriorityNodesQueue.push_back(temp);
    }




    while(!myPriorityNodesQueue.empty()) {

        sortMyPriorityNodesQueue(myPriorityNodesQueue);

        auto node = myPriorityNodesQueue.front();
        myPriorityNodesQueue.erase(myPriorityNodesQueue.begin());
        node.first->visited = true;

        for (auto it = node.first->adj.begin(); it != node.first->adj.end() ; it++){

            if(it->dest->visited== false
            && (*distMap[node.first]) + it->weight < (*distMap[it->dest])){
                (*distMap[it->dest]) =  (*distMap[node.first]) + it->weight;
                predOfKey[it->dest] = node.first;
            }
        }

    }
    return
    std::pair<
            std::unordered_map<Node<T>*, double * >,
            std::unordered_map<Node<T>*, Node<T> *>> (distMap, predOfKey);

}

template<class T>
void Graph<T>::sortMyPriorityNodesQueue(std::vector<std::pair <Node<T>*, double *>> &myPriorityNodesQueue){

    std::sort(myPriorityNodesQueue.begin(), myPriorityNodesQueue.end(), [](const std::pair <Node<T>*, double*> a, std::pair <Node<T>*, double*> b){
        return (*a.second) < (*b.second);
    });
}

template<class T>
void Graph<T>::eraseEdge(Node<T> *origin, Node<T> *dest) {
    for (auto it = origin->adj.begin(); it != origin->adj.end(); it++){
        if (*it = dest){
            origin->adj.erase(it);
            break;
        }
    }
}

template <class T>
Graph<T> Graph<T>::prims(Node<T> * originNode, bool dir){

    std::vector<std::pair <Node<T> *, double*>> myPriorityNodesQueue;
    std::unordered_map<Node<T>*, double * > distMap;

    for (auto it = allNodes.begin(); it != allNodes.end(); it++){

        double *x = new double;
        distMap[*it] = x;

        (*distMap[*it]) = DBL_MAX;

        (*it)->visited = false;

        std::pair <Node<T> *, double *> temp;
        temp.first = *it;
        temp.second = x;

        myPriorityNodesQueue.push_back(temp);
    }

    (*distMap[originNode]) = 0.0;
    //TODO:prim's algorithm
    //Graph::Graph<>()
}