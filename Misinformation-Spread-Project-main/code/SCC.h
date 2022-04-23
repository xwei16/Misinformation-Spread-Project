/**
 * @file SCC.h
 * Definition of a helper function for Strongly Connected Component Algorithm
 *
 * @author yifan20-xwei16-xianghe3-hanqing5
 * @date Fall 2021
 */
#include "Graph.h"
#include <stack>
#include <vector>



/**
 * @param ggg: the pointer to the Graph class
 * @param threshold: this variable is used for the message output. 
 * The algorithm will only report the index of SCC if the number of vertices is >= threshold
 * 
 * This function will perform Strongly Connected Component algorithm, specifically, Tarjan's Algorithms.
 * It will recursively use DFS to traverse the graph. 
 * While visiting a vertex, 
 *      an index and a lowlink index are assigned to the vertex. 
 *      The vertex will be push down on the stack. Then it will check each of its neighbors
 *              If neighbor has no index assigned, recursively traverse to it
 *                  After returning, assign current lowlink index as the smaller one between current and neighbor
 *              Else If neighbor is still on the stack, 
 *                  assign the current lowlink indx as the smaller one between current lowlink and neighbor's index
 *              Else: Ignore
 * After going through all the neighbor, check if the lowlink is same as index.
 * If is: current vertex is the root, so keep poping the vertice on the stack until reach the current one
 * now we have a Strongly Connect Component
 * The Function will mark the index of SCC in the Graph
 * 
 * Within a SCC, for any s and t that is part of the subgraph, there is always exists a path from s to t
 * @return It will return the number of SCC subgraphs in the graph
 */
int SCC(Graph * ggg, int threshold);






