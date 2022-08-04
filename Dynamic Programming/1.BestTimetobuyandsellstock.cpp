#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:

// Method 1 : Two Pointers Method


    // Keep track of the buy_price and sell_price


    // if the sell_price - buy_price is negative profit then reset the buy_price and iterate from there 


    // then return the max_profit



    int maxProfit(vector<int>& prices) 
    {
        
        int i = 0;  //buy
        int j = 1;  //sell
        int max_profit = 0;
        
        while(j < prices.size())
        {
            int temp = prices[j] - prices[i];
            
            if(temp < 0)
            {
                i = j;
            }
            else
            {
                j++;
                max_profit = max(max_profit,temp);
            }
        }
        return max_profit;
    }


// Method 2 : Dynamic Programming


// 1. Keep track of the profit from the first element and second element over the loop

// 2. Keep the costprice minimum of the elements in the array so it is not greater than the selling price



    int maxProfit(vector<int>& prices) 
    {
        
        int costprice = prices[0];
        int profit = 0;
        
        
        for(int i = 1 ; i < prices.size(); i++)
        {
            profit = max(profit , prices[i] - costprice);
            costprice = min(prices[i],costprice);
          
        }
        return profit;
       
    }
};