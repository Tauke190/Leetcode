#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
/* 
Difficulty - Hard 
Type - Backtracking 
Attmept 1  - Could not Solve it , Almost did it
Attmept 2  - Works only till 4

Time Complexity  :  0(n^6)
Space Complexity :  

Algorithm 1 (Backtracking without recursion)

*/

/* class Solution {
public:
    vector<vector<string> > solveNQueens(int n) 
    {
         string dotblock = "";
         vector<vector<string> > results;
         set<set<pair<int,int> > > pairresults;
         
        
        int queencount = 0;
         for(int i = 0 ; i < n ; i++)
         {
             dotblock +=".";
             for(int j = 0 ; j < n ; j++)
             {
                set<pair<int,int> > queenspos = startqueen(i,j,n);
                if(queenspos.size() == n)
                {
                    pairresults.insert(queenspos);
                }
             }
         }
       
        
       
      
        
        
        for(auto x : pairresults)
        {
           
           vector<string> block(n,dotblock);
           for(auto y : x)
           {
               block[y.first][y.second] = 'Q';
               cout<<y.first<<y.second<<",";
              
           }
            results.push_back(block);
            cout<<endl;
        }
        
        return results;
        //return {{}};
    }
    
    set< pair<int,int> > startqueen(int x , int y , int n)
    {
        set<pair<int,int> > queenpositions; 
        int queencounter = 0;
        
        queenpositions.insert(make_pair(x,y));
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(isnotinqueenspath(i,j,queenpositions))
                {
                    queenpositions.insert(make_pair(i,j));
                   // cout<<i<<j<<endl;
                  
                }
            }
        }
      
        return queenpositions;
    }
 
    
    bool isnotinqueenspath(int i , int j ,set<pair<int,int> > &queenpositions)
    {
        for(auto x : queenpositions)
        {
            if(i == x.first || j == x.second)
            {
                return false;
            }
            if(i + 1 == x.first && j + 1 == x.second) // Top left
            {
                return false;
            }
            if(i - 1 == x.first && j - 1 == x.second) // Bottom right
            {
                return false;
            }
            if(i + 1 == x.first && j - 1 == x.second) // Top right
            {
                return false;
            }
            if(i - 1 == x.first && j + 1 == x.second) // Bottom left
            {
                return false;
            }
        }
        return true;
    }
}; */

/* 
Difficulty - Hard 
Type - Backtracking 
Attmept 1  - Could not Solve it , Understood it properly with geeks for geek

Time Complexity  :  
Space Complexity :  

Algorithm 1 (Backtracking with recursion)
1.Start with the leftmost column
2.In that column , check for all the row
3.If the row in that column is safe , Mark that as Q and call the recursive call for another column
4.When column size is equal to the board size , that is base case and we return the result
5.After we mark the Q and call ir recursive call
6. If the call doesnt match the criteria , we backtrack in the previous call
7. After backtracking it tries in the different row and recursion happens again
8.In the issafe function , check the row and left side of the queen only ( lower diagonal and upper diagonal)
since we are moving to the right
9.

*/

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) 
    {
        vector<vector<string> > results;
        
        
        vector<string> dot(n,".");
        vector<vector<string> > board(n,dot);
        
        
        
        solveNQUntil(board,0,results);
        
        return results;
        
    }
    
    
    
    bool solveNQUntil(vector<vector<string> > board , int col, vector<vector<string> > &results)
    {
        int N = board.size();
        
      
        if(col == N)
        {
            vector<string> configuration;
            for(int i = 0 ; i < N ; i++)
            {
                string row  = "";
                for(int j = 0 ; j < N ; j++)
                {
                    row+= board[i][j];
                }
                configuration.push_back(row);
            }
            results.push_back(configuration);
            return true;
        }
           
        bool res = false;
        for(int i = 0 ; i < N ; i++)
        {
            if(isSafe(board,i,col))
            {
                board[i][col] = "Q";
                
                 res = solveNQUntil(board,col+1,results) || res;
                
                //Backtrack
                board[i][col] = ".";
                
            }
           
        }
        
        // If the queen cannot be placed in any row in this column , return false
        return res;
        
    }
    bool isSafe(vector<vector<string> > &board , int row , int col)
    {
        int N = board.size();   
        
        int i , j;
        for( i = 0 ; i < N ; i++)
        {
            if(board[row][i] == "Q") 
            {
                return false;
            }
        }
        for ( i = row,  j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == "Q")
            {
                return false;
            }
        }
        for ( i = row,  j = col; j >= 0 && i < N; i++, j--)
        {
           if (board[i][j] == "Q")
            {
                  return false;
            } 
        }
        return true;
    }
};


