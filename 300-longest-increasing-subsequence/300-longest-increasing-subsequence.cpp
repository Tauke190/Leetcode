/* 
Difficulty - Easy 
Type - Dynamic Programming
Attmept 1  - Could not Solve it ( Had to memorize neetcode video)



Time  Complexity: 0(N^2)
Space Complexity: 0(N)

Algorithm
1.The idea is starting from the back and see what subsequence length they can form
2.The last element will always have one so we intialize the dp array to be 1
3.We move left from them . and check right from there those element which is greater than the current element
4. dp[i] = max(dp[i] , dp[c] + 1)the length of subsquence in those elements greater than the current element)
5. Now we have found the length of subsequece from each index
6. We keep track of the max length
7. Return the max length
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
       
        int N = nums.size();
        vector<int> dp(N,1);        // Set the DP array to one because all the subsequence can have at least 1
        
        if(N == 1)
            return 1;
        int current_element = 0;    
        
        int ans = 0; 
        
        for(int i = N-1 ; i >= 0 ; i--)
        {
           current_element = nums[i];   // The current element from which we are trying to find the increasing subsequence
            for(int j = i+1 ; j < N ; j++)
            {
                if(current_element < nums[j]) // We find those elements in which this element can be part of to form a subsequence
                {
                    dp[i] = max(dp[i], 1+ dp[j]); // We select the subsequence with the maximum length
                }
                
                ans = max(ans,dp[i]);
            }
        }
        
      
        
        return ans;
    }
};