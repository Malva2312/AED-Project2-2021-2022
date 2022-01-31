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

    for(Edge<T> adj : allNodes.at(idxOrigin).adj){
        if (adj.dest->value == allNodes.at(idxDest).value && adj.weight == weight){
            return false;
        }
    }

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

    for(Edge<T> adj : allNodes.at(idxOrigin).adj){
        if (adj.dest->value == allNodes.at(idxDest).value && adj.weight == weight){
            return false;
        }
    }

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

    sortMyPriorityNodesQueue(myPriorityNodesQueue);

    while (!myPriorityNodesQueue.empty()){

        auto node = myPriorityNodesQueue.front();
        myPriorityNodesQueue.erase(myPriorityNodesQueue.begin());
        node.first->visited = true;


        for (auto it = node.first->adj.begin(); it != node.first->adj.end() ; it++){

            if(it->dest->visited == false
               && distMap[node.first] + it->weight < distMap[it->dest]){
                distMap[it->dest] =  distMap[node.first] + it->weight;
                predOfKey[it->dest] = node.first;

                sortMyPriorityNodesQueue(myPriorityNodesQueue);
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
MyGraph<T>::prims(T start) {
    int idx = findNodeIndex(start);
    if(idx < 0) return std::pair<
                        double,
                        std::unordered_map<T, T>>(0, std::unordered_map<T, T>());

    return prims(allNodes.at(idx));
}

template<class T>
std::pair<
        double,
        std::unordered_map<T, T>>
MyGraph<T>::prims(Node<T> start) {
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

    sort(availableEdges.begin(), availableEdges.end(), []
            (const std::pair<T, Edge<T>> A, const std::pair<T, Edge<T>> B){
        return A.second.weight < B.second.weight;
    });

    while (!availableEdges.empty()){

        Edge<T> edge = availableEdges.front().second;
        T org = availableEdges.front().first;
        availableEdges.erase(availableEdges.begin());

        if(edge.dest->visited == false){
            cost += edge.weight;
            edge.dest->visited = true;
            predOfKey[edge.dest->value] = org;
            for(auto it : edge.dest->adj) availableEdges.template emplace_back(edge.dest->value, it);

            sort(availableEdges.begin(), availableEdges.end(), []
                    (const std::pair<T, Edge<T>> A, const std::pair<T, Edge<T>> B){
                return A.second.weight < B.second.weight;
            });
        }
    }

    return std::pair<
            double,
            std::unordered_map<T, T>>(cost, predOfKey);
}


template <class T>
std::vector<std::pair<T, double>> MyGraph<T>::pathValues(T start, T end){  //  paragem <-> distancia à origem
    int idx = findNodeIndex(start);
    int idxEnd = findNodeIndex(end);
    if (idx <0 || idxEnd < 0) return std::vector<std::pair<T, double>>();

    auto dijks = dijkstraForOrigin(allNodes.at(idx));  //map<Node*,distância double > map<Node*, Node* do precedente>
    auto nodeDist = dijks.first;
    auto predOfNode = dijks.second;

    Node<T> * endPtr = getAllNodesPtr().at(idxEnd);

    std::vector<std::pair<T, double>> res;

    while (predOfNode[endPtr] != nullptr){
        res.template emplace_back(endPtr->value, nodeDist[endPtr]);
        endPtr = predOfNode[endPtr];
    }

    res.template emplace_back(endPtr->value, 0);
    std::reverse(res.begin(), res.end());

    return res;
}


