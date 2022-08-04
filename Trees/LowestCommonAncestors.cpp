#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/* The distance from n1 to n2 can be computed as the distance from the root to n1,
plus the distance from the root to n2, minus twice the distance from 
the root to their lowest common ancestor */


 //The first node n with the lowest depth which lies in between n1 and n2 (n1<=n<=n2) when traversing the tree



 

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root == NULL)
           return NULL;
        if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left,p,q);
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};