#include "Graph.h"
#include "Prim.h"
#include <vector>
#include <climits>
#include <queue>
using namespace std;


/**
* customer constructor for SpreaNet class. 
* Input: a pointer to a Graph object
* Output: the index for the chosen SCC to perform Prim's Algorithm
*/
SpreadNet::SpreadNet(Graph* g, int SCC_identity) {
    graph = g;
    SCC_identity_ = SCC_identity;

    //convert vertex list to vector
    list<unsigned long> temp = graph->all_vertices_scc(SCC_identity);
    for (unsigned long v : temp) {
        scc_vertices.push_back(v);
    }


    scc_vertex_size = scc_vertices.size();

    
    //prev.resize(vertex_size);
    cost.resize(scc_vertex_size);
    inMST.resize(scc_vertex_size);

    //initialization
    for (size_t i = 0; i < scc_vertex_size; i++) {
        cost[i] = INT_MAX;
        inMST[i] = false;
    }

    
}


/**
 * @param start: the node to begin Prim's algorithm
 * @param end : the node to end the Prim's algorithm
 * This function perform Prim's Algorithm start from start node and end with the end node
 */
void SpreadNet::PrimMST(unsigned long start, unsigned long end) {

    cost[getIndex(start)] = 0;
    
    int end_index = getIndex(end);
    for (size_t i = 0; i < scc_vertex_size; i++) {
        int index = findMin();

        // include the vertex into MST(spreadLink)
        inMST[index] = true;
        scc_spread_net.push_back(scc_vertices[index]);
        if (index == end_index) return; //link finished
        //update adjacents of the vertex
        for (unsigned long v : graph -> vertex_neighbor_scc(scc_vertices[index])) {
            int idx_v =getIndex(v);
            if (1 < cost[idx_v]) {
                cost[idx_v] = 1;    //unit weight
            }
            
        }
    }
    
        
}

/**
 * @param vertex: the vertex to find its index in scc_vertices
 * find the index of the vertex in scc_vertices
 * @return if the vertex exists, return its index
 * Otherwise, it would return INT_MAX
 * Notice: this should not happen as long as the userInput is correct
 */
int SpreadNet::getIndex(unsigned long vertex) {
    for (size_t i = 0; i < scc_vertex_size; i++) {
        if (scc_vertices[i] == vertex) return i;
    }
    return INT_MAX;     //fix for warning. normally should not reach this line
}



/**
 * This function find min cost in vector:cost
 * @return the index of the vertex with min cost
 */
int SpreadNet::findMin() {
   int min = INT_MAX;
   int min_index = INT_MAX;
    for (size_t i = 0; i < scc_vertex_size; i++) {
        if (!inMST[i]) {
            if (cost[i] < min) {
                min = cost[i];
                min_index = i;
            }
        }
    }
    return min_index;
}


/**
 * @param start: the node to begin Prim's algorithm
 * @param end : the node to end the Prim's algorithm
 * This function call PrimMST function to perform Prim's Algorithm
 * @return return a vector of node been visited during Prim's Algorithm
 */
vector<unsigned long> SpreadNet::get_spread_net(unsigned long start, unsigned long end) {
    
    PrimMST(start, end);
    
    return scc_spread_net;
}


/**
 * This function return the scc_vertices if needed
 * @return return scc_vertices
 */
 vector<unsigned long> SpreadNet::get_scc_vertices() {
     return scc_vertices;
 }