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
 
class Solution {
public:
    TreeNode* helper(int l, int r,vector<int>& nums)
    {
        //Binary Search Bitch so it become balanced 
        while(l > r)
            return NULL;        
        int m =  l +(r-l)/2;
        
        TreeNode* rooter = new TreeNode(nums[m]);
        rooter->left = helper(l,m-1,nums);
        rooter->right = helper(m+1,r,nums);
        
        return rooter;
        

    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        
        return helper(0,nums.size()-1,nums);
        
    }
};