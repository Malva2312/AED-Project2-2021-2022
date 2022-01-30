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
    /**
     * Creates an object of the class MyGraph
     */
    MyGraph();
    /**
     * Creates an object of the class MyGraph given the first node
     * @param firstNodeValue
     */
    MyGraph(T firstNodeValue);

    /**
     * Adds a new node to the graph
     * @param newNode
     */
    void addNode(Node<T> newNode);
    /**
     * Adds a node to the graph given its value
     * @param value
     */
    void addNode(T value);

    /**
     * Sets all nodes to not visited
     */
    void setAllNotVisited();


    /**
     * Returns all nodes
     * @return
     */
    std::vector<Node<T>> getAllNodes() const;
    /**
     * Returns all node's pointers
     * @return
     */
    std::vector<Node<T>*> getAllNodesPtr();

    /**
     * Returns the size of the vector containing the nodes
     * @return
     */
    unsigned int size();

    /**
     * Finds a node's index given its value
     * The function uses operator== to compare the given value with the values present in the Nodes
     * Return the index of the first occurrence
     * Return -1 if no node was found
     * Time complexity: O(N)
     * @param NodeValue
     * @return
     */
    int findNodeIndex(T NodeValue);
    /**
     * Finds a node's index given its value
     * The function uses operator== to compare the given value with the values present in the Nodes
     * Return the index of the first occurrence
     * Return -1 if no node was found
     * Time complexity: O(N)
     * @param node
     * @return
     */
    int findNodeIndex(Node<T> node);

    /**
     * Adds an edge between two nodes given their values
     * Return True if the edge was created, return False otherwise
     * Time complexity: O(n)
     * @param originNodeValue
     * @param destNodeValue
     * @param weight
     * @return
     */
    bool addEdge(T originNodeValue, T destNodeValue, double weight);
    /**
     * Adds an edge between two nodes given the nodes
     * Return True if the edge was created, return False otherwise
     * Time complexity: O(n)
     * @param nodeOrigin
     * @param nodeDest
     * @param weight
     * @return
     */
    bool addEdge(Node<T> nodeOrigin, Node<T> nodeDest, double weight);

    /**
     * Removes a node given the node
     * @param node
     */
    void removeNode(Node<T> node);
    /**
     *Removes a node given its value
     * @param nodeValue
     */
    void removeNode(T nodeValue);

    /**
     * Erases an edge given the nodes
     * @param origin
     * @param dest
     */
    void eraseEdge(Node<T> origin, Node<T> dest);
    /**
     *Removes an edge given the node's values
     * @param originValue
     * @param destValue
     */
    void eraseEdge(T originValue, T destValue);

    /**
     * Calls the BFS algorithm by getting the node's value
     * @param nodeValue
     * @return
     */
    std::vector<Node<T> *> valueToBFS(T &nodeValue);
    /**
     * BFS algorithm
     * Returns pointers to nodes in the order they were visited
     * Time complexity: O(N + E)
     * @param node
     * @return
     */
    std::vector<Node<T> *> BFS(Node<T> &node);


    /**
     *
     * @param node
     * @param nodesQueue
     */
    void addAdjToQueue(Node<T> *node, std::queue<Node<T> *> &nodesQueue);

    /**
     * Calls the Dijkstra's algorithm given a node's value
     * Time complexity: O(E×log(N)), assuming that E ≥ V
     * @param originNodeValue
     * @return
     */
    std::pair<
            std::unordered_map<Node<T>*, double >,
            std::unordered_map<Node<T>*, Node<T> *>> dijkstraForOriginValue(T originNodeValue);
    /**
     * Dijkstra's algorithm
     * Time complexity: O(E×log(N)), assuming that E ≥ V
     * @param originNode
     * @return
     */
    std::pair<
            std::unordered_map<Node<T>*, double >,
            std::unordered_map<Node<T>*, Node<T> *>> dijkstraForOrigin(Node<T> originNode);

    /**
     * Sorts the priority nodes' queue
     * @param myPriorityNodesQueue
     */
    void sortMyPriorityNodesQueue(std::vector<std::pair<Node<T> *, double*>> &myPriorityNodesQueue);

    /**
     * Prim's algorithm given a certain value
     * Time complexity: O(E×log(E))
     * @param start
     * @return
     */
    std::pair<
            double,
            std::unordered_map<T, T>> prims(T start);

    /**
     * Prim's algorithm given a node
     * Time complexity: O(E×log(E))
     * @param start
     * @return
     */
    std::pair<
            double,
            std::unordered_map<T, T>> prims(Node<T> start);

    /**
     * Returns a vector with the Stop and the distance to the origin
     * @param nodeValue
     * @param end
     * @return
     */
    std::vector<std::pair<T, double>> pathValues(T nodeValue , T end);
};


#endif //TRABALHOAED2_MYGRAPH_H
