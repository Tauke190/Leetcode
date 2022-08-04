/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) 
    {
        
        if(node == NULL)
            return NULL;
        unordered_map<Node*,Node*> hmap;    // Key = Address of Original Graph
                                            // Value = Address of Cloned Graph
        queue<Node*> q;
        
        q.push(node);
        
        Node* src = new Node(node->val);
        
        hmap[node] = src;
        
        
        while(!q.empty())
        {
            Node* top = q.front();
            for(Node* neighbor : top->neighbors)
            {
                if(hmap[neighbor] == NULL) // If the node as not been constructed
                {
                    Node* newnode = new Node(neighbor->val);
                    hmap[neighbor] = newnode;
                    q.push(neighbor);
                }
                
                hmap[top]->neighbors.push_back(hmap[neighbor]);
            }
            
           // cout<<top->val;
            q.pop();
        }
        return hmap[node];
    }
    
};