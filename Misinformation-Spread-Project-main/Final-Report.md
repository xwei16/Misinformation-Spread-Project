# Project Final Report
# The Misinformation-Spread in Twitter Network

yifan20-xwei16-xianghe3-hanqing5

## Final Presentation

<a href="http://www.youtube.com/watch?feature=player_embedded&v=7WMrje_X-0Y" target="_blank"><img src="http://img.youtube.com/vi/7WMrje_X-0Y/0.jpg" alt="Final Presentation" width="240" height="180" border="10" /></a>

## GOALS

#### **Leading Question**

We want to develop a tool that can simulate the spread of misinformation through social media. First, we divide the social network into several Strongly Connected Components(SCC). Assuming that misinformation spreading speed is constant within each component, and given a source and destination, we want to find out who has been infected with misinformation (spread net) by the time it reaches to the destination. The graph will be directed graph. The weight on each edge is unit weight.

#### **Dataset**

We will use [ego-Twitter](http://snap.stanford.edu/data/ego-Twitter.html) from Stanford Large Network Dataset Collection as our dataset. The dataset contains directed edge lists. There are two columns of number. Each number represents a userID. There are 2,420,766 rows. At each row, the first number is the follower userID. The second number is the userID being followed. After removing all the duplicated edges with R. We got 81,306 unique userID and 1,768,149 unique edges. In our dataset, in order to represent the flow of the information, we need to load the data with second column as the source and first column as the destination in a directed graph. We also realized that some twitter users in the real world may not follow any person, which means information wouldn't be propagated to them. To solve this issue, we will use Strongly Connected Component (SCC) to cluster these users away while analyzing the spread net. 


#### **Algorithms** 

We will assume the unit weight for each edge. The graph will remain as directed. We will use Prim's algorithm to look for the spread net. Also, we will use Strongly Connected Component algorithm to divide the social network into several dense circles. The input will be the whole graph. BFS traversal will also be implemented. Also, SCC algorithm will be based on DFS.


##### Prim's Algorithm
* The runtime of the Prim's Algorithm is O (n^2), since we will use adjacency list to implement graph and unordered array in Prim's Algorithm.
* This algorithm uses the idea of Greedy Algorithm to find a MST on a weighted graph, given a starting node.
* In the whole class, the input is a pointer to a Graph object and the index of SCC, and the output is a vector of nodes that has been visited during the spreading from the start node to the end node.

##### BFS Traversal
* The runtime of the BFS Traversal Algorithm is O (|V| + |E|).
* The input is a pointer to a Graph object, and the output is the number of nodes in this graph.

##### SCC Algorithm
* We use Tarjan's Algorithm to implement the SCC. It is DFS based.
* The runtime of the Strongly Connected Component is O(|V| + |E|).
* The input is a pointer to a Graph object and an integer T that tells the program to print out the information of any SCC subgraph if the total of vertices in that SCC subgraph is not less than T.
* The output of the algorithm will be an integer indicating how many SCC subgraphs it has found. 
* The algorithm will leave markings on each vertex in the graph object during the execution.

#### **Final Deliverable**

The program will allow the user to choose which dataset to load and perform the SCC algorithm on the graph. The user can input a number as the threshold, which is used for filtering out the SCC subgraphs with number of vertices less than that. Then, the program will list out all SCC subgraphs' indices whose number of vertices are above the threshold. User enters the SCC subgraph index they want to work on. The program will output all vertices into an external file, where user can read and choose a misinformation source vertx and destination vertex and enter them into the program terminal. The program will soon use Prim's algorithm to search for the spread net. The final result will be outputed in a txt file. It is a list of vertices that shows who has been infected with the misinformation while the source vertex passes it to the destination vertex.

We will construct a bunch of test cases in test.cpp to prove that our algorithms are implemented successfully. We will test each Algorithm seperately by using different test cases. And for each Algorithm, we will build seperate test for different functions. This kind of function-by-function test will help us reduce the probability of having bugs in our code. 

#### **Timeline**
**Time Spread: five weeks**

- **Week 1 (Nov 8th, Nov 14th):**

     Our general goal is to polish up the proposal and finish data acquisition and most part of data processing. If there is still time left, we will come up with the basic ideas of the structures of traversals and algorithms. 

- **Week 2 (Nov 15th, Nov 21st):**

     By the end of the second week, we should have completed all works listed in week one and achieve the requirement of Mid-Project Check-in. Besides, we will also produce all basic structures and at least two of three primary models in our project.

- **Week 3 (Nov 22nd, Nov 28th)	Fall break! No Work**

- **Week 4 (Nov 29th, Dec 5th):**

     This week, we will strive to make sure the whole model runs smoothly and be able to solve our leading question. Also, all test cases and explanation files are expected to be  completed. 

- **Week 5 (Dec 6th, Dec 12th):**

     During the final week, we will polish up our model based on the advice from mentor and course staff. Meanwhile, we will also record the final presentation video and publish it onto Youtube.


## DEVELOPMENT LOG
#### **Week 1: (Nov 3rd to Nov 7th)**
We just got acquainted with each other. On Nov 5th, we had our first group meeting. During the meeting, we exchanged ideas and discussed the future timeline for this project. We tried to decide on the dataset and leading question for this project. However, there was not enough time on that day. So, only Team Contract was completed during the meeting. We all unanimously agreed to follow all terms from the contract and fulfill the expectations. On Nov 6th, we continued our discussion on the project leading question and data collection. Eventually, we all assent to the idea of using social media graph data to simulate the spread of misinformation. During that meeting, we also discussed whether the graph edge needs weight or not, if yes, how to assign it, which algorithm and traversal technique should be used. That day was quite fruitful. We completed the proposal and agreed to use Strongly Connected Component algorithm to separate graphs into several dense parts, then use Prim’s Algorithm to find the misinformation spreader. Both BFS and DFS would be used in the project. 

#### **Week 2: (Nov 8th to Nov 14th)**
On Nov 11th, we received our proposal review from the mentor. On Nov 12th, we conducted a meeting with our mentor and got enough clarification on the issues with our proposal. After the meeting, we acted swiftly to fix the proposal and got it approved on Nov 16th. 

#### **Week 3: (Nov 15th to Nov 21st)**
The proposal approval was received on 16th. So, we were only able to conduct this week's meeting as early as Nov 20th. During this week's meeting, we discussed further details about this project. Most details are related to grading rubric. We decided to divide and conquer for the following two weeks, and combine our work to build the final result. The project coding  part was splitted into two parts. One part is Graph class implementation and Strongly Connected Component Algorithm. Another part is BFS implementation and Prim's algorithm. Four-member team was divided into two units. Each unit has one person implement the algorithm and another writing test code. Although next week would be a holiday break, we decided to work on the project to make up for the time lost due to proposal revision.

#### **Week 4: (Nov 22nd to Nov 28th)**
This week was supposed to be a break. However, we decided to complete most coding parts during this week to catch up on some lost time. So, we completed Graph class implementation, Prim's algorithm, BFS traversal, Strongly Connected Component(SCC) algorithm and most of the testing code. Two units actively communicated with each other to ensure each of our code implementations is compatible with others'. Since we haven't figured out how to build Makefile, we couldn't run the code and check for bugs. On Nov 28th, we conducted this week's meeting. During this meeting, we discussed what was left to do and when approximately we should finish each of the remaining jobs in order to meet the deadline. We also scheduled next week's mid-checkpoint with our mentor. Prior to the mid-checkpoint meeting, we must build a simple runnable program that is capable of processing the dataset, and must write instructions in the README file.

#### **Week 5: (Nov 29th to Dec 5th)**
Before meeting with our mentor, we successfully built a simple Makefile and wrote a simple program that can process the dataset and display the result on the screen. On Dec 1st, we had our meeting with the mentor. Mentor was satisfied with our progress. On Dec 5th, we conducted this week's group meeting. During this meeting, we drew the layout of remaining work and assigned tasks and deadlines to each member. By Dec 9th, we should be able to organize all of our meeting notes. By Dec 10th, we should finish the first draft of the ppt. By Dec 11th, we should wrap up all the works and be ready for presentation. On Dec 12th, we will present and make the recording.

#### **Week 6: (Dec 6th to Dec 12th)**
This week, we plan to finish all remaining tasks, which mainly includes debugging all the code, optimizing the performance, completing all the text work, and finishing the final presentation. We held the meeting at the beginning of the week and successfully assigned all the work. Before Dec 9th, we had finished all the debugging work and performance optimization. By Dec 10th, we uploaded README and the final report, and finished all our individual parts of the final presentation, including PPT and explanation of the project. By the end of this week, we finished all the tasks in this project.


## RESULT
#### **Algorithms**

##### Graph Implementation (Graph.h & Graph.cpp)

The graph implementation is very successful. After loading the data, all statistics matches that on the website. By building varieties of test cases on different graphs, we can confirm that all functions like inserting vertex, edge, neighbors look-up, scc index storage are working as we intended. 

##### BFS Traversal (BFS.h & BFS.cpp)

The BFS also works as we expected. We built three test cases to comfirm the correctness for this class. We test the constructor, and the main function that perform BFS. In order to test BFS. One of the cases use cyclic graph, and another one uses acyclic. This would make sure that our BFS Algorithm works on both tree and cyclic graph. All tests passed in the end. Further, as we stated before, the role of BFS in our project is to check if we load the data file correctly. Thus, we used BFS and print out the number of vertices. The result is shown below:<img width="1283" alt="Screen Shot 2021-12-12 at 13 01 35" src="https://media.github-dev.cs.illinois.edu/user/11998/files/6405c77d-dfdc-42a2-8182-29b467cfa0c4"> This result match the number in the resource website correctly.


##### SCC Algorithm (SCC.h & SCC.cpp)

We use tarjan's algorithm to divide the graph into several subgraphs. The algorithm is DFS based and runs in O(|V| + |E|). We built two test cases with two complicated garphs to confirm the correctness of the SCC implementation. Both tests passed. The SCC algorithm works as we intended. Then, we applied this alogrithm on the twitter network dataset. The result shows 13,842 SCC subgraphs were found. Among all subgraphs, only one has the number of vertices exceeding 100. That subgraph has total 66,493 vertiecs. This result is exactly what we are expecting. The SCC algorithm successfully filtered out the users that are not well connected with the rest of the network. Now, we can apply the Prim's algorithm to look for the spread net of the misinformation. In the directed SCC subgraph, there always exists a path between two randomly picked vertices. This ensures when the user picked two vertices from same SCC subgraph as the source and destination of the misinformation, the Prim's algorithm will always find the spread net. The misinformation will always be delivered to the destination due to the connectivity of the SCC.

##### Prim's Algorithm (Prim.h & Prim.cpp)

We first use a simple graph to test if the Prim's implementation can produce any result or not. Then, we use more complicated graph to test Pirm's correctness and other helper functions individually. All tests passed. Then, we applied the Prim's algorithm onto the largest SCC subgraph. We picked misinformation source and destination vertices from the chosen SCC subgraph. The Prim's algorithm is able output a list of vertices that shows all the user ID has been infected with the misinformation while the misinformation is transmiting from the soure to the destination.




#### **Result in Complete Run**

1. Under the directory `\code`, run the following code to compile the code:

```
make
```

![Figure 1: Compilation](https://media.github-dev.cs.illinois.edu/user/11991/files/329f7531-002c-4232-b7c0-164bd6512812)

2. After compilation, run the following code to start the program

```
./misinfo_spread data/twitter_clean.txt
```

![Figure 2: Before entering the SCC Threshold](https://media.github-dev.cs.illinois.edu/user/11991/files/370d03ba-945c-43e1-a694-7f54c3bdbfff)

Then, we would see the number of vertices and edges in the graph. The program will ask user to enter a threshold for the SCC reporting. This number is used to filter out any small SCC subgraphs that is not useful. For our project, we will enter 100 as threshold. We would use any SCC subgraphs with number of vertices larger than 100.

![Figure 3: Entering the SCC Threshold](https://media.github-dev.cs.illinois.edu/user/11991/files/053a7e06-b04f-4fb1-86b9-252112d66882)

3. After we entered the threshold, the program will show the user a list of SCC subgraphs that satisfied the threshold. In our case, there is only one SCC subgraph with more than 100 vertices. Other 13,841 SCC subgraphs are too small for us. So, we input 1603 to tell the program that we want to work on this SCC subgraph. Then, the program will tell user where all the vertices in the chosen subgraph is placed. In our case, all vertices in the 1603 subgrapg are located in a txt file named `scc_vertices.txt` under the current directory.

![Figure 4: choosing vertices](https://media.github-dev.cs.illinois.edu/user/11991/files/064e0f89-be8f-4bf0-afc0-154660a4919c)


The following picture shows a part of `scc_vertices.txt`. 
<img width="767" alt="Screen Shot 2021-12-10 at 23 01 51" src="https://media.github-dev.cs.illinois.edu/user/11998/files/f17358e4-a774-4884-a41a-1663a7023bce">


4. Now, we need to choose two vertices from the list as source and destination. After entering two vertices into the program, the program will tell the user where the result is being placed. The result is a list of vertices that has been spreaded with misinformation while the misinformation was being passed to the destination. 

![Figure 5: finishing](https://media.github-dev.cs.illinois.edu/user/11991/files/6ec0ae90-4a43-4eb8-981a-1330acf2a7b0)

The following picture shows a part of `result.txt`:

<img width="767" alt="Screen Shot 2021-12-10 at 23 01 56" src="https://media.github-dev.cs.illinois.edu/user/11998/files/f19b4799-9b02-49c5-93f0-15a44f19cbe0">


**Testing**



Result: from this image, it's easy to see that we passed all tests and with no memory error.<img width="919" alt="Screen Shot 2021-12-12 at 12 39 49" src="https://media.github-dev.cs.illinois.edu/user/11998/files/ef67d8d2-4479-46a5-81c0-bd8faf236c1a">




**Memory Test**


And the last but not least, our program has **no memory error**.
![WechatIMG185](https://media.github-dev.cs.illinois.edu/user/11998/files/cfbe8ca6-0648-4266-9764-405b9319a492)







#### **Discussion and Findings**

The data we have is just a tip of the iceberg in twitter social network. The limited information forced us to assume the probability of one user passing the information to its followers is 100 percent. So, we used unit weight on every edge.
Among plenty of subgraphs, some members assume that there will be a few big SCC graphs. However, only 12 of them contain more or equal than 10 nodes, and most people are well connected to each other in graph 1603. Compared to people in the above graph, there are still about 18% people are difficult to receive messages from this cycle. 
Another interesting finding is that, in 1603, if you choose random start point and end point, for some cases, you will find it spread to the entire network by the time the message reaches the destination. 
