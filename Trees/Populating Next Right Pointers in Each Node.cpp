#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/* Difficulty - Easy 
Type - Depth First Search
Attmept 1  - Done with a tiny little bit of help but took 2 hours ...the solution took only 15 mins to figure out



Algorithm
1.So the left child has to point to right child which is always the case since it is complement binary tree
2.Right child points to the left child of the next pointer if the next pointer is not NULL
3.If the next pointer is null , right child points to NULL to
4.Do a bfs or level order traversal and call it from every node
*/


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) 
    {
       bfs(root);
        
        return root;
    }
    
    void bfs(Node* &root)
    {
        if(root!=NULL)
        {
            cout<<root->val;
            if(root->left && root->right)
            {
                root->left->next = root->right;
                if(root->next != NULL)
                {
                    root->right->next = root->next->left;
                }
                else
                {
                    root->right->next = NULL;
                }
            }
           
            bfs(root->left);
            bfs(root->right);
        }
        
    }
};
