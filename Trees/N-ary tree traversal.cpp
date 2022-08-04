#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
 

// Pre-order traversal in binary tree


// 1. Visit the root

// 2. preorder(root->left);

// 3. preorder(root->right);


// Pre-order traversal in binary tree

// 1. Visit the root  // Use Helped method to store into the vector or do something except print the root->val

// 2. preorder(root->children[i); all the children


class Solution {
public:
    vector<int> preorder(Node* root)
    {
        vector<int> mylist;
        preordervector(root,mylist);
        return mylist;
       
    }
    
    void preordervector(Node* root,vector<int> &list)
    {
        if(root == NULL)
            return;
        list.push_back(root->val);
        for(int i = 0 ; i < root->children.size() ; i++)
        {
            preordervector(root->children[i],list);
        }
    }
};
