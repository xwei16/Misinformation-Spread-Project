/**
 * @file test.cpp
 * @author yifan20-xwei16-xianghe3-hanqing5
 * @brief 
 *  test of all functions in the project
 *  
 * @version final
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "catch.hpp"
#include "catchmain.cpp"
#include "Graph.h"
#include "SCC.h"
#include "BFS.h"
#include "Prim.h"


#include <list>
#include <string>
#include <unordered_map>
#include <utility>
#include <fstream> 
#include <sstream>
#include <unordered_set>
#include <stack>
#include <queue>


using std::string;
using std::stack;
using std::unordered_set;
using std::list;
using std::queue;
using std::ifstream;


//-------------------------------------------------------------------------
/**
 * @brief One: Test of Graph-related functions 
 * 
 */

/**
 * @brief 
 * [1]
 * test of the constructor Graph()
 */

TEST_CASE("Correct initialization", "[weight=1]") {
  Graph test_initial;
  int size_v = test_initial.vertex_size();
  int size_e = test_initial.edge_size();
  REQUIRE( size_v == 0 );
  REQUIRE( size_e == 0 );
}

/**
 *  test of following functions:
 * 
 *  [6]     
 *  ssize_t vertex_degree(unsigned long s);
 *  [7.1]   
 *  size_t ver_size; 
 *  [7.2]   
 *  size_t ed_size; 
 *  [8] 
 *  void Graph::mark_component_idx(unsigned long v, int idx)
 *  [9.1]
 *  list<unsigned long> vertex_neighbor(unsigned long s); 
 *  [9.2] 
 *  list<unsigned long> Graph::vertex_neighbor_scc(unsigned long s, int idx); 
 *  [10.1] 
 *  void insert_vertex(unsigned long s); 
 *  [10.2]
 *  void insert_edge(unsigned long s, unsigned long t); 
 */

/**
 * @brief (1.1)simple insert
 * 
 */

TEST_CASE("Correctly insert vertex (simple)", "[weight=1]") {
  Graph test_insert;
  
  test_insert.insert_vertex(5);
  test_insert.insert_vertex(8);
  test_insert.insert_vertex(7);
  int size_v = test_insert.vertex_size();
  REQUIRE( size_v == 3 );
}

/**
 * @brief (1.2)dumplicate vertex
 * 
 */

TEST_CASE("Correctly insert vertex", "[weight=1]") {
  Graph test_insert;
  test_insert.insert_vertex(5);
  test_insert.insert_vertex(8);
  test_insert.insert_vertex(7);
  test_insert.insert_vertex(20);
  test_insert.insert_vertex(13);
  test_insert.insert_vertex(8);
  int size_v = test_insert.vertex_size();
  REQUIRE( size_v == 5 ); 
}

/**
 * @brief (2.1) simple insert edge
 * 
 */
TEST_CASE("Correctly insert vertex and insert one edge", "[weight=1]") {
  Graph test_insert;
  unsigned long result_5 = 0;
  
  test_insert.insert_vertex(5);
  test_insert.insert_vertex(8);
  test_insert.insert_vertex(7);

  test_insert.insert_edge(5, 8);

  int size_e = test_insert.edge_size();
  REQUIRE( size_e == 1 );

  //only front has degree and neighbour
  REQUIRE( test_insert.vertex_degree(5) == 1 );
  

  list<unsigned long> temp_5 = test_insert.vertex_neighbor(5);
  result_5 = temp_5.front();
  REQUIRE( result_5 == 8 );  


}
/**
 * @brief (2.2)  edge and mutiple degree
 * 
 */
TEST_CASE("Correctly insert vertex and insert mutiple edges", "[weight=1]") {
  Graph test_insert;
  test_insert.insert_vertex(5);
  test_insert.insert_vertex(8);
  test_insert.insert_vertex(7);
  test_insert.insert_vertex(20);
  test_insert.insert_vertex(13);

  test_insert.insert_edge(5, 8);
  test_insert.insert_edge(5, 13);
  test_insert.insert_edge(7, 20);

  int size_e = test_insert.edge_size();
  REQUIRE( size_e == 3 );

  REQUIRE( test_insert.vertex_degree(5) == 2 );
  REQUIRE( test_insert.vertex_degree(7) == 1 );

  unsigned long result_7 = 0;
  unsigned long result_5_1 = 0;
  unsigned long result_5_2 = 0;    
  list<unsigned long> temp_7 = test_insert.vertex_neighbor(7);
  result_7 = temp_7.front();
  REQUIRE( result_7 == 20 );  

  list<unsigned long> temp_5 = test_insert.vertex_neighbor(5);
  list<unsigned long>::iterator it = temp_5.begin();
  for(int i=0; i < 2; i++){
    if (result_5_1 == 0) {
      result_5_1 = *it;
    } else if (result_5_2 == 0) {
      result_5_2 = *it;
    }
    ++it;
  }
    
  REQUIRE( result_5_1 == 8 );  
  REQUIRE( result_5_2 == 13 ); 

};

/**
 * @brief (3) index
 * 
 */
