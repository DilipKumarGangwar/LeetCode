/*
 You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

*/


//Solution

class Solution {
public:
    int numJewelsInStones(string J, string S) {

        set<char> s;
        int J_len=J.size();
        int S_len=S.size();
        for(int i=0;i<J_len;i++)
        {

            s.insert(J[i]);

        }
        int c=0;

        for(int i=0;i<S_len;i++)
        {

            if(s.find(S[i])!=s.end())
               c++;

        }
        return c;



    }
};

//TC = O(M+N)
//SC = O(1)
