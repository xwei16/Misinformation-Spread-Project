# CS 225 Data Structures 
## Project Proposal (yifan20-xwei16-xianghe3-hanqing5) 

### Leading Question

We want to develop a tool that can simulate the spread of misinformation through social media. First, we divide the social network into several Strongly Connected Components(SCC). Assuming that misinformation spreading speed is constant within each component, we want to find out who is capable of spreading misinformation within the shortest time in each SCC. Therefore, the system can put those users on the special watchlist. Once they start to spread the misinformation, the system can swiftly send out alerts.

---

### Dataset Acquisition and Processing

We will use ego-Twitter (http://snap.stanford.edu/data/ego-Twitter.html) as our dataset from Stanford Large Network Dataset Collection. We plan to use userID as our vertices and edges from the provided file, twitter_combined.txt.gz, in the ego-Twitter.We plan to use userID as vertices because it can avoid a duplicating ID for different users. For the userID file, we plan to use Python to extract the userID from twitter_combined.txt.gz. 
The first real-world problem we realized is that there may be some users not following any person, which means any information will not be propagated to them. In this case, we prefer to use SCC to block these users when we analyze the super disseminators.
The second problem may be that the userID would be duplicated in the real-world data as a mistake. But this problem should be the data collector’s responsibility, as the real-world userID should be unique.

---

### Graph Algorithms

We will assume the unit weight for each edge. Since blogger's post can't be directly passed to a non-subscriber, we will not convert the directed graph. We will use Prim’s algorithm to look for the minimum spanning tree. This algorithm will take a root node as the misinformation source and use BFS to traverse the graph. It will stop after certain number of people have been exposed to misinformation. The time complexity is O(mlogn). Also, we will use Strongly Connected Component algorithm to divide the social network into several dense circles. The input will be the whole graph. The time complexity of this algorithm will be in Linear Time. While using Prim's algorithm to look for Minimum Spanning Tree, we will use BFS to traverse the graph. While sperating graph into Strongly Connect Component, we will use algorithm that is based on DFS.

---

### Timeline

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
 

