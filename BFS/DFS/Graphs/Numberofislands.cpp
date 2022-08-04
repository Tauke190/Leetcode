#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;




/* Algorithm
Time complexity : O(N^2)
Space complexity : O(N)

1.Think of a recurisive fucntion to do it from a single element in the grid at 0,0
2.The recursive function will travel to its neighbours and if it is '1' , it will change its value to '0'
3.We call this recursive function from every element in the grid in double loop
4.Before we call this recusive function , when we find a element '1' and add to result afterwards it will change to '2'
and we will lose its track  */

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) 
    {
        int result = 0;
        for(int i = 0 ; i < grid.size() ; i++)
        {
            for(int j = 0 ; j < grid[0].size() ; j++)
            {   
                if(grid[i][j] == '1')
                {
                    result++;
                    dfs(grid,i,j);
                }
            }  
        }
        return result;
    }
    
    void dfs(vector<vector<char> >& grid, int r , int c)
    {
        if(grid[r][c] == '1')
        {
            grid[r][c] = '2';
            if(r >=1)
            {
                dfs(grid,r-1,c);            //. go left if you can 
            }
            if(c >=1)
            {
                dfs(grid,r,c-1);            //. go up if you can
            }
            if(r+1 < grid.size())           //. go right if you can
            {
                dfs(grid,r+1,c);
            }
            if(c+1 < grid[0].size())       //. go down if you can
            {
                dfs(grid,r,c+1);
            }
        }
    }
};