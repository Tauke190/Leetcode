class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        
        
        
        int N = matrix.size();
        
        
        for(int col = 0 ; col < N ; col++)
        {
            for(int row = col ; row < N ; row++)
            {
               swap(matrix[row][col] , matrix[col][row]);
            }
        }
        
        
        for(int row = 0 ; row < N ; row++)
        {
            int left = 0; 
            int right = N - 1;
            
            while(left < right)
            {
                swap(matrix[row][left],matrix[row][right]);
                left++;
                right--;
            }
        }
    }
};