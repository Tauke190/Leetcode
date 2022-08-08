class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int N = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;
        
        
        
        
        for(int i = 0 ; i < N ; i++)
        {
            
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }
            int target = nums[i];  
            
            int left  = i + 1;
            int right = N - 1;
            
            while(left < right)
            {
                
                int threesum = target + nums[left] + nums[right];
                
                if(threesum > 0)
                {
                    right--;
                }
                else if(threesum < 0)
                {
                    left++;
                }
                else
                {
                    vector<int> triplets{target,nums[left],nums[right]};
                    results.push_back(triplets);
                    left++;
                    while(nums[left] == nums[left-1] && left < right)
                    {
                        left++;
                    }
                }
            }
        }
        return results;
    }
};