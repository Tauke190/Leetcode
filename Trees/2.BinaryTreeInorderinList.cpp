#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <stack>

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



//Approach 1 Recursion
class Solution1{
// Since we cannot print we have to add to the list from the inside and for that we nee a parameter in the
//function itself


//We have to make a helper function that inserts in the final list ,The normal recursion happens in the 
//helper function


public:
    
     vector<int> inorderTraversal(TreeNode *root) 
     {
        vector<int> res;
        helper(root, res);
        return res;
     }
    
     void helper(TreeNode *root , vector<int> &res)
     {
         if(root != NULL)
         {
             helper(root->left,res);
             res.push_back(root->val);
             helper(root->right,res);
         }
     }
    
   
    
    
};


//Approach 2 Iteration
class Solution2 {

public:
     vector<int> inorderTraversal(TreeNode *root) 
     {
         stack<TreeNode*> stack;
         vector<int> res;

         TreeNode *current = root;




        while (current!= NULL || !stack.empty())
        {
            while( current!= NULL)
                {
                    stack.push(current);
                    current = current->left;

                //Now the current become null so make it top of the stack again
                }

            current = stack.top();
            res.push_back(current->val);
            stack.pop();
            current = current->right;

        }
        return res;
    
     }
};


