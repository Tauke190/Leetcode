
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/* 
Difficulty - Medium 
Type - Depth First Search
Attmept 1  - Solved it with a little bit of help , 2 hours , Forget to mark visited node and it cause out of bounds error

Algorithm
1. We look for neighbours in each 1's block recursively
2. For the recursive function 
   Base Condition(Return 0)
   -Check if the index are in bounds
   -Check if the number is 0
3. If it passes all the condition , it is a valid neighbour and mark it ( Make it 0 ) so that it doesnt be counted again
4. Make the recusive call for all the neighbours up,down,left,right while adding it and add + 1
*/
class Solution 
{
public:
    int neighbours = 0;
    int maxAreaOfIsland(vector<vector<int> >& grid)
    {
        
        //Search for neighbours in each one cell
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[i].size();j++)
            {
                if(grid[i][j]== 1)
                {
                    neighbours = max(neighbours,lookforneighbours(i,j,grid));   // We look for neighbours in each 1's block recursively
                }
            }
        }
        return neighbours;
    }
    
    int lookforneighbours(int row,int column,vector<vector<int> >&grid)
    {
        //Base Conditions that stops the recursion
        if(row < 0 || column < 0)
        {
             return 0;
        }
        if(row >= grid.size() || column >= grid[0].size())
        {
            return 0;
        }
        if(grid[row][column] == 0)
        {
            return 0;
        }
        grid[row][column] = 0;                            // Mark it so it isnt counted again
        return  (1 + lookforneighbours(row+1,column,grid) // If it passes all the condition add 1
                  + lookforneighbours(row,column+1,grid)
                  + lookforneighbours(row,column-1,grid)
                  + lookforneighbours(row-1,column,grid));
    }
};





