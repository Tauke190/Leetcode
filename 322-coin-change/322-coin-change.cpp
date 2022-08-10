/* 
Difficulty - Medium 
Type - Dynnamic Programming
Attmept 1  - Could Not Solve it but understood it very clearly form neetcode


Time  Complexity: 0(N)
Space Complexity: 0(1)

Algorithm
1. We basically make a dp array of length amount +1 with default value amount + 1
2. set dp[0] = 0 // Base case
3. We loop through the array
4. For each amount , we check which coin we can use 
5. For each usabale coin we take min of dp[i] , dp[i-c] + 1  i is the amount and c is the coin i = c means only one coin
6.We return the result if the dp[amount] is not equal to its default value


*/




class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1,amount+1); // Intialize the DP array to maximum number which is amount+1 , which is the max amount of coins needed for each amount
        
        dp[0] = 0;          //The numbers of coins needed to make 0 is 0
        
        for(int i = 1 ; i < amount+1 ; i++)
        {                                    // We check num of mimum coins needed for each amoun
            for(auto c : coins)
            {
                if(i - c >= 0)                // If the coins can be used to make that amount
                {
                    dp[i] = min(dp[i] , dp[i-c]+1);         // i-c basically return 0 if the amount = coin , then we need only 1 coin for that
                    //we check the mimimum value of each possible coin we can use
                }
            }
        }
        if(dp[amount] != amount + 1)
        {
            //If the dp[amount] is not same as default value]
            return dp[amount];
        }
        else
        {
            return -1;
        }
    }

   
    
};