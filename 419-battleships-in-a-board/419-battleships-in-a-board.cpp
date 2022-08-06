class Solution {
public:
    
    
    vector<vector<int>> dir {{0,1},{1,0},{-1,0},{0,-1}};
    int countBattleships(vector<vector<char>>& board)
    {
        int result = 0; 
        int row = board.size();
        int col = board[0].size();
        
        
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                if(board[i][j] =='X')
                {
                    result++;
                    dfs(board,i,j);
                }
            }
        }    
        return result;
    }
    
    void dfs(vector<vector<char>> &board , int i , int j)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
        {
             return;
        }
        if(board[i][j] =='X')
        {
            board[i][j] = 'Y';
            for(auto x : dir)
            {
                dfs(board ,i + x[0] , j + x[1]);
            }
        }   
    }
};