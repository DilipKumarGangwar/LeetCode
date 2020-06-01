/*
 In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

Constraints:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/

//Solution

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

   void  parent_and_level(TreeNode* root,TreeNode** parent,TreeNode* prev, int level ,int *maxlevel,int val_to_check)
   {

       if(root->val==val_to_check)
       {
           *parent=prev;
           if(level>*maxlevel)
               *maxlevel=level;


       }
       if(root->left)
            parent_and_level(root->left,parent,root, level+1,maxlevel,val_to_check);
       if(root->right)
            parent_and_level(root->right,parent,root, level+1,maxlevel,val_to_check);


   }


    bool isCousins(TreeNode* root, int x, int y) {


        TreeNode * parent1=NULL,*parent2=NULL;
        int maxlevel1=0,maxlevel2=0;

        parent_and_level(root,&parent1,NULL, 0,&maxlevel1,x);
        parent_and_level(root,&parent2,NULL, 0,&maxlevel2,y);

        if(parent1!=parent2&&maxlevel1==maxlevel2)
            return true;
        return false;




    }
};

//TC = O(N)
//SC = O(Height of tree)
