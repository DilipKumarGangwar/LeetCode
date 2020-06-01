/*
 You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

//Solution

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int no_of_points=coordinates.size();
        if(no_of_points == 2)
            return true;
        double slope_initial_x,slope_initial_y;
        slope_initial_x=double(coordinates[1][1]-coordinates[0][1]);
        slope_initial_y=double(coordinates[1][0]-coordinates[0][0]);
      
        int i;
        for(i=1;i<no_of_points-1;i++)
        {
            double slope_curr_x,slope_curr_y;
            slope_curr_x=double(coordinates[i+1][1]-coordinates[i][1]);
            slope_curr_y=double(coordinates[i+1][0]-coordinates[i][0]);
            
            if((slope_initial_x * slope_curr_y )!= (slope_initial_y * slope_curr_x ))
                return false;
            
            
        }
        return true;
        
        
        
    }
};

//TC = O(Length of corrdinates array)
//Sc = O(1)
