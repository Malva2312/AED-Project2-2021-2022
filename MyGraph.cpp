//
// Created by Utilizador on 28/01/2022.
//

#include "MyGraph.h"


template <class T>
MyGraph<T>::MyGraph() {}

template <class T>
MyGraph<T>::MyGraph(T firstNodeValue) {
    addNode(firstNodeValue);
}

template<class T>
void MyGraph<T>::addNode(Node<T> newNode) {
    allNodes.push_back(newNode);
}

template<class T>
void MyGraph<T>::addNode(T value) {
    Node<T> newNode;
    newNode.value = value;
    addNode(newNode);
}

template<class T>
void MyGraph<T>::setAllNotVisited() {
    for (auto it = allNodes.begin(); it != allNodes.end(); it++){
         it->visited = false;
    }
}

template<class T>
std::vector<Node<T>> MyGraph<T>::getAllNodes() const {
    return allNodes;
}

template<class T>
unsigned int MyGraph<T>::size() {
    return allNodes.size();
}

template<class T>
int MyGraph<T>::findNodeIndex(T NodeValue) {
    for (int idx = 0; idx < size(); idx++){
        if (allNodes[idx].value == NodeValue) return idx;
    }
    return -1;
}

template<class T>
int MyGraph<T>::findNodeIndex(Node<T> node) {
    for (int idx = 0; idx < size(); idx++){
        if (allNodes[idx].value == node.value) return idx;
    }
    return -1;
}

template<class T>
bool MyGraph<T>::addEdge(T originNodeValue, T destNodeValue, double weight) {
    int idxOrigin = findNodeIndex(originNodeValue);
    int idxDest = findNodeIndex(destNodeValue);


    if (idxOrigin < 0 || idxDest < 0){return false;}

    Edge<T> newEdge;
    newEdge.dest = &allNodes.at(idxDest);
    newEdge.weight = weight;

    allNodes.at(idxOrigin).adj.push_back(newEdge);
    return true;
}

template<class T>
bool MyGraph<T>::addEdge(Node<T> nodeOrigin, Node<T> nodeDest, double weight) {
    int idxOrigin = findNodeIndex(nodeOrigin);
    int idxDest = findNodeIndex(nodeOrigin);

    if (idxOrigin < 0 || idxDest < 0){return false;}

    Edge<T> newEdge;
    newEdge.dest = &allNodes.at(idxDest);
    newEdge.weight = weight;

    nodeOrigin->adj.push_back(newEdge);

    return true;
}

template<class T>
std::vector<Node<T>*> MyGraph<T>::BFS(Node<T> &node) {
    int idx = findNodeIndex(node);
    Node<T> * nodePtr = &allNodes.at(idx);

    setAllNotVisited();

    std::queue<Node<T> *> nodesQueue;
    std::vector<Node<T> *> nodeValuesPath = {nodePtr};

    nodePtr->visited = true;
    addAdjToQueue(nodePtr, nodesQueue);

    while (nodesQueue.empty() == false){
        nodePtr = nodesQueue.front();
        nodesQueue.pop();

        nodePtr->visited = true;
        addAdjToQueue(nodePtr, nodesQueue);

        nodeValuesPath.push_back(nodePtr);
    }

    return nodeValuesPath;
}

template<class T>
void MyGraph<T>::addAdjToQueue(Node<T> *node, std::queue<Node<T>*>  &nodesQueue) {

    for (auto it = node->adj.begin(); it != node->adj.end(); it++){
        if(it->dest->visited == false) {
            nodesQueue.push(it->dest);
            it->dest->visited = true;
        }
    }
}


template<class T>
std::vector<Node<T>*> MyGraph<T>::valueToBFS(T &nodeValue) {
    int idx= findNodeIndex(nodeValue);
    return BFS(allNodes.at(idx));
}

template<class T>
std::pair<
        std::unordered_map<Node<T> *, double>,
        std::unordered_map<Node<T> *, Node<T> *>>
MyGraph<T>::dijkstraForOriginValue(T originNodeValue) {
    int idx = findNodeIndex(originNodeValue);
    if (idx < 0){
        std::pair<
                std::unordered_map<Node<T> *, double>,
                std::unordered_map<Node<T> *, Node<T> *>> temp;
        return temp;
    }
    return dijkstraForOrigin(allNodes.at(idx));
}

template<class T>
std::pair<
        std::unordered_map<Node<T> *, double>,
        std::unordered_map<Node<T> *, Node<T> *>>
