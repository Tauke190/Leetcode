 /* Difficulty - Medium 
    Type - Graph/DFS/BFS
    Attmept 1  -  Almost done it 80%. Algorithm was right but could not implement it
    
    
    Time Complexity : 0(nxm)
    Space Complexity : 0(nxm)
    
    
    Algorithm 
    1.Make a results matrix
    2.Make a bool matrix to store which cell can flow through pacific
    3.Make a bool matrix to store which cell can flow through altantic
    4.Run dfs with pacific for the corresponding column and row
    5.Run dfs with atlantic for the corresponding column and row
    6.DFS Logic, carries position, matrix , previous , ocean 
    7.Border Check 
    8.If the ocean is already visited check
    9.If the current element if smaller than the previous element check
    10.Do dfs in all direction and pass the current element as the prev for the next recursion
    11.Now check the overlapping cell in both pacific and atlantic
    12.If both can flow to both oceans
    13.Put its indices in vector and push to the results
    14.Return the results
    */

class Solution 
{
    
    vector<vector<int>> dir {{1,0},{0,1},{-1,0},{0,-1}};
    
public:    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        
        int row = heights.size();           
        int col = heights[0].size();
        vector<vector<int>> results;
        
        
        bool** pacific = new bool*[row];           // Make a bool matrix to store if cell can flow to pacific
        for(int i = 0 ; i < row ; i++)
            pacific[i] = new bool[col];
        
        bool** atlantic = new bool*[row];         // Make a bool matrix to store if cell can flow to atlantic
        for(int i = 0 ; i < row ; i++)
            atlantic[i] = new bool[col];
        
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col; j++)
            {
                pacific[i][j] = false;          // Intialize both the dynamic matrix
                atlantic[i][j] = false;
            }
        }
        
        
       //DFS Logic Here
        
        for(int i = 0 ; i < row ; i++)
        {
            dfs(i,0,INT_MIN,heights,pacific);                 // Runs dfs from first column for pacific 
            dfs(i,col-1,INT_MIN,heights,atlantic);            // Runs dfs from last column  for atlantic
        }
        
        for(int j = 0 ; j < col ; j++)
        {
            dfs(0,j,INT_MIN,heights,pacific);                 //Runs dfs from first row for pacific
            dfs(row-1,j,INT_MIN,heights,atlantic);            //Runs dfs from last row for atlantic
        }
        
    
        for(int i = 0 ; i < row ; i++)
        {
            for(int j = 0 ; j < col; j++)
            {
                if(pacific[i][j] && atlantic[i][j])  // if both cell can flow to both ocean, return its indicies
                {
                    vector<int> pair{i,j};
                    results.push_back(pair);
                }
            }
        }
        
        return results;
       
    }
    
    
    void dfs(int i , int j , int prev , vector<vector<int>>& heights, bool** ocean)
    {
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size())         // Border check
            return;
        if(ocean[i][j])                                     //Already visited check
            return;
        if(heights[i][j] < prev)         //If the current element is smaller than previous element check
            return;
        ocean[i][j] = true;              //Water can flow from this block to a particular ocean
        
        for(auto x : dir)
        {
            dfs(i+x[0],j+x[1],heights[i][j],heights,ocean);         // dfs in all four direction
        }
    }
  
};