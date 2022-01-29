//
// Created by Utilizador on 28/01/2022.
//

#ifndef TRABALHOAED2_MYGRAPH_H
#define TRABALHOAED2_MYGRAPH_H

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include "float.h"

template <class T> struct Node;
template <class T> struct Edge;
template <class T> class MyGraph;


template <class T> struct Node{
    std::vector<Edge<T> > adj;
    T value;
    bool visited = false;		// auxiliary field
};

template <class T> struct Edge{
    Node<T> *dest;
    int weight;
};

template <class T> class MyGraph {
private:
    std::vector<Node<T> > allNodes;
public:
    MyGraph();
    MyGraph(T firstNodeValue);

    void addNode(Node<T> newNode);
    void addNode(T value);

    void setAllNotVisited();

    //std::vector<T *> getAllNodesValues() const;
    std::vector<Node<T>> getAllNodes() const;
    std::vector<Node<T>*> getAllNodesPtr();

    unsigned int size();

    int findNodeIndex(T NodeValue);
    int findNodeIndex(Node<T> node);

    bool addEdge(T originNodeValue, T destNodeValue, double weight);
    bool addEdge(Node<T> nodeOrigin, Node<T> nodeDest, double weight);

    void removeNode(Node<T> node);
    void removeNode(T nodeValue);

    void eraseEdge(Node<T> origin, Node<T> dest);
    void eraseEdge(T originValue, T destValue);

    std::vector<Node<T> *> valueToBFS(T &nodeValue);
    std::vector<Node<T> *> BFS(Node<T> &node);


    void addAdjToQueue(Node<T> *node, std::queue<Node<T> *> &nodesQueue);

    std::pair<
            std::unordered_map<Node<T>*, double >,
            std::unordered_map<Node<T>*, Node<T> *>> dijkstraForOriginValue(T originNodeValue);
    std::pair<
            std::unordered_map<Node<T>*, double >,
            std::unordered_map<Node<T>*, Node<T> *>> dijkstraForOrigin(Node<T> originNode);


    void sortMyPriorityNodesQueue(std::vector<std::pair<Node<T> *, double*>> &myPriorityNodesQueue);


    std::pair<
            double,
            std::unordered_map<T, T>> prims(T start);

    std::pair<
            double,
            std::unordered_map<T, T>> prims(Node<T> start);

    std::vector<std::pair<T, double>> pathValues(T nodeValue , T end);
};


#endif //TRABALHOAED2_MYGRAPH_H