TEST_CASE("Correctly mark the index", "[weight=1]") {
  //a. construct empty graph
  Graph test_index;

  test_index.insert_vertex(5);
  test_index.insert_vertex(8);
  test_index.insert_vertex(7);
  test_index.insert_vertex(20);
  test_index.insert_vertex(13);

  test_index.insert_edge(5, 8);
  test_index.insert_edge(5, 13);
  test_index.insert_edge(7, 20);
  test_index.insert_edge(5, 8);
  //b. assign the index
  test_index.mark_component_idx(5, 3);
  test_index.mark_component_idx(7, 1);
  //c. check whether equal
  
  int result1 = test_index.component_idx(5);
  int result2 = test_index.component_idx(7);

  REQUIRE( result1 == 3 );
  REQUIRE( result2 == 1 );
}

//--------------------------------------------------------------------------


/**
 * @brief Two: test of BFS related fuctions
 * 
 */
//Test BFS
TEST_CASE("Test BFS Constructor", "[weight=1]") {
  Graph *test_constructor = new Graph();
  test_constructor->insert_vertex(5);
  test_constructor->insert_vertex(8);
  test_constructor->insert_vertex(7);
  test_constructor->insert_edge(5, 8);
  test_constructor->insert_edge(5, 7);

  BFS traversal = BFS(test_constructor);
  REQUIRE( traversal.get_vertex_count() == 0 );
  unordered_map<unsigned long, bool> temp = traversal.get_vertex_label();
  REQUIRE( temp[5] == false );
  delete test_constructor;
}

TEST_CASE("Test BFS Traversal Without Loop", "[weight=1]") {
  Graph *test_BFS = new Graph();
  test_BFS->insert_vertex(5);
  test_BFS->insert_vertex(8);
  test_BFS->insert_vertex(7);
  test_BFS->insert_edge(5, 8);
  test_BFS->insert_edge(5, 7);

  BFS traversal = BFS(test_BFS);

  REQUIRE( traversal.BFSTraversal() == 3);
  delete test_BFS;
}

TEST_CASE("Test BFS Traversal With Loop", "[weight=1]") {
  Graph *test_BFS = new Graph();
  test_BFS->insert_vertex(5);
  test_BFS->insert_vertex(8);
  test_BFS->insert_vertex(7);
  test_BFS->insert_edge(5, 8);
  test_BFS->insert_edge(5, 7);
  test_BFS->insert_edge(7, 8);
  
  BFS traversal = BFS(test_BFS);

  REQUIRE( traversal.BFSTraversal() == 3);
  delete test_BFS;
}


//--------------------------------------------------------------------------


/**
 * @brief Three: test of SCC related fuctions
 * 
 */

/**
 * @brief constructor
 * [1] int SCC(Graph * ggg);
 */

TEST_CASE("Correct scc constructor", "[weight=1]") {
  Graph *test_scc_initial = new Graph();
  int num = 0;
  test_scc_initial->insert_edge(5, 8);
  test_scc_initial->insert_edge(14, 5);  
  test_scc_initial->insert_edge(8, 14);
  test_scc_initial->insert_edge(5, 13);
  
  test_scc_initial->insert_edge(7, 5);
  test_scc_initial->insert_edge(7, 20);
  test_scc_initial->insert_edge(9, 7);  
  test_scc_initial->insert_edge(20, 9);
  num = SCC(test_scc_initial, 100);
  REQUIRE( num == 3 ); 
  delete test_scc_initial;
}

/**
 * @brief Complicated case1: size, index, correct graph
 * 
 */
TEST_CASE("SCC correct assignment 1", "[weight=1]") {
  // load data from txt file
  Graph ggg_1("data/test_graph1.txt");

  // check vertex size and edge size
  REQUIRE( ggg_1.vertex_size() == 16 );
  REQUIRE( ggg_1.edge_size() == 25 );
  REQUIRE( ggg_1.vertex_degree(11) == 3);

  // check for scc assignment
  int scc_piece = SCC(&ggg_1, 100);
  REQUIRE( scc_piece == 4 );
  REQUIRE( ggg_1.vertex_neighbor_scc(6).front() == 7 );

  // check if vertex 1, 2, 3, 4, 5 all has same index
  unsigned long i = 1;
  for (; i < 5; i++) {
    REQUIRE( ggg_1.component_idx(i) == ggg_1.component_idx(i+1) );
  }

  // check if other scc member doesn't share same index with vertex 5
  REQUIRE( ggg_1.component_idx(11) != ggg_1.component_idx(5) );
  REQUIRE( ggg_1.component_idx(8) != ggg_1.component_idx(5) );
  REQUIRE( ggg_1.component_idx(6) != ggg_1.component_idx(5) );

  // check for vertex 6 and 7
  REQUIRE( ggg_1.component_idx(6) == ggg_1.component_idx(7) );

  // check for vertex 8, 9, 10
  i = 8;
  for (; i < 10; i++) {
    REQUIRE( ggg_1.component_idx(i) == ggg_1.component_idx(i+1) );
  }

  // check 8 and 7 not in same scc
  REQUIRE( ggg_1.component_idx(8) != ggg_1.component_idx(7) );

  // check 10 and 11 not in same scc
  REQUIRE( ggg_1.component_idx(10) != ggg_1.component_idx(11) );
  // check 6 and 11 not in same scc
  REQUIRE( ggg_1.component_idx(6) != ggg_1.component_idx(11) );
  i = 11;
  for (; i < 16; i++) {
    REQUIRE( ggg_1.component_idx(i) == ggg_1.component_idx(i+1) );
  }

  REQUIRE(ggg_1.vertex_neighbor_scc(1).size() == 2);
  REQUIRE(ggg_1.vertex_neighbor_scc(6).size() == 1);
  REQUIRE(ggg_1.vertex_neighbor_scc(8).size() == 1);
  REQUIRE(ggg_1.vertex_neighbor_scc(11).size() == 2);
}

