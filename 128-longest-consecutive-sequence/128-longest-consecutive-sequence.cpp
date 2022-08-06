// #include <string>
// #include <iostream>
// #include <cmath>
// #include <vector>
// using namespace std;

// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };
// */

// class Solution {
// public:
    
//     Node* cloneGraph(Node* node) 
//     {
//         queue<Node*> q;
//         int counter = 0;
        
//         Node* clone;
        
//         set<int> neighboursfound;
        
//         q.push(node);
        
//         while(!q.empty())
//         {
//             vector <Node*> foundneighbours;
//             if(neighboursfound.find(q.front()->val) == neighboursfound.end()) // If not found on neighboursfound   
//             {
//                 for(Node* neighbour : q.front()->neighbors)
//                 {
//                     Node* newneighbour = new Node(neighbour->val);
//                     foundneighbours.push_back(newneighbour);
//                     q.push(neighbour);
//                 }
//                 Node* newnode = new Node(q.front()->val,foundneighbours);
//                 clone->neighbours = foundneighbours;
//                 cout<< newnode->val<<" : ";
                
//                 for(Node* x : newnode->neighbors)
//                 {
//                     cout<<x->val<<",";
//                 }
//                 cout<<endl;
//             }
//             neighboursfound.insert(q.front()->val);
//             q.front()->neighbors = foundneighbours;
//             q.pop();
//         }
//         return clone;
//     }
    
/* 
Difficulty - Medium 
Type - HashMap or DFS
Attmept 1  - Solved it with DFS but got TLA
Attempt 2  - Looked at the solution and used the hashmap

Time Complexity  : 0(N)
Space Complexity : 0(N)


Algorithm
1.Iterate through the array
2.Put the elements in the hashmap for 0(1) Lookups later
3.Again Iterate through the array
4.We build sequence from a number which is not part if the larger sequence 
5.To ensure that we see if the num - 1 is present in the hashmap
6.If not we procced and we set the currentstreak and the currentnum
7.While we have num + 1 (consective number ) in the hashmap , we increment the currentstreak and current num
8. At last we have max of the currentstreak in each iteration
9.Return the largest currentstreak store somewhere 
*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        
        unordered_map<int,int> hmap;
        
        int N = nums.size();
        
        if(N == 0)
            return 0;
        
        int higheststreak = 1;
        
        for(int i = 0 ; i < N ; i++)
        {
            hmap[nums[i]]++;
        }
        
        for(int i = 0 ; i < N ; i++)
        {
            if(!hmap[nums[i]-1])
            {
                int currentnum = nums[i];
                int currentstreak = 1;
            
                while(hmap[currentnum + 1])
                {
                    currentnum++;
                    currentstreak++;
                }
                higheststreak = max(higheststreak,currentstreak);
            }
           
        }
        
                  
        return higheststreak;
    }
};