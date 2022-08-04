#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

  struct TreeNode 
  {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
// Breadth-First search in the binary tree
//  1. Make a function that print the nodes on the current level (current level function)
//  2. In Currentlevelfunction , the recursion is done by decreasing the level 
//  3. Make another method that call the currentlevelfunctionbyeachlevel and store it in vector 
//  4. Create a new functio that returns the height or the depth of the tree.



class Solution {
public:
    int maxdepth(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1 + max(maxdepth(root->left), maxdepth(root->right));
    }
    
    
    vector<vector<int> > levelOrder(TreeNode* root) 
    {
       vector<vector<int> > total;
       for(int i = 1 ; i < maxdepth(root)+1 ; i++)
       {
           vector<int> mylevelnode;
           currentlevel(root,i,mylevelnode);
           total.push_back(mylevelnode);
       }
          
       return total;
    }
    
    void currentlevel(TreeNode* root ,int level,vector<int> &levelnodes)
    {
        if(root == NULL)
            return;
        if(level == 1)
            levelnodes.push_back(root->val);
        else
            currentlevel(root->left,level- 1,levelnodes);
            currentlevel(root->right,level -1,levelnodes);
    }
};
