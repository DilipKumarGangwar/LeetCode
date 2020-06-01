/*
 Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

//Solution

class Solution {
public:
    bool checkAnagram(int p_count[],int s_count[],vector<int> &ans)
    {
        int i;


        for(i=0;i<26;i++)
        {
            if(p_count[i]!=s_count[i])
                return false;
        }

        return true;


    }
    vector<int> findAnagrams(string s, string p) {



        int p_len=p.size();
        int s_len=s.size();
         vector<int> ans;
         if(s_len<p_len)
             return ans;

        int i;
        int p_count[26]={0},s_count[26]={0};
      for(i=0;i<p_len;i++)
          p_count[p[i]-'a']++;

         string s_str="";
        for(i=0;i<p_len;i++)
        {

            s_count[s[i]-'a']++;
        }

        if(checkAnagram(p_count,s_count,ans))
              ans.push_back(0);


        int n=s_len-p_len;
        for( i=1;i<=n;i++)
        {
            s_count[s[i+p_len-1]-'a']++;
            s_count[s[i-1]-'a']--;


          if(checkAnagram(p_count,s_count,ans))
              ans.push_back(i);

        }

        return ans;

    }
};

//TC = O(26* length of string s)
//SC = O(1)
