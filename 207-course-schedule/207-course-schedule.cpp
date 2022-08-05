/* Difficulty - Medium 
    Type - DFS / Graph Coloring
    Attmept 1  -  Spent 5 hours on it , Could not do it
    

    Time Complexity : 0(V+E)
    Space Compexity : 0(N)
    
    Algorithm
    1.Make a adjancency list
    2.Make a isvisted array with 3 colors , explored , exploring , unexplored
    3.Run dfs on each of the unexplored node
    4.If dfs gives false , it mean it has cycle in its graph , return false
    5.Each recursive dfs function carries the node, adjlist, isvisted array
    6.Make the current node as processing 
    7.Look at its adjanent/neighbour node , it if its exploring , return false because it has cycle
    8.For the unexplored neighbour/adjance node, run dfs on that node and see if it has cycle or not
    9.For node with no neighbours
    10.Means it does not have prereqs and mark as visited and dfs will return true means no cycle
    */

class Solution {
    
    
    
    int WHITE = 0; // Unexplored        // Not completed the course
    int GREY = 1;  // Processing        // Current Course
    int BLACK = 2;  // Explored          //Completed the course
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        
        int N = numCourses;
        vector<vector<int>> adjlist(N);
        vector<int> isvisited (N,WHITE);
        
        for(int i = 0 ; i < prerequisites.size() ; i++)                //Construct the adjacency list
        {
            adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i = 0 ; i < N ; i++)                // Run DFS on each node
        {
            if(isvisited[i] == WHITE)               // If the nodes are unexplored
            {
                if(!dfs(i,adjlist,isvisited))         // dfs false means it has cycle
                {
                    return false;                               
                } 
            }
        }
        
        return true;
    }
    
    
    bool dfs(int node,vector<vector<int>> &adjlist,vector<int> &isvisited)
    {
        isvisited[node] = GREY;                                     //Processing this node
        
        for(int i = 0 ; i < adjlist[node].size() ; i++)           //Run dfs on its prereqs
        {
             if(isvisited[adjlist[node][i]] == GREY)              //If its prereqs is GREY , it mean its looping
             {
                    return false;                                   
             }
            if(isvisited[adjlist[node][i]] == WHITE)              //If the prereqs are unexplored , we run dfs
             {
                if(!dfs(adjlist[node][i],adjlist,isvisited))
                {
                    return false;                               //If dfs returns false it means it has a cycle 
                }
             }
        }
        
        isvisited[node] = BLACK;                            //It is completed because it has no prereqs
        return true;
    }
};