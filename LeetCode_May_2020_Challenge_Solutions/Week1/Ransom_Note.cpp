/*
 Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.
Example 1:

Input: ransomNote = "a", magazine = "b"
Output: false
Example 2:

Input: ransomNote = "aa", magazine = "ab"
Output: false
Example 3:

Input: ransomNote = "aa", magazine = "aab"
Output: true

Constraints:

You may assume that both strings contain only lowercase letters.
*/

//Solution

class Solution {
public:
    bool canConstruct(string ran, string magazine) {


        map<char,int> mp;
        int n;
        n=magazine.length();
        for(int i=0;i<n;i++)
        {
            mp[magazine[i]]++;
        }
        int m=ran.length();
        int i;
        for( i=0;i<m;i++)
        {
            mp[ran[i]]--;
               if( mp[ran[i]]<0)
                   break;
        }

        if(i==m)
        {
            return true;
        }
        else
            return false;

    }
};

//TC = O(N+M)
//SC = O(1)
