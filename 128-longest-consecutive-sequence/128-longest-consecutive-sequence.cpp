class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        
        unordered_map<int,int> hmap;
        
        int N = nums.size();
        
        if(N == 0)
            return 0;
        
        int higheststreak = 1;
        
        for(int i = 0 ; i < N ; i++)
        {
            hmap[nums[i]]++;
        }
        
        for(int i = 0 ; i < N ; i++)
        {
            if(!hmap[nums[i]-1])
            {
                int currentnum = nums[i];
                int currentstreak = 1;
            
                while(hmap[currentnum + 1])
                {
                    currentnum++;
                    currentstreak++;
                }
                higheststreak = max(higheststreak,currentstreak);
            }
           
        }
        
                  
        return higheststreak;
    }
};