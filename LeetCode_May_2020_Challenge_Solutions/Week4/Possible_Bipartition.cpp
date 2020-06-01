/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Constraints:

1 <= N <= 2000
0 <= dislikes.length <= 10000
dislikes[i].length == 2
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

*/ 

//Solution

class Solution {
public:
    bool isBipartite( int source, vector<vector<int>> adj, vector<int> &col)
    {

         queue<int > q;

        if(col[source]!=-1)
            return true;
        //put source in queue
        q.push(source);

        col[source]=1;
        while(!q.empty())
        {
            int i=q.front();
            q.pop();

            int len=adj[i].size();
            for (int j=0;j<len;j++)
            {
                int neighbor=adj[i][j];

                if(col[neighbor]==-1)
                {
                    col[neighbor]=1- col[i];
                    q.push(neighbor);

                }

                else if(col[neighbor] == col[i])
                    return false;
            }


        }
        return true;




    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {

        if(N==0)
            return true;
        vector<vector<int>> adj(N+1,vector<int>());
        vector<int> col(N+1,-1);


         int vsize=dislikes.size();
        for(int i=0;i<vsize;i++)
        {
            int x=dislikes[i][0];
            int y=dislikes[i][1];

            adj[x].push_back(y);
            adj[y].push_back(x);

        }

        for(int i=1;i<=N;i++)
        {
            if(col[i]==-1)
            {
             if(!isBipartite(i,adj,col))
                   return false;
            }
        }
        return true;




    }
};

//TC =O(E+V)   E is no of edges V= no of vertices 
//SC=O(1)  if stack space is ignored