MyGraph<T>::dijkstraForOrigin(Node<T> originNode) {

    int idx = findNodeIndex(originNode);
    Node<T> * nodePtr = &allNodes.at(idx);

    std::vector<std::pair <Node<T> *, double*>> myPriorityNodesQueue;
    std::unordered_map<Node<T>*, double> distMap;
    std::unordered_map<Node<T>*, Node<T> *> predOfKey;

    for(auto it = allNodes.begin(); it != allNodes.end(); it++){

        distMap[&*it] = DBL_MAX;
        it->visited = false;

        std::pair <Node<T> *, double*> temp;
        temp.first = &(*it);
        temp.second = &distMap[&*it];

        myPriorityNodesQueue.push_back(temp);
    }

    nodePtr->visited = true;
    distMap[nodePtr] = 0.0;
    predOfKey[nodePtr] = nullptr;

    while (!myPriorityNodesQueue.empty()){

        sortMyPriorityNodesQueue(myPriorityNodesQueue);

        auto node = myPriorityNodesQueue.front();
        myPriorityNodesQueue.erase(myPriorityNodesQueue.begin());
        node.first->visited = true;


        for (auto it = node.first->adj.begin(); it != node.first->adj.end() ; it++){

            if(it->dest->visited == false
               && distMap[node.first] + it->weight < distMap[it->dest]){
                distMap[it->dest] =  distMap[node.first] + it->weight;
                predOfKey[it->dest] = node.first;
            }
        }
    }

    return
            std::pair<
                    std::unordered_map<Node<T>*, double >,
                    std::unordered_map<Node<T>*, Node<T> *>> (distMap, predOfKey);

}

template<class T>
void MyGraph<T>::sortMyPriorityNodesQueue(std::vector<std::pair <Node<T>*, double*>> &myPriorityNodesQueue){

    std::sort(myPriorityNodesQueue.begin(), myPriorityNodesQueue.end(), [](const std::pair <Node<T>*, double*> a, std::pair <Node<T>*, double*> b){
        return (*a.second) < (*b.second);
    });
}

template<class T>
std::vector<Node<T> *> MyGraph<T>::getAllNodesPtr() {
    std::vector<Node<T> *> res;
    for (auto it = allNodes.begin(); it!= allNodes.end(); it++){
        res.push_back(&(*it));
    }
    return res;
}

template<class T>
std::pair<
        double,
        std::unordered_map<T, T>>
MyGraph<T>::prims(T start, bool undir) {
    int idx = findNodeIndex(start);
    if(idx < 0) return std::pair<
                        double,
                        std::unordered_map<T, T>>(0, std::unordered_map<T, T>());

    return prims(allNodes.at(idx), undir);
}

template<class T>
std::pair<
        double,
        std::unordered_map<T, T>>
MyGraph<T>::prims(Node<T> start, bool undir) {
    int idx = findNodeIndex(start);
    if(idx < 0) return std::pair<
                double,
                std::unordered_map<T, T>>(0, std::unordered_map<T, T>());

    setAllNotVisited();

    double cost = 0;
    std::unordered_map<T, T> predOfKey;
    std::vector<std::pair<T, Edge<T>>> availableEdges;

    allNodes.at(idx).visited = true;
    start = allNodes.at(idx);
    start.visited = true;
    T org = start.value;
    predOfKey[org] = org;  //org == predOfKey[org]

    for(auto it : start.adj) availableEdges.template emplace_back(org, it);

    while (!availableEdges.empty()){
        sort(availableEdges.begin(), availableEdges.end(), []
            (const std::pair<T, Edge<T>> A, const std::pair<T, Edge<T>> B){
                return A.second.weight < B.second.weight;
        });

        Edge<T> edge = availableEdges.front().second;
        T org = availableEdges.front().first;
        availableEdges.erase(availableEdges.begin());

        if(edge.dest->visited == false){
            cost += edge.weight;
            edge.dest->visited = true;
            predOfKey[edge.dest->value] = org;
            for(auto it : edge.dest->adj) availableEdges.template emplace_back(edge.dest->value, it);
        }
    }

    return std::pair<
            double,
            std::unordered_map<T, T>>(cost, predOfKey);
}

/*
template<class T>
std::vector<T *> MyGraph<T>::getAllNodesValues() const {
    std::vector<T *> allNodesValues;
    for (auto it = allNodes.begin(); it != allNodes.end(); it++){
        //allNodesValues.push_back((it->value));
    }
    return allNodesValues;
}*/


