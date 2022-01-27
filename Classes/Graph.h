
#ifndef TRABALHOAED2_GRAPH_H
#define TRABALHOAED2_GRAPH_H

#include <string>
#include <list>
#include <vector>
#include <queue>

template <class T, class W> struct Node;
template <class T, class W> struct Edge;
template <class T, class W> class Graph;


template <class T, class W> struct Node{
    std::vector<Edge<T, W> > adj;
    T * value;
    bool visited = false;		// auxiliary field
};

template <class T, class W> struct Edge{
    Node<T, W> *dest;
    W weight;
};

template <class T, class W>
class Graph{
private:
    std::vector<Node<T, W> * > allNodes;
    unsigned int graphSize;


public:
    Graph(T * firstNodeValue);
    void setAllNotVisited();

    std::vector<T *> getAllNodesValues() const;
    std::vector<Node<T, W> *> getAllNodes() const;

    unsigned int size();
    void addNode(T * newNodeValue);
    void addNode(Node <T, W> * node);

    int findNodeIndex(T * NodeValue);
    int findNodeIndex(Node<T, W> node);

    bool addEdge(T * originNodeValue, T * destNodeValue, W weight );
    bool addEdge(Node<T, W> * nodeOrigin, Node<T, W> nodeDest, W weight);

    void removeNode(Node<T, W> node);
    void removeNode(T * nodeValue);

    void setVisitedTrue(Node<T, W> * node);

    std::vector<T *> valueToBFS(T * nodeValue);
    std::vector<T *> BFS(Node<T, W> * node);

    void addAdjToQueue(Node<T, W> * node, std::queue<Node<T, W>*> &nodesQueue);
};


#endif //TRABALHOAED2_GRAPH_H


