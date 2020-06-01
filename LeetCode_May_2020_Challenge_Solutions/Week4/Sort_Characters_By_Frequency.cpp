/*
 Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/

//Solution

class Solution {
public:
    
     vector<pair<char,int>> createVector( map<char,int>  mp)
     {
     
        vector<pair<char,int>> v;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            v.push_back({it->first,it->second});
        }
        
        return v;
     }
    
      static   bool sortByValue(const pair<char,int> &a,const pair<char,int> &b)
      {
              return a.second>b.second;
      }
    
    string frequencySort(string s) {
     
        map<char,int> mp;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        vector<pair<char,int>> v(createVector(mp));
        
        sort(v.begin(),v.end(),sortByValue) ;
        string ans="";
        for(auto it=v.begin();it!=v.end();it++)
        {
            int freq=it->second;  
            for(int i=0;i<freq;i++)
            {
                ans+=it->first;
                
            }
            
          }
        return ans;
        
        
        
    }
};


//TC=SC=O(length of string)

