/**
 * @file Prim.h
 * Definition of a class for Prim's Algorithm with some modification
 *
 * @author yifan20-xwei16-xianghe3-hanqing5
 * @date Fall 2021
 */

#pragma once
#include "Graph.h"
#include <vector>
using namespace std;

/**
 * SpreadNet class. Provides interface (get_spread_net) for find the SpreadNet in the chosen SCC,
 * with given start node & end node. Others are all helper functions.
 *
 * Input: a pointer to a Graph object
 * Output: the index for the chosen SCC to perform Prim's Algorithm
 *
 * @author yifan20-xwei16-xianghe3-hanqing5
 * @date Fall 2021
 */
class SpreadNet {
    private:
        Graph* graph;
        vector<unsigned long> scc_spread_net;
        size_t scc_vertex_size;
        vector<unsigned long> scc_vertices;
        vector<int> cost;
        vector<bool> inMST;
        int SCC_identity_;


    public:

        /**
         * customer constructor for SpreaNet class. 
         * Input: a pointer to a Graph object & SCC index
         */
        SpreadNet(Graph* g, int SCC_identity);


        /**
         * This function find min cost in vector:cost
         * @return the index of the vertex with min cost
         */
        int findMin();


        /**
         * @param vertex: the vertex to find its index in scc_vertices
         * find the index of the vertex in scc_vertices
         * @return if the vertex exists, return its index
         * Otherwise, it would return INT_MAX
         * Notice: this should not happen as long as the userInput is correct
         */
        int getIndex(unsigned long vertex);
        
        
        /**
         * @param start: the node to begin Prim's algorithm
         * @param end : the node to end the Prim's algorithm
         * This function perform Prim's Algorithm start from start node and end with the end node
         */
        void PrimMST(unsigned long start, unsigned long end);
        /**
         * @param start: the node to begin Prim's algorithm
         * @param end : the node to end the Prim's algorithm
         * This function call PrimMST function to perform Prim's Algorithm
         * @return return a vector of node been visited during Prim's Algorithm
         */
        vector<unsigned long> get_spread_net(unsigned long start, unsigned long end);


        /**
         * This function return the scc_vertices if needed
         * @return return scc_vertices
         */
        vector<unsigned long> get_scc_vertices();
};
