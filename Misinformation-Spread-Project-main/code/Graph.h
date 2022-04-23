/**
 * @file Graph.h
 * Definition of a class for Graph data struture 
 *
 * @author yifan20-xwei16-xianghe3-hanqing5
 * @date Fall 2021
 */

#pragma once

#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using std::string;
using std::list;
using std::unordered_set;
using std::pair;
using std::unordered_map;
using std::stringstream;


/**
 * Graph class. Provides interfaces for inserting vertices and edges, 
 * loading graph from txt file, and outputing list of neighbor vertices 
 * and neighbor vertices in same SCC subgraph
 *
 * @author yifan20-xwei16-xianghe3-hanqing5
 * @date Fall 2021
 */
class Graph {
    public:
        /**
         * Default constructor for Graph class. Initialize private variables
         */
        Graph();

        /**
         * customer constructor for Graph class. It loads graph data from a txt file. 
         * It assumes all the edges in the file is unique.
         */
        Graph(const string &filename);

        /**
         * @param s: the vertex user want to look up
         * count how many vertices are neighbor to vertex s
         * @return if the vertex exists, it would return a non-negative integer
         * Otherwise, it would return -1
         */
        ssize_t vertex_degree(unsigned long s);

        /**
         * @param s: the vertex user want to look up
         * For any vertex t in this graph s.t. (s, t) is an edge in this graph
         * @return if the vertex exists and has neighbor, it would return a list of vertices
         * Otherwise, it would return an empty list
         */
        list<unsigned long> vertex_neighbor(unsigned long s);

        /**
         * This function puts all vertices in a list
         * @return a list that contains all vertices in the graph
         */
        list<unsigned long> all_vertices();

        /**
         * @param idx: the scc index
         * This function puts all vertices within same scc subgraph in a list
         * @return a list that contains all vertices from the scc subgraph indexed with idx
         * If the idx is out of bound, empty list would be returned
         */
        list<unsigned long> all_vertices_scc(int idx);

        /**
         * This function is similar with all_vertices() with different return data structure
         * @return a set that contains all vertices from the graph
         */
        unordered_set<unsigned long> all_vertices_set();

        /**
         * @param s the vertex s
         * This function takes the vertex and find its neighbors and 
         * filter out all other vertices not in the same scc subgraph
         * @return a list of vertices that is neighbor to s with same scc index
         */
        list<unsigned long> vertex_neighbor_scc(unsigned long s);

        /**
         * This function colect all the edges and return to the user in a list of pair
         * @return a list of edges from the graph
         */
        list<pair<unsigned long, unsigned long> > all_edges();

        /**
         * @param v: the vertex v
         * @param idx: the scc index
         * This function assign the vertex v with index idx
         * It returns nothing.
         */
        void mark_component_idx(unsigned long v, int idx);

        /**
         * @param v: the vertex v
         * This function tells you which scc subgraoh the vertex v belongs to
         * @return if the vertex has been assigned with a index, an non-negative integer would be returned
         * Otherwise, it would return -1
         */
        int component_idx(unsigned long v);

        /**
         * @return the total number of vertices
         */
        size_t vertex_size();

        /**
         * @return the total number of edges
         */
        size_t edge_size();

        /**
         * @param s: vertex s
         * If s exists already, do nothing, otherwise, add a key and an empty list to the unordered map
         */
        void insert_vertex(unsigned long s);

        /**
         * @param s: vertex s
         * @param t: vertex t
         * First, call insert_vertex on both vertex s and t. Then add t to the list of neighbors for s
         */
        void insert_edge(unsigned long s, unsigned long t);


    private: 

        /**
         * An unordered_map for the adjacency list. 
         * key is the vertex. value is a list of vertices that is neighbor to the key
         */
        unordered_map<unsigned long, list<unsigned long> > vertices_map;

        /**
         * An unordered_map for scc 
         * key is the vertex. value is the SCC index that key belongs to 
         */
        unordered_map<unsigned long, int> component_map;

        /**
         * An unordered_map for scc, reverse
         * key is the SCC index. value is list of all vertices in the SCC 
         */
        unordered_map<int, list<unsigned long> > scc_list;

        /**
         * @param filename: a path to the file data that contains edge data
         * This is an internal helper function that load data from txt file to the data structure
         * For each row, there is two id numbers separated by the space char. 
         * Suppose, this function reads a row "s t", it will insert them as edge(t, s)
         */
        void read_datafile(const string &filename);

        /**
         * The total number of vertices
         */
        size_t ver_size;

        /**
         * The total number of edges
         */
        size_t ed_size;
};
