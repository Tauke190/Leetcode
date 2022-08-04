
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    
    
    /* 
    Difficulty - Medium 
    Type - Breadth First Search
    Attmept 1  - Spent 5 hours on this shit
    
    Algorithm
    1.I dont fucking know 

    */

    vector<vector<int> > updateMatrix(vector<vector<int> >& mat) 
    {
        
        queue<pair<int,int> > q;
        for(int i = 0 ; i < mat.size() ; i++)
        {
            for(int j = 0 ; j < mat[i].size(); j++)
            {
                if(mat[i][j] == 0)
                {
                   q.push( make_pair(i,j)); // Push the index into the queue
                }
                else
                {
                    mat[i][j] = -1; // To mark node as unvisited
                }
            }   
        }
        
        
        int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}}; // Neighbouring cells
        int length = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            length++;
            
            while(size-- >0) // After removing the top , is it greater than 1
            {
                pair<int,int> top = q.front();
                for(int i = 0 ; i < 4 ;i++)
                {
                    int neighbourX = top.first + dir[i][0];
                    int neighbourY = top.second + dir[i][1];
                    
                    if(neighbourX < 0 || neighbourY < 0 || neighbourX == mat.size()                               ||neighbourY == mat[0].size() || mat[neighbourX][neighbourY] != -1 )
                    {
                         continue;
                    }
                       
                    mat[neighbourX][neighbourY] = length;
                    q.push(make_pair(neighbourX,neighbourY));
                }
               q.pop();
            }
        
        }
        return mat;
    }
};