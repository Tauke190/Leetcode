#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;








class Solution {
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];
        
        vector<int> lootedcash(nums.size()+2,0);
        
        lootedcash[0] = 0;
        lootedcash[1] = 0;
        
        
        for(int i = 2 ; i <= nums.size()+1 ; i++)
        {
            lootedcash[i] = max(lootedcash[i-1] , nums[i-2] + lootedcash[i-2]); 
        }
        
        return lootedcash[nums.size()+1];
        
    }
};