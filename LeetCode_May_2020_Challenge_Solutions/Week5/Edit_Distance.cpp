/*Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 
*/

//Solution

class Solution {
public:

    //Method1: Space Optimised (DP)
    int minDistanceUtil(string word1, string word2, int m, int n){

        int result[n+1];
        int diag=0;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0)
                    result[j]=j;
                else if(j==0){
                    diag=result[j];
                    result[j]=i;
                }
                else if(word1[i-1]==word2[j-1]){

                    int temp=diag;   //save old diag (answer for now)
                    diag=result[j];   //update diag for next
                    result[j]=temp;


                }

                else{

                    int temp = 1+min({diag,result[j-1],result[j]});   //save old diag (answer for now)
                    diag=result[j];                     //update diag for next
                    result[j] = temp;
                }
            }
              for(int i=0;i<=n;i++)
                     cout<<result[i]<<" ";
            cout<<endl;
        }


        return result[n];
    }
    int minDistance(string word1, string word2) {

       return  minDistanceUtil(word1,word2,word1.size(),word2.size());


    }
};


//        Method 2: DP with 2D Array
// class Solution {
// public:

//     //Method1: Space Optimised (DP)
//     int minDistanceUtil(string word1, string word2, int m, int n){

//         int table[m+1][n+1];

//         for(int i=0;i<=m;i++){
//             for(int j=0;j<=n;j++){
//                 if(i==0)
//                     table[i][j]=j;
//                 else if(j==0)
//                     table[i][j]=i;
//                 else if(word1[i-1]==word2[j-1])
//                     table[i][j]=table[i-1][j-1];

//                 else

//                     table[i][j]= 1 + min(min(table[i-1][j],table[i-1][j-1]),table[i][j-1]);
//             }

//         }
//         for(int i=0;i<=m;i++){
//             for(int j=0;j<=n;j++){
//                 cout<<table[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         return table[m][n];


//    }
//     int minDistance(string word1, string word2) {

//        return  minDistanceUtil(word1,word2,word1.size(),word2.size());


//     }
// };

//Method 1: TC=O(m*n)   SC=O(m*n)
//Method 1: TC=O(m*n)   SC=O(n)    n is length of word2
