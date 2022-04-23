/**
 * @file Graph.cpp
 * The implementation of the class Graph for Graph.h
 *
 * @author yifan20-xwei16-xianghe3-hanqing5
 * @date Fall 2021
 */

#include "Graph.h"
#include <fstream> 
#include <sstream>

using std::ifstream;
using std::stoi;


/**
 * Default constructor for Graph class. Initialize private variables
 */
Graph::Graph() {
    ver_size = 0;
    ed_size = 0;
}

/**
 * customer constructor for Graph class. It loads graph data from a txt file. 
 * It assumes all the edges in the file is unique.
 */
Graph::Graph(const string &filename) {
    ver_size = 0;
    ed_size = 0;
    read_datafile(filename);
}


/**
 * This function is similar with all_vertices() with different return data structure
 * @return a set that contains all vertices from the graph
 */
unordered_set<unsigned long> Graph::all_vertices_set() {
    unordered_set<unsigned long> all_v;
    unordered_map<unsigned long, list<unsigned long>>::iterator it = vertices_map.begin();
    for (; it != vertices_map.end(); ++it) {
        all_v.insert(it->first);
    }
    return all_v;
}


/**
 * This function puts all vertices in a list
 * @return a list that contains all vertices in the graph
 */
list<unsigned long> Graph::all_vertices() {
    list<unsigned long> all_v; 
    unordered_map<unsigned long, list<unsigned long>>::iterator it = vertices_map.begin();
    for (; it != vertices_map.end(); ++it) {
        all_v.push_back(it->first);
    }
    return all_v;
}

/**
 * @param idx: the scc index
 * This function puts all vertices within same scc subgraph in a list
 * @return a list that contains all vertices from the scc subgraph indexed with idx
 * If the idx is out of bound, empty list would be returned
 */
list<unsigned long> Graph::all_vertices_scc(int idx) {
    return scc_list[idx];
}


/**
 * This function colect all the edges and return to the user in a list of pair
 * @return a list of edges from the graph
 */
list<pair<unsigned long, unsigned long>> Graph::all_edges() {
    list<pair<unsigned long, unsigned long>> all_e;
    unordered_map<unsigned long, list<unsigned long>>::iterator it = vertices_map.begin();
    for (; it != vertices_map.end(); ++it) {
        for (unsigned long & aa : it->second) {
            all_e.push_back(pair<unsigned long, unsigned long>(it->first, aa));
        }
    }
    return all_e;
}



/**
 * @param filename: a path to the file data that contains edge data
 * This is an internal helper function that load data from txt file to the data structure
 * For each row, there is two id numbers separated by the space char. 
 * Suppose, this function reads a row "s t", it will insert them as edge(t, s)
 */
void Graph::read_datafile(const string &filename) {
    // assume file's format is correct
    ifstream edge_file(filename);
    string edge_1;
    if (edge_file.is_open()) {
        while (getline(edge_file, edge_1)) {
            stringstream ss(edge_1);
            string temp_ver;
            getline(ss, temp_ver, ' ');
            unsigned long s = stoi(temp_ver);
            getline(ss, temp_ver, ' ');
            unsigned long t = stoi(temp_ver);
            //insert_edge(s, t);
            insert_edge(t, s);
        }
    }
    edge_file.close();
}


/**
 * @param v: the vertex v
 * This function tells you which scc subgraoh the vertex v belongs to
 * @return if the vertex has been assigned with a index, an non-negative integer would be returned
 * Otherwise, it would return -1
 */
int Graph::component_idx(unsigned long v) {
    if (component_map.find(v) == component_map.end()) {
        return -1;
    }
    return component_map[v];
}

/**
 * @param s: the vertex user want to look up
 * count how many vertices are neighbor to vertex s
 * @return if the vertex exists, it would return a non-negative integer
 * Otherwise, it would return -1
 */
ssize_t Graph::vertex_degree(unsigned long s) {
    // if vertex not exist, return -1
    if (vertices_map.find(s) == vertices_map.end()) {
        return -1;
    }
    size_t dg = vertices_map[s].size();
    return dg;
}

/**
 * @return the total number of vertices
 */
size_t Graph::vertex_size() {
    return ver_size;
}

/**
 * @return the total number of edges
 */
size_t Graph::edge_size() {
    return ed_size;
}

/**
 * @param v: the vertex v
 * @param idx: the scc index
 * This function assign the vertex v with index idx
 * It returns nothing.
 */
void Graph::mark_component_idx(unsigned long v, int idx) {
    //printf("marking %lu with index %d\n", v, idx);
    if (vertices_map.find(v) == vertices_map.end()) {
        return;
    }
    component_map[v] = idx;
    scc_list[idx].push_back(v);
}

/**
 * @param s: the vertex user want to look up
 * For any vertex t in this graph s.t. (s, t) is an edge in this graph
 * @return if the vertex exists and has neighbor, it would return a list of vertices
 * Otherwise, it would return an empty list
 */
list<unsigned long> Graph::vertex_neighbor(unsigned long s) {
    // if not exist, return an empty list
    if (vertices_map.find(s) == vertices_map.end()) {
        return list<unsigned long>();
    }
    list<unsigned long> neighbor_copy = vertices_map[s];
    return neighbor_copy;
}


/**
 * @param s the vertex s
 * This function takes the vertex and find its neighbors and 
 * filter out all other vertices not in the same scc subgraph
 * @return a list of vertices that is neighbor to s with same scc index
 */
list<unsigned long> Graph::vertex_neighbor_scc(unsigned long s) {
    // if not exist, return an empty list
    list<unsigned long> neighbor_v;
    if (vertices_map.find(s) == vertices_map.end()) {
        return neighbor_v;
    }
    if (component_map.find(s) == component_map.end()) {
        return neighbor_v;
    }
    int idx = component_map[s];
    for (unsigned long & aaa : vertices_map[s]) {
        if (component_map[aaa] == idx) {
            neighbor_v.push_back(aaa);
        }
    }
    return neighbor_v;
}

/**
 * @param s: vertex s
 * If s exists already, do nothing, otherwise, add a key and an empty list to the unordered map
 */
void Graph::insert_vertex(unsigned long s) {
    // check if s exists already, do nothing
    if (vertices_map.find(s) != vertices_map.end()) {
        return;
    }
    list<unsigned long> egde_list;
    vertices_map.insert(pair<unsigned long, list<unsigned long>>(s, egde_list));
    ver_size++;
}

/**
 * @param s: vertex s
 * @param t: vertex t
 * First, call insert_vertex on both vertex s and t. Then add t to the list of neighbors for s
 */
void Graph::insert_edge(unsigned long s, unsigned long t) {
    insert_vertex(s);
    insert_vertex(t);
    vertices_map[s].push_back(t);
    ed_size++;
}
