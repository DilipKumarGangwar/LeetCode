/*
 An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
*/

//Solution

class Solution {
public:

   bool isSafe(int i,int j,int row,int col)
    {

        if(i<0 || i>=row || j<0 || j>=col) //=> out of boundary
            return false;
        return true;

    }
    vector<vector<int>> floodFillUtil(vector<vector<int>>& image, int i, int j, int newColor,vector<vector<bool>> visited,int row,int col)
    {


        visited[i][j]=true;
        if(isSafe(i,j+1,row,col)&&image[i][j]==image[i][j+1] && visited[i][j+1]==false)
        {

               floodFillUtil(image,i,j+1,newColor,visited,row,col);


        }

        if(isSafe(i+1,j,row,col)&& image[i][j]==image[i+1][j] && visited[i+1][j]==false)
        {

               floodFillUtil(image,i+1,j,newColor,visited,row,col);


        }
         if(isSafe(i,j-1,row,col) && image[i][j]==image[i][j-1]  && visited[i][j-1]==false)
        {

               floodFillUtil(image,i,j-1,newColor,visited,row,col);


        }

        if(isSafe(i-1,j,row,col) && image[i][j]==image[i-1][j]  && visited[i-1][j]==false)
        {

               floodFillUtil(image,i-1,j,newColor,visited,row,col);


        }

        image[i][j]=newColor;

        return image;

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row=image.size();
        int col=image[0].size();

        vector<vector<bool>> visited(row,vector<bool>(col,false));
        return floodFillUtil(image,sr,sc,newColor,visited,row,col);



    }
};

//TC = O(row*col)
//SC = O(1)  id=f stack space is ignored
