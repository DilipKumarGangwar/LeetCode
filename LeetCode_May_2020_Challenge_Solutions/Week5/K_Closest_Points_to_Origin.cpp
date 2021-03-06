/* We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000
 
*/

//Solution

struct comparePoints{
    
    bool operator()(const vector<int> &p1,const vector<int> &p2){
        int d1=(p1[0]*p1[0]+p1[1]*p1[1]);
        int d2=(p2[0]*p2[0]+p2[1]*p2[1]);
        return d1<d2;
    }  
};
class Solution {
public:
    
     //Method 1: Sort By Sorting in vector /array 
     
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            sort(points.begin(),points.end(),comparePoints());

            vector<vector<int>> ans;
            for(int i=0;i<K;i++){
                ans.push_back(points[i]);

             }
             return ans;
        }
};
    
    
    
    // Priority Queue (Heap) method
 
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
//         priority_queue < vector<int> ,vector<vector<int>>,comparePoints> pq;
        
//         for(vector<int> &pt : points){
//           if(pq.size() < K)
//               pq.push(pt);
//           else{
//               //find distances first and push in queue accordingly
//               vector<int> top= pq.top();
              
//               int d1= pt[0]*pt[0] + pt[1]*pt[1];
//               int d2= top[0]*top[0] + top[1]*top[1];
              
              
//               if(d1 < d2){
//                   pq.pop();    //pop top element / point
//                   pq.push(pt);   //push incoming point
//               }
              
             
//           }   
          
        
//         }  //end of for
        
//          vector<vector<int>> ans;
//          while(!pq.empty()){
//              ans.push_back(pq.top());
//              pq.pop();
            
//          }
//          return ans;
        
//};

//Method 1: Sort By Sorting in vector /array 
//TC= O(NlogN)
// Priority Queue (Heap) method
//TC= O(NlogK)
