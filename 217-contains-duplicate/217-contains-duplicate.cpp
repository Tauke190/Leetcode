/* 
Difficulty - Easy 
Type - Array
Attmept 1  - Solved 7 mins

Algorithm 1 (Time Complexity : 0(N) , Space Complexity : 0(N))
1.Use HashMap


Algorithm 2 (Time Complexity : 2*0(N) , Space Complexity : 0(1))
1.Use Inplace sorting and check for consecutive elements


*/

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
                break;
            }
        }
        
        return hasduplicate;
    }
};