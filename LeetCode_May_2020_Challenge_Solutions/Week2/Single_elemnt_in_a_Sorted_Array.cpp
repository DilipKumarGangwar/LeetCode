/*
 You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10
 

Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

//Solution


int singleNonDuplicateUtil(vector<int>& a,int low,int high,int n)
{
  int mid;
   while(low<high)
   {
        mid=low+(high-low)/2;
    if(mid>0&&(a[mid-1] == a[mid]))
    {

        if(mid%2==0)
            high=mid-1;
        else
            low=mid+1;

    }
    else if(mid<n &&(a[mid+1]==a[mid]))
    {

        if(mid%2==0)

            low=mid+1;
        else
            high=mid-1;
    }
    else
        return a[mid];
   }
    return a[low]; //or a[high]


}
class Solution {

public:



    int singleNonDuplicate(vector<int>& nums) {


       return  singleNonDuplicateUtil(nums,0,nums.size()-1,nums.size());

    }
};

//TC = O(log n)
//SC = O(1)
