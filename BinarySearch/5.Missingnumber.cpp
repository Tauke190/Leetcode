#include <iostream>
#include <vector>

using namespace std;

// Method 1 : Binary Search O(nlogn)
class Solution
{
public:
    int missingNumber(vector<int>& nums) 
    {
        
        sort(nums.begin(),nums.end()); //Binary search only works for a sorted array bitch
        
        int missingnum = 0;
    
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(search(nums,i))
            {
                missingnum++;
            }
            else
            {
                break;
            }
        }
               
      return missingnum;
    }
    
    bool search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid + 1;
        }
        return false;
    }
};


// Method 2 : Sum approach O(N)

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int N = nums.size();
        
        int totalsum = N * (N + 1)/2;               // Get the total sum of the natural numbers
        int vectorsum = 0;
        
        for(auto i : nums)                          // Get the sum of the elements in the vector
        {
            vectorsum +=  i;
        }
        
        return totalsum - vectorsum;               // The difference is the missing element in the vector
    }
};
