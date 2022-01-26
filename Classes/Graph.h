//
// Created by Utilizador on 25/01/2022.
//

#ifndef TRABALHOAED2_GRAPH_H
#define TRABALHOAED2_GRAPH_H

#include <string>
#include <list>
#include <vector>

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
    //bool hasDir;            //false: undirect; true: directed

public:
    Graph(T * firstNodeValue, unsigned int size);
    void setAllNotVisited();

};

#endif //TRABALHOAED2_GRAPH_H