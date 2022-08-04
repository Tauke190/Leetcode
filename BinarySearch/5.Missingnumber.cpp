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


// Method 2 : Sum approach O(nlogn)

class Solution
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int totalsum1 = (n*(n+1))/2;
        int totalsum2 = 0;
        
        int missing = 0;
    
        cout<<totalsum1<<endl;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            totalsum2 += nums[i];
        }
         cout<<totalsum2<<endl;
        
        missing = totalsum1 - totalsum2;
               
      return missing;
    }
};