class Solution 
{
public:
    int maxSubArray(vector<int>& nums)
    {
        
        int N = nums.size();
        int currsum = nums[0];
        int maxsum = nums[0];
        
        
        for(int i = 1 ; i < N ; i++)
        {
            currsum = max (nums[i] ,currsum + nums[i]);
            
            if(currsum > maxsum)
            {
                maxsum = currsum;
            }
            
         
        }
        return maxsum;
       
    }
};