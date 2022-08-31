/* 
Difficulty - Medium 
Type - Matrix 
Attmept 1  - Could Not do it 
Attempt 2  - Could do it with a small hint



Algorithm
1. Change the matrix into the transpose of the matrix using swapping (will be easy)
2. Reverse the orders of the row or column in the according to the rotation in the question
3. Done
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
    
        int N = matrix.size();              
        
        for(int col = 0 ; col < N ; col++)
        {
            for(int row = col ; row < N ; row++)
            {
               swap(matrix[row][col] , matrix[col][row]);                   // Transforming the matrix into transpose matrix
            }
        }
        
        for(int row = 0 ; row < N ; row++)
        {
            int left = 0; 
            int right = N - 1;
            
            while(left < right)
            {
                swap(matrix[row][left],matrix[row][right]);                 // Reversing the order of every row in the matrix
                left++;
                right--;
            }
        }
    }
};