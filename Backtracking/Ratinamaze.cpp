#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
/* 
Difficulty - Medium 
Type - Backtracking 
Attmept 1  - Almost solved it but forgot to keep track of already visited cell

Time Complexity  :  0(2^(m*n)) 
Space Complexity :  0(m*n)

Algorithm
1.Make a isvisited array
2.Make a vector to store the strings
3.Make a recursive formula that accepts the current rat position, board , isvisted array and the path string and results
4.In the first part of the recursion call, check if the rat position is in the destination
5.If yes then push the path it had formed to the results
6.Then individually look at the cell in all the direction
7.If it exisit and is not visited and is 1 which is not a wall
8.Make the recursion go there mark it , and if the condition is not met in the further recursion call unmark the visited
cell and that is the backtracking logic
9.Do this this for Up,Down,Right,Left
*/


class Solution {
public:
    int totalNQueens(  vector<vector<int> > board) 
    {
        vector<string> results;
        
        vector<vector<int> > isvisited(board.size(),vector<int>(board.size(),0)); 
        // vector<vector<int> > m  { {1, 0, 0, 1 },
        //                          { 1, 1, 0,  1 }, 
        //                          { 1, 1, 0,  1 },
        //                          { 0, 1, 1,  1 }};
        
       recurseForward(board,0,0,results,"",isvisited); // Source position
        return 0;
    }
    void recurseForward(vector<vector<int> > &board, int i , int j , vector<string> results, string path, vector<vector<int> > &isvisited)
    {
        
        int N = board.size();
        if(i == 0 && j == 3)
        {
            cout<<path<<endl;
            results.push_back(path);
            return;
        }
        if(i + 1 < N && !isvisited[i+1][j] && board[i+1][j] == 1) // Down
        {
            isvisited[i][j] = 1;
            recurseForward(board,i+1,j,results, path + 'D',isvisited);
            isvisited[i][j] = 0;   
        }
        if(j + 1 < N && !isvisited[i][j+1] && board[i][j+1] == 1) // Right
        {
            isvisited[i][j] = 1;
            recurseForward(board,i,j+1,results,path +'R',isvisited);
            isvisited[i][j] = 0;   
        }
        if(j - 1 >= 0 && !isvisited[i][j-1] && board[i][j-1] == 1) // Right
        {
            isvisited[i][j] = 1;
            recurseForward(board,i,j-1,results,path +'L',isvisited);
            isvisited[i][j] = 0;   
        }
         if(i - 1 >= 0 && !isvisited[i-1][j] && board[i-1][j] == 1) // Down
        {
            isvisited[i][j] = 1;
            recurseForward(board,i-1,j,results, path + 'U',isvisited);
            isvisited[i][j] = 0;   
        }
    }
                                                    
       
};