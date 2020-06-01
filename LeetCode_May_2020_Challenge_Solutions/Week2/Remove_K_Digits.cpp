/*
 Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

//Solution

class Solution {
public:
    string removeKdigits(string a, int k) {

        int i=0;
        int n=a.length();

        // while(a[i]<a[i+1])
        // {
        //     i++;
        // }

        int c=0;
        while(c<k)
        {
            if(i==n-1)
            {
                if(a[i]=='0')
                    break;
                a.erase(i,1);
                i--;
                c++;
                n=n-1;

            }
            else if(i==0)
            {
                if(a[i]=='0')
                {
                    a.erase(i,1);
                    n=n-1;

                    continue;
                }
                else if(a[i]>a[i+1])
                {
                    a.erase(i,1);
                    c++;
                    n=n-1;

                }
                else
                {

                while(i!=n-1&&a[i]<=a[i+1])
                {
                    i++;
                }
                 a.erase(i,1);
                 c++;
                i--;
                 n=n-1;
                }
            }

            else
            {
                while(i!=n-1&&a[i]<=a[i+1])
                {
                    i++;
                }
                 a.erase(i,1);
                 c++;
                i--;
                 n=n-1;
            }

            }//end of outer while



         //remove leading 0's and print 0 for o, 00, 000,....
            i=0;


        while(i<n)
        {
            if(a[i]=='0')
            {

                i++;
            }
            else
                return a.substr(i,n-i);
        }
        return "0";



    }
};

//TC = O(N)  //considering complexity of erase as O(1) 
//SC = O(1)
