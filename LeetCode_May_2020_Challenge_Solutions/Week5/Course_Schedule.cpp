/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1 <= numCourses <= 10^5 

*/

//Solution


class Solution {
public:

    //NOTE:
    // 0 = unvisted vertex   1 = under processing vertex   2 = completely explored vertex
    //Cycle is present if we come to "under processing" vertex again
    // If we do not pass graph (adjacency list ) by reference in dfs() , then we will get TLE

    bool dfs(int u, vector<vector<int>> &graph, vector<int> &visited_check_cycle){

        if(visited_check_cycle[u] == 1)       //if we come to a "under processing" vertex, this means cycle is present
           return false;
        if(visited_check_cycle[u] == 2)
            return true;
        visited_check_cycle[u] = 1;           //marking the vertex as "under processing"
        int s= graph[u].size();
        for(int v=0;v<s;v++){                 //explore neighbours

              if(!dfs(graph[u][v], graph, visited_check_cycle))
                return false;
        }



        visited_check_cycle[u]=2;          ////when all neighbours are explored, mark the vertex as completely explored
        return true;

    }

    bool dfsUtil(int numCourses, vector<vector<int>> & graph){

         vector<int> visited_check_cycle(numCourses,0);
        for(int i=0;i<numCourses;i++){
           if(visited_check_cycle[i]==0){
            if(!dfs(i, graph,visited_check_cycle))
                  return false;
           }

        }
        return true;

    }

     vector<vector<int>> create_graph( vector<vector<int>> &graph, int numCourses, vector<vector<int>>& prerequisites){

        int n= prerequisites.size();
        for(int i=0;i<n;i++){

            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);

        }

        return graph;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses,vector<int>());
        graph=create_graph(graph,numCourses,prerequisites);


        return dfsUtil(numCourses,graph);


    }
};

//TC = O(V+E)
//Sc = O(1)    if stack space is ignored
