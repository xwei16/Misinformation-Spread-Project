# Misinfomation Spreading Project
Repo for yifan20-xwei16-xianghe3-hanqing5


## Overview
Our final project uses **twitter_combined.txt** [ego-Twitter](http://snap.stanford.edu/data/ego-Twitter.html) as the dataset, which contains all edges and vertices from the graph. With the help of R language, we were able to clean the data and remove all duplicated rows. Thus, we would be using **twitter_clean.txt** for any further execution.

The program would load the graph data and run the Strongly Connected Component Algorithm to partition the graph. Then we will provide options for users to choose which component to play with. After entering the valid component index, we would return user a file containing all ID numbers within the chosen component. The user can pick one ID number as the **source** of the misinformation, and another one as the ending point or the **destination** of the misinformation spreading. The program will compute the shortest path from source to destination and return it to user in a text file. On the terminal, the program will show how many people has been infected with this misinfo along the way.


## Linkage


#### Code 


* All code can be found under the directory `code/` .
* After compilation, an executable file `misinfo_spread` can also be found under the directory `code/`.

#### Data


* The data can be found under the directory `code/data/`.
* The original data is called `twitter_combined.txt`. 
* After some data cleaning, we have a graph dataset `twitter_clean.txt` without any duplicated edge.


#### Result


* All results is stored under the directory`code/`.
* The text file `scc_vertices.txt` contains a list of Strongly Connected Component Index can be found under this directory
* The test file `result.txt` contains all the spreaded vertices when spreading from start to end point can be found under this directory


## Usage


#### Prior to anything

* If you are compiling the program on EWS machine, please run `module load llvm/6.0.1` before you do anything.
* We are using `C++14` compiler in the makefile. So, please confirgure your enviorment accordingly.


#### Compilation

* Under the **./code** directory, type the following to compile the program

```
make 
```

* If user needs to clean up all the files after compilation, type the following

```
make clean
```

#### Program Execution

* To start the program, run the following command under directory `code/`:

```
./misinfo_spread data/twitter_clean.txt
```

* The program call must contain exactly two prases. The first one calls `./misinfo_spread` to the executable file. The second one `<datafile path>` is the path to the data set. For this project, dataset is inside of the directory `data/`.


#### Data Format


To successfully run the program, we must have a valid dataset with valid format. 

* The dataset must only contains two columns of ID numbers, which is separated by a space char. 
* Each row represents an directed edge. According to the data source, the first column user follows second column user twitter account. So, we set an edge in graph from second column to first column, which repesents the flow of information.
* Each ID number must be numeric and in the range from 0 to 4,294,967,295. 
* There must be no headers or any other elements in the dataset. 
* Here is an example of the correct dataset format:

```
214328887 34428380
17116707 28465635
380580781 18996905
221036078 153460275
107830991 17868918
151338729 222261763
19705747 34428380
222261763 88323281
19933035 149538028
158419434 17434613
```





#### During Executing
* Follow the guideline to input any needed stuff. Please make sure that your input is **valid**; invalid or incorrectly formatted input is undefined behavior.
* All the vertices in the chosen SCC will be a text file called `scc_vertices.txt` in the directory `code/`.
* The final result will be a text file called `result.txt` in the directory `code/`.


## TESTING
#### Brief Introduction


All test cases are designed to check the correctness of implementation of all algorithms. 
We designed varieties of tests to check the status of vertices, edges and whether BFS, Prim, SCC works as we expected. Simple graphs are manually inserted. More complicated graphs are loaded from external TEXT files.


#### Test Cases


We set up simple graphs to test the graph implementation and BFS traversals. We just need to check if the inserting and traversing actually works. For Prim's and Strongly Connected Component Algorithms, we need to use more complicated graph. Not only we need to make sure that the algorithm will produce any result, but also we have to ensure the correctness of the outcome. 


#### Code 

* All test can be found under the directory `code/test.cpp` .

#### Data

* The data can be found under the directory `code/data/`.

#### Compilation

* Under the **./code** directory, type the following to compile the test

```
make test
```

#### Program Execution

* To start the program, run the following command under **./code** directory:

```
./test
```
