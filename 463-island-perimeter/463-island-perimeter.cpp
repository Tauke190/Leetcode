class Solution {
public:
    
    vector<vector<int>> dir {{0,1},{1,0},{-1,0},{0,-1}};
    
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int perimeter = 0;
        
        vector<vector<int>> isvisited(row ,  vector<int>(col,0));
        
        int first_i = 0;
        int first_j = 0;
       
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                if(grid[i][j] == 1)
                {
                    first_i = i;
                    first_j = j;
                    break;
                }
            }
        }
        
        cout<<first_i<<first_j<<endl;
       
        
        dfs(first_i,first_j,grid,isvisited,perimeter);
        return perimeter;
    }
    
    
    void dfs(int i , int j , vector<vector<int>> &grid, vector<vector<int>> &isvisited, int &perimeter)
    {
        
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            perimeter++;
            return;
        }
        if(grid[i][j] == 0)                         //Is water
        {
            perimeter++;
            return;
        }
        if(isvisited[i][j] == 1)
        {
            return;
        }
        isvisited[i][j] = 1;
        
        
        for(auto x : dir)
        {
            dfs(i+x[0], j+x[1] , grid , isvisited, perimeter);
        }
           
        
       
    }
};