/**
 * @brief Complicated case1: size, index, correct graph
 * 
 */
TEST_CASE("SCC correct assignment 2", "[weight=1]") {
  // load data from txt file
  Graph ggg_1("data/test_graph2.txt");

  // check vertex size and edge size
  REQUIRE( ggg_1.vertex_size() == 10 );
  REQUIRE( ggg_1.edge_size() == 17 );

  // check for scc assignment
  int scc_piece = SCC(&ggg_1, 100);
  REQUIRE( scc_piece == 4 );

  // check if vertex 0, 1, 2, 3 all has the same index
  unsigned long i = 0;
  for (; i < 3; i++) {
    REQUIRE( ggg_1.component_idx(i) == ggg_1.component_idx(i+1) );
  }

  // check if other scc member doesn't share same index with vertex 3
  REQUIRE( ggg_1.component_idx(6) != ggg_1.component_idx(3) );
  REQUIRE( ggg_1.component_idx(8) != ggg_1.component_idx(3) );
  REQUIRE( ggg_1.component_idx(7) != ggg_1.component_idx(3) );

  // check for vertex 8, 9
  REQUIRE( ggg_1.component_idx(8) == ggg_1.component_idx(9) );

  // check 8 and 7 not in same scc
  REQUIRE( ggg_1.component_idx(8) != ggg_1.component_idx(7) );
  REQUIRE( ggg_1.vertex_neighbor_scc(1).size() == 1 );
}


//--------------------------------------------------------------------------


/**
 * @brief Four: test of Prim related fuctions
 * 
 */

//Test Prim Constructor
TEST_CASE("Test Prim Constructor", "[weight=1]") {
  Graph* test_Prim = new Graph();
  test_Prim->insert_vertex(5);
  test_Prim->insert_vertex(8);
  test_Prim->insert_vertex(7);
  test_Prim->insert_edge(5, 7);
  int num = SCC(test_Prim, 100);

  SpreadNet net = SpreadNet(test_Prim, 0);
  REQUIRE( net.get_scc_vertices().size() == 1 );
  net = SpreadNet(test_Prim, 1);
  REQUIRE( net.get_scc_vertices().size() == 1 );
  net = SpreadNet(test_Prim, 2);
  REQUIRE( net.get_scc_vertices().size() == 1 );
  delete test_Prim;
}

//Test Prim get_spread_net method
TEST_CASE("Test Prim_spread_net", "[weight=1]") {

  Graph ggg_1("data/test_graph1.txt");

  int num = SCC(&ggg_1, 100);
  //check simple spread net
  SpreadNet net = SpreadNet(&ggg_1, 2);
  //printf("the vertex 6 has index %d\n", ggg_1.component_idx(6));
  //printf("the vertex 7 has index %d\n", ggg_1.component_idx(7));
  vector <unsigned long> temp = net.get_spread_net(6,7);
  REQUIRE( temp.size() == 2 );
  REQUIRE( temp[0] == 6 );
  REQUIRE( temp[1] == 7 );

  //check more complex spread net
  net = SpreadNet(&ggg_1, 3);
  temp = net.get_spread_net(1,4);
  REQUIRE( temp.size() == 4 );    //or 5
  REQUIRE( temp[0] == 1 );
  REQUIRE( temp[3] == 4 );
  
}

//Test Prim findMin method
TEST_CASE("Test Prim findMin", "[weight=1]") {
  Graph* test_Min = new Graph();
  test_Min->insert_vertex(5);
  test_Min->insert_vertex(8);
  test_Min->insert_vertex(7);
  test_Min->insert_edge(5, 7);
  int num = SCC(test_Min, 100);

  SpreadNet net = SpreadNet(test_Min, 1);
  REQUIRE( net.findMin() ==  INT_MAX);
  delete test_Min;
}

//Test Prim getIndex method
TEST_CASE("Test Prim getIndex", "[weight=1]") {
  Graph* test_Index = new Graph();
  test_Index->insert_vertex(5);
  test_Index->insert_vertex(8);
  test_Index->insert_vertex(7);
  test_Index->insert_edge(5, 7);
  int num = SCC(test_Index, 100);

  SpreadNet net = SpreadNet(test_Index, 1);
  //Includes both existing and non-existing vertices
  REQUIRE( net.getIndex(8) == 0 );
  REQUIRE( net.getIndex(20) == INT_MAX );
  delete test_Index;
}

