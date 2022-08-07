class Solution {
public:
    
    bool containsDuplicate(vector<int>& nums) 
    {
        int N = nums.size();
        bool hasduplicate = false;
        unordered_map<int,int> hmap;
        
        for(int i = 0 ; i < N; i++)
        {
            if(!hmap[nums[i]])
            {
                hmap[nums[i]]++;
            }
            else
            {
                hasduplicate = true;
            }
        }
        
        return hasduplicate;
    }
};