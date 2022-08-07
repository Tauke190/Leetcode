/* 
Difficulty - Easy 
Type - Array / Kundanes algorithms
Attmept 1  - Fucking 3 hours
Attemp  2  - Fucking gave up and watched a video bitch


Algorithm(Only for positive numbers)
1. Keep on increasing its sum
2. If its max store it somewhere 
3. If the currentsum < 0 , then it does not subarray till that index does not contribute anymore ,reset it
4. Retun the maxsum and enjoy


Algorithm(Only for positive numbers)
1. First check if the current sum is negative, if it is currentsum = 0;
2. Increase the currentsum in the loop
3. If the currentsum is 

*/









class Solution 
{
public:
    int maxSubArray(vector<int>& nums)
    {
        
        int N = nums.size();
        int currsum = 0;
        int maxsum = nums[0];
        
        
        for(int i = 0 ; i < N ; i++)
        {
            
            currsum = currsum + nums[i];
            maxsum = max(maxsum,currsum);
            if(currsum < 0)
            {
                currsum = 0;
            }
        }
        return maxsum;
       
    }
};