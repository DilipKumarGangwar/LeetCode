/*
  Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].


*/

//Solution

class Solution {
public:

    bool checkPermutation(int count_s1[],int count_s2[])
    {

        int i;
        for(i=0;i<26;i++)
        {
            if(count_s1[i]!=count_s2[i])
            {
                cout<<"ohh";
                return false;
            }
            cout<<"check=";
            // cout<<count_s1[i]<<" "<< count_s2[i]<<" ";

        }
        return true;


    }
    bool checkInclusion(string s1, string s2) {


        int s1_len=s1.size();
        int s2_len=s2.size();

        if(s2_len<s1_len)
            return false;

        int i;
        int count_s1[26]={0};
        int count_s2[26]={0};
        for(i=0;i<s1_len;i++)
            count_s1[s1[i]-'a']++;

        for(i=0;i<s1_len;i++)
            count_s2[s2[i]-'a']++;


        int n=s2_len-s1_len;

        for(i=0;i<n;i++)
        {

            if(checkPermutation(count_s1,count_s2))
                return true;

            count_s2[s2[i]-'a']--;
            count_s2[s2[i+s1_len]-'a']++;


        }


        if(checkPermutation(count_s1,count_s2))
                return true;


        return false;




    }
};

//TC=O(length of s2 * 26)
//SC=O(1)
