
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0 ;
        int right = nums.size()-1;
        
        int ans = 0;
        
        
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            
            if(nums[mid] == target)
            {
                ans = mid;
                return ans;
            }
            else if(nums[mid] > target)
            {
                right = mid-1;
                if(ans > left)                  //checking for extreme left condition
                {
                    ans = mid - 1;              // the ans will always be left or right of the mid
                }                              //keep index is going left
            }
            else
            {
                left = mid+1;
                if(ans <= right)                //optional
                {                               // the ans will always be left or right of the mid
                    ans = mid + 1;             // index is going right
                }
                
            }
        }
        
        return ans;
        
    }
};