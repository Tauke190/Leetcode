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
    int maxDepth(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1 + max(maxDepth(root->left),maxDepth(root->right));   //Compare the height of the left and right children and return 
                                                                      // what is greater
    }
};