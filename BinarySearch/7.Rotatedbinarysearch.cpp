#include <iostream>
#include <vector>


using namespace std;



/* Algorithm 
1.Check for left half 
2.Check whether the target lies there or not, it lies adjust the left and right accordingly 
3.Check for left half 
4.Check whether the target lies there or not, it lies adjust the left and right accordingly 
5.Return null if nothing found
 */
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;                                  
        int right = nums.size() - 1;
      
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                 return mid;
            }
            if(nums[left] <= nums[mid]) // check for left half  
            {
                if(nums[left] <= target && nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }               
            else                                // check for left half
                if(nums[right] >= target && nums[mid] < target)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid-1;
                }
        }
        return -1;
        
    }
};