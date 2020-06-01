/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Follow up: Do not use any built-in library function such as sqrt.

Example 1:

Input: num = 16
Output: true
Example 2:

Input: num = 14
Output: false
 

Constraints:

1 <= num <= 2^31 - 1 

*/

//Solution

class Solution {
public:
    bool isPerfectSquareUtil(int num,int low,int high)
    {
        if(low>high)
            return  false;
        long long int mid=low+(high-low)/2;
        long long int sq=mid*mid;
        if(sq==num)
            return true;
        if(sq>num)
            return isPerfectSquareUtil(num,low,mid-1);
        return isPerfectSquareUtil(num,mid+1,high);



    }
    bool isPerfectSquare(int num) {

        if(num==0)
            return false;
        return isPerfectSquareUtil(num,1,num);
   }

};

//TC = O(lon sqrt(num))
//SC = O(1)
