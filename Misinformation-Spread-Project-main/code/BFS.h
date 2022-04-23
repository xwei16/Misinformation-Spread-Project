/**
 * @file BFS.h
 * Definition of a class for BFS Traversal Algorithm
 * Help to check if the Graph load data file correctly
 *
 * @author yifan20-xwei16-xianghe3-hanqing5
 * @date Fall 2021
 */
#pragma once

#include "Graph.h"
#include <vector>
#include <unordered_map>

using namespace std;
/**
 * BFS class. Provides interfaces to perform BFS traversal on the given Graph object.
 *
 * Input: a pointer to a Graph object
 * Output: the number of nodes in the graph
 *
 * @author yifan20-xwei16-xianghe3-hanqing5
 * @date Fall 2021
 */
class BFS {
    private:
    unordered_map<unsigned long, bool> vertex_label;
    Graph* graph;
    unsigned long vertex_count;
    
    /**
     * @param vertex: the vertex to label as VISITED
     * A Helper function to label the given vertex as VISITED
     */
    void setVertexVisited(unsigned long vertex);

    /**
     * @param vertex: the start node to begin BFS traversal on each connected component of the graph
     * This function perform BFS Traversal Algorithm on each connected component of the graph
     */
    void BFSHelper(unsigned long start);

    public:

    /**
     * customer constructor for BFS class. 
     * Input: a pointer to a Graph object
     */
    BFS(Graph* g);

    /**
     * This function perform BFS Traversal Algorithm on the graph
     * @return return the number of vertices in the whole graph
     */
    unsigned long BFSTraversal ();

    /**
     * This function make sure the vertex_count is correct before and after performing the traversal
     * @return return private member: vertex_count
     */    
    unsigned long get_vertex_count();

    /**
     * This function make sure the vertex_label is correct before and after performing the traversal
     * @return return private member: vertex_label
     */        
    unordered_map<unsigned long, bool> get_vertex_label();
};
