#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* 
Difficulty - Hard 
Type - String 
Attmept 1  - Done with BruteForce with syntax help( 1 : 30 mins)
Time Complexity: 0(N^2)
Space Complexity: 0(N)

Attempt 2 - Could not do in 0(N)
Time Complexity: 0(N)
Space Complexity: 0(N)



Algorithm 1 (Bruteforce)
1. Make a hashtable]
2. Make a window_start and window_end
3.The window_size changes every iteration to visit every possible combination
4.Put the values inside the window in the hash table and count number of elements
5.Erase the key or decrease its count from the window accordingly
6.Accumulation the value of the hashtable can be a useful trick to see how many elements are there in hash table


Algorithm 2 (Dynamic Programming)
1. Make a array with 26 and fill it with 1
2. Make a DP array , the DP of the array holds the max substring until that index
3. Loop through the array and add previous element of th DP + i - theindexofthelastoccuring of the character
4. Now add the last element of dp into some results
5. Keep track of the index of the last occuring character
6. Return the result

*/
class Solution {
public:
    long long appealSum(string s) 
    {
        unordered_map<char,int> h_map;
        
        int window_start = 0;
       
        long long result = 0;
        
        
        for(int i = 1 ; i <= s.length() ; i++) // This is to increase window size
        {
            
            for(int window_end = 0 ; window_end < s.length() ; window_end++)
            {
               
                h_map[s[window_end]]++;
              
                int total = 0;
                
                // Accumlate all the values of the key in the hash_map
                for (unordered_map<char,int>::iterator it = h_map.begin() ; it != h_map.end();it++) 
                {
                   total += it->second;
                }
                
                if(total == i) // I is the window size
                {
                     result += h_map.size();
                     cout<<result<<endl;
                    
                     if(h_map[s[window_start]] > 1)
                     {
                          h_map[s[window_start]]--;
                     }
                     else
                     {
                          h_map.erase(s[window_start]);
                     }
                     window_start++;
                }
            }
            window_start = 0;
            h_map.clear();
        }
        return result;
        
    }

    
};

class Solution {
public:
    long long appealSum(string s) 
    {
        int N = s.length();             // Store alphabetical index
        vector<int> lastindex(26,-1);
      
        long total = 0;
        vector<long> dp(N+1,0);
        
        
        for(int i = 0 ; i < s.length() ; i++)
        {
            long curr = s[i] - 'a'; // Gets the alphabetical index of the current
            
         
            dp[i + 1] = dp[i] + i  - lastindex[curr];
            
            total += dp[i+1];
            
            lastindex[curr] = i;
            
        }
        return total;
    }
};

