
#ifndef TRABALHOAED2_GRAPH_H
#define TRABALHOAED2_GRAPH_H

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include "float.h"

template <class T> struct Node;
template <class T> struct Edge;
template <class T> class Graph;


template <class T> struct Node{
    std::vector<Edge<T> > adj;
    T * value;
    bool visited = false;		// auxiliary field
};

template <class T> struct Edge{
    Node<T> *dest;
    double weight;
};

template <class T>
class Graph{
private:
    std::vector<Node<T> * > allNodes;
    unsigned int graphSize;


public:
    Graph(T * firstNodeValue);
    void setAllNotVisited();

    std::vector<T *> getAllNodesValues() const;
    std::vector<Node<T> *> getAllNodes() const;

    unsigned int size();
    void addNode(T * newNodeValue);
    void addNode(Node <T> * node);

    int findNodeIndex(T * NodeValue);
    int findNodeIndex(Node<T> node);

    bool addEdge(T * originNodeValue, T * destNodeValue, double weight );
    bool addEdge(Node<T> * nodeOrigin, Node<T> nodeDest, double weight);

    void removeNode(Node<T> node);
    void removeNode(T * nodeValue);

    void eraseEdge(Node<T> * origin, Node<T> * dest);

    void setVisitedTrue(Node<T> * node);

    std::vector<T *> valueToBFS(T * nodeValue);
    std::vector<T *> BFS(Node<T> * node);

    void addAdjToQueue(Node<T> * node, std::queue<Node<T>*> &nodesQueue);

    std::pair<
            std::unordered_map<Node<T>*, double * >,
            std::unordered_map<Node<T>*, Node<T> *>> dijkstraForOriginValue(T * originNodeValue);
    std::pair<
            std::unordered_map<Node<T>*, double * >,
            std::unordered_map<Node<T>*, Node<T> *>>dijkstraForOrigin(Node<T> * originNode);

    void sortMyPriorityNodesQueue(std::vector<std::pair <Node<T>*, double *>> &myPriorityNodesQueue);
};


#endif //TRABALHOAED2_GRAPH_H


