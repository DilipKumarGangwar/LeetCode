/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.

*/

//Solution

class Solution {
public:
    int firstUniqChar(string s) {
        
       
        map<char,int> m;
        map<char, int>::iterator itr;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]] ++ ;
        }
        for(int i=0;i<s.size();i++)
        {
            itr = m.find(s[i]);
            if(itr -> second == 1)
                return i;
        }
        return -1;
    }
        
        
    
};

//TC = O(N)
//SC = O(1)
