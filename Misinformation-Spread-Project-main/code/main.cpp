#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>

#include <string>
#include <fstream>
#include "Graph.h"
#include "Prim.h"
#include "SCC.h"
#include "BFS.h"


#include<stdio.h>
#include<stdlib.h>
#define txtfilename "result.txt"
#define txtfilename1 "scc_vertices.txt"

using std::string;

int main(int argv, char* argc[]) {
    if (argv != 2) {
        printf("    Usage: ./dataload <datafile path>\n");
        exit(1);
    }

    string data_file_path = argc[1];

    Graph graph(data_file_path);

    //make sure load file correctly
    printf("===========================================================\n");
    printf("    Total amount of vertices is %zu\n", graph.vertex_size());
    printf("    Total amount of edges is %zu\n", graph.edge_size());
    printf("===========================================================\n");
    
    //enter threshold for SCC
    int threshold;
    printf("    Please enter a threshold for the number of vertices in the SCC, so that when the number of vertices in the SCC is above the threshold, we will show the exact number of vertices in the chosen SCC\n");
    scanf("%d", &threshold); 
    printf("===========================================================\n");

    //perform SCC algorithm
    int num_of_scc = SCC(&graph, threshold);
    printf("    Total amount of SCC is %d\n", num_of_scc);
    printf("===========================================================\n");

    //find spread net on each SCC
    //let user choose which SCC to perform
    int scc_idx;
    printf("    Please decide to use which SCC: enter a number from 0 to %d\n ", num_of_scc-1);
    scanf("%d", &scc_idx); 
    printf("===========================================================\n");
    //show the verteces in the chosen SCC
    list<unsigned long> scc_vertices = graph.all_vertices_scc(scc_idx);
    FILE *scc_vert;
    if((scc_vert = fopen(txtfilename1,"wt+"))==NULL)
    {
      printf("\nerror on open %s file!","scc_vertices.txt");
      exit(1);
    }
    char write_to_file1[20];
    for (unsigned long & node : scc_vertices) {
        memset(write_to_file1,0,20);
        snprintf(write_to_file1, sizeof(write_to_file1), "%lu\n", node);
        fputs(write_to_file1,scc_vert);
    }
    fclose(scc_vert);
    scc_vert = NULL;
    printf("    All vertices in the chosen SCC is in scc_vertices.txt in /code directory! Please take a look!\n");
    printf("===========================================================\n");
    unsigned long start, end;
    printf("    Please decide the start and the end respectively from the above vertices\n");
    printf("    Please enter the start node:\n");
    scanf("%lu", &start); 
    printf("    Please enter the end node:\n");
    scanf("%lu", &end); 
    printf("===========================================================\n");

    //find the spread net with the given SCC, start node, and the end node
    SpreadNet net(&graph, scc_idx);
    vector<unsigned long> spread_net = net.get_spread_net(start, end);

    //write net to file
    FILE *result;
    if((result = fopen(txtfilename,"wt+"))==NULL)
    {
      printf("\nerror on open %s file!","result.txt");
      exit(1);
    }
    char write_to_file[20];
    for (unsigned long & node : spread_net) {
        memset(write_to_file,0,20);
        snprintf(write_to_file, sizeof(write_to_file), "%lu\n", node);
        fputs(write_to_file,result);
    }
    fclose(result);

    result = NULL;

    //finish
    printf("    The result is already in the result.txt file in /code directory! Thanks for using our program!\n");

    return 0;




    /***********************Test Code****************************
    if (argv != 2) {
        printf("    Usage: ./dataload <datafile path>\n");
        exit(1);
    }
    string data_file_path = argc[1];

    Graph g_load(data_file_path);
    printf("===========================================================\n");
    printf("    Total amount of vertices is %zu\n", g_load.vertex_size());
    printf("    Total amount of edges is %zu\n", g_load.edge_size());
    printf("===========================================================\n");
    printf("    Print first ten vertices ID number: \n");
    list<unsigned long> vertices_l = g_load.all_vertices();
    int i = 0;
    for (unsigned long & aaa : vertices_l) {
        if (i == 10) {
            break;
        }
        printf("        %lu\n", aaa);
        i++;
    }

    return 0;
    */

    //print net
    /*
    printf("    Below is the spread net of SCC #%d, with the start node %lu and the end node %lu\n", scc_idx, start, end);
    for (unsigned long & aaa : spread_net) {
        printf("        %lu", aaa);
    }
    printf("\n");
    printf("===========================================================\n");
    */

    /*for (unsigned long & aaa : scc_vertices) {
        printf("        %lu", aaa);
    }
    */
}

