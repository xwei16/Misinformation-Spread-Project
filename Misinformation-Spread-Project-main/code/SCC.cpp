/**
 * @file SCC.cpp
 * implemnetation of a helper function for Strongly Connected Component Algorithm
 * This fille also consists of private helper functions only accessible in the scope of SCC
 *
 * @author yifan20-xwei16-xianghe3-hanqing5
 * @date Fall 2021
 */

#include "SCC.h"
#include <unordered_set>
#include <stack>
#include <queue>

using std::stack;
using std::unordered_set;
using std::list;
using std::queue;


/**
 * a helper function to recursively traverse the graph and loop for SCC
 * @param ggg: the pointer to the graph traversed on
 * @param curr_idx: the index we should assign to the vertex in this call
 * @param curr_v: the vertex we are at, or say it is the source
 * @param curr_scc_idx: the pointer to the scc index, it will increment by 1 after we find a SCC
 * @param threshold: if number of vertices in a SCC is less than threshold, no report would be print out
 * @param v_idx: the index assignment to the visited vertices
 * @param v_lowlink: the lowlink assignment to the visited vertices
 * @param active_stack: The stack to store the vertice that we are currently visiting but not assigned to a SCC yet
 * @param on_stack: a set that indicates if the vertex is in the active_stack or not
 * This function will recursively traverse the graph and record the path by assigning the index and lowlink to each vertex
 * When it discover a cycle, it will change its lowlink. All vertex wil same lowlink would be in the same SCC 
 */
void strong_cc_recur(Graph* ggg, int curr_idx, unsigned long curr_v,
                    int* curr_scc_idx, int threshold,
                    unordered_map<unsigned long, int> & v_idx, 
                    unordered_map<unsigned long, int> & v_lowlink, 
                    stack<unsigned long> & active_stack, 
                    unordered_set<unsigned long> & on_stack);



/**
 * @param ggg: the pointer to the Graph class
 * @param threshold: this variable is used for the message output. 
 * The algorithm will only report the index of SCC if the number of vertices is >= threshold
 * 
 * The Function will mark the index of SCC in the Graph
 * 
 * Within a SCC, for any s and t that is part of the subgraph, there is always exists a path from s to t
 * @return It will return the number of SCC subgraphs in the graph
 */
int SCC(Graph* ggg, int threshold) {
    list<unsigned long> unvisited_list = ggg->all_vertices();

    // set index and lowlink mapping
    unordered_map<unsigned long, int> v_idx, v_lowlink;
    unordered_set<unsigned long> on_stack;
    stack<unsigned long> active_stack;
    int curr_scc_idx = 0;
    int curr_idx = 0;

    // go through all vertex in graph, call the recursive function on it if not visited
    for (unsigned long & curr_v : unvisited_list) {
        if (v_idx.find(curr_v) == v_idx.end()) {
            strong_cc_recur(ggg, curr_idx, curr_v, &curr_scc_idx, threshold, v_idx, v_lowlink, active_stack, on_stack); 
        }
    }
    return curr_scc_idx;
}

/**
 * a helper function to DFS traverse the graph. For more, see the the declaration of the function above
 */
void strong_cc_recur(Graph* ggg, int curr_idx, unsigned long curr_v,
                    int* curr_scc_idx, int threshold,
                    unordered_map<unsigned long, int> & v_idx, 
                    unordered_map<unsigned long, int> & v_lowlink, 
                    stack<unsigned long> & active_stack, 
                    unordered_set<unsigned long> & on_stack)
{   
    // assign the index and low link
    // push it to the stack
    v_idx[curr_v] = curr_idx;
    v_lowlink[curr_v] = curr_idx;
    curr_idx++;
    active_stack.push(curr_v);
    on_stack.insert(curr_v);

    // go through the neighbors
    // if not visited, call itself to visit it then change the lowlink to min
    // if currently on stack, it means we find a cycle, and this neighbor is on the same SCC as us. 
    //      change lowlink to the minimum between my lowlink and neighbor's index
    list<unsigned long> neighbor_list = ggg->vertex_neighbor(curr_v);
    for (unsigned long & nei_ver : neighbor_list) {
        if (v_idx.find(nei_ver) == v_idx.end()) {
            strong_cc_recur(ggg, curr_idx, nei_ver, curr_scc_idx, threshold, v_idx, v_lowlink, active_stack, on_stack);
            v_lowlink[curr_v] = (v_lowlink[curr_v] < v_lowlink[nei_ver])? v_lowlink[curr_v] : v_lowlink[nei_ver];
        }
        else if (on_stack.find(curr_v) != on_stack.end()) {
            v_lowlink[curr_v] = (v_lowlink[curr_v] < v_idx[nei_ver])? v_lowlink[curr_v] : v_idx[nei_ver];
        }
    }

    // if the lowlink and index is same, it means we reached a root vertex
    // keep poping out vertex from stack until we pop out current v from the stack
    if (v_lowlink[curr_v] == v_idx[curr_v]) {
        int num_nodes = 0;
        while (1) {
            unsigned long next_on_stack = active_stack.top();
            active_stack.pop();
            on_stack.erase(next_on_stack);
            ggg->mark_component_idx(next_on_stack, *curr_scc_idx);
            num_nodes++;
            if (next_on_stack == curr_v) {
                break;
            }
        }

        // report it to the user
        if (num_nodes >= threshold) {
            printf("    SCC index %d has vertices %d\n", *curr_scc_idx, num_nodes);
        }
        (*curr_scc_idx)++;
    }

}





