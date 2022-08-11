/* 
Difficulty - Easy 
Type - Dynamic Programming
Attmept 1  - Could not solve it (I am fucking dump)




Time  Complexity: 0(m*n)
Space Complexity: 0(m*n)

Algorithm
1. Always start from the start ( The Dp tabulation bottom up approach)
2. In the double loop , check if the last characters are same
3. If equal subsequence length would increase by 1  + the results that comes after that , so we dont need to calculate it. dp[i][j] = 1 + dp[i+1][i+1];
4. If not equal than it is the max of the subsequence that was calculated before it (Its right and down neighbours)
5.Return dp[0][0] and Enjoy
*/



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int N1 = text1.size();
        int N2 = text2.size();
        vector<vector<int>> dp(N1+1, vector<int>(N2+1,0));
        
        for(int i = N1-1 ; i >= 0 ; i--)
        {
            for(int j = N2-1 ; j >= 0 ; j--)
            {
                if(text1[i] == text2[j])
                {
                    dp[i][j] = 1+dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
        
    }
};