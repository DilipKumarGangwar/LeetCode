/*
 Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.

*/ 

//Solution

class Solution {
public:
    int findMaxLength(vector<int>& a) {

        unordered_map<int,int> mp;
        int i;
        int n=a.size();

        int sum=0,max_len=0;
        mp.insert({sum,-1});
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
                sum++;
            else if(a[i]==0)
                sum--;

            //check sum in hashmap
             unordered_map<int,int> :: iterator it;
            it=mp.find(sum);
            if(it!=mp.end())
            {

                max_len=max(max_len,i-it->second);
            }

            else
                mp.insert({sum,i});



        }

    return max_len;
    }
};

//TC=SC=O(n)
