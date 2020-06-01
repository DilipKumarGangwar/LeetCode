/*Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
*/

//Solution

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

         int r=matrix.size();
        if(r==0)
            return 0;
        int c=matrix[0].size();
        if(c==0)
            return 0;

        vector<int> count(c,0);
        int result=0;
        int top=0,left=0,topleft=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
             {
                 if(matrix[i][j]==1)
                 {
                     top=(i==0)?0 : count[j];
                     left=(j==0)?0: count[j-1];

                     count[j]=1+min({top,left,topleft});
                     result+=count[j];
                     topleft=(j==c-1)?0:top;
                 }
                else
                    count[j]=0;



            }
        }
        return  result;
    }


};

//TC = O(r*c)
//SC = O(length of a matrix row , which is c )

