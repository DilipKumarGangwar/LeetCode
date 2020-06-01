/*
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.  The intersection of two closed intervals is a set of real numbers that is either empty, or can be represented as a closed interval.  For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
Example 1:
Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

Note:
0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

*/i

//Solution

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>& b) {
     vector<vector<int>> ans;




        int n1=a.size();

        int n2=b.size();

        if(n1==0)
            return a;
        if(n2==0)
            return b;

        int i,j;
        for(i=0,j=0;i<n1&& j<n2;)
        {
             vector<int> temp;
            if(a[i][1] < b[j][0])
            {

                i++;
                continue;

            }
            else if(b[j][1] <  a[i][0])
            {
                j++;
                continue;

            }

            if(a[i][0] > b[j][0])
                temp.push_back(a[i][0]);
            else
                temp.push_back(b[j][0]);


            if(a[i][1] < b[j][1])
            {
                temp.push_back(a[i][1]);
                i++;
            }
            else
            {
                temp.push_back(b[j][1]);
                j++;

            }

            ans.push_back(temp);
        }





       return ans;
    }
};

//TC=SC=O(n1+n2)
