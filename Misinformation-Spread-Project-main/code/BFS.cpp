#include "Graph.h"
#include "BFS.h"
#include <vector>
#include <list>
#include <queue>

using namespace std;


/**
 * customer constructor for BFS class. 
 * Input: a pointer to a Graph object
 */
BFS::BFS(Graph* g) {
    graph = g;
    //set all lables to false (UNVISITED)
    for (unsigned long vertex : graph->all_vertices()) {
        vertex_label[vertex] = false;
    }
    vertex_count = 0;
}


/**
 * This function perform BFS Traversal Algorithm on the graph
 * @return return the number of vertices in the whole graph
 */
unsigned long BFS::BFSTraversal () {
    //BFS on each connected component
    for (unsigned long vertex : graph->all_vertices()) {
        if (!vertex_label[vertex]) {
            BFSHelper(vertex);
        }
    }
    return vertex_count;
}


/**
 * @param vertex: the start node to begin BFS traversal on each connected component of the graph
 * This function perform BFS Traversal Algorithm on each connected component of the graph
 */
void BFS::BFSHelper(unsigned long start) {
    //queue
    queue<unsigned long> vertex_queue;
    setVertexVisited(start);   
    vertex_queue.push(start);

      
    while (!vertex_queue.empty()) {
        unsigned long current = vertex_queue.front();
        vertex_queue.pop();
        ++vertex_count;
        list<unsigned long> adj = graph->vertex_neighbor(current);
        for (unsigned long v : adj) {
            if (!vertex_label[v]) {
                setVertexVisited(v);
                vertex_queue.push(v);
            }
        }
    } 
}


/**
 * @param vertex: the vertex to label as VISITED
 * A Helper function to label the given vertex as VISITED
 */
void BFS::setVertexVisited(unsigned long vertex) {
    vertex_label[vertex] = true;
}

/**
 * This function make sure the vertex_count is correct before and after performing the traversal
 * @return return private member: vertex_count
 */    
unsigned long BFS::get_vertex_count() {
    return vertex_count;
}

/**
 * This function make sure the vertex_label is correct before and after performing the traversal
 * @return return private member: vertex_label
 */ 
unordered_map<unsigned long, bool> BFS::get_vertex_label() {
    return vertex_label;
}