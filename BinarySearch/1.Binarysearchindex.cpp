#include <iostream>
#include <vector>


using namespace std;

// Method 1 - Recursion 
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        
        int result = 0 ;
        binarysearch(nums,target,left,right,result);
        return result;
        

    }
    
    void binarysearch(vector<int>& nums, int target, int left ,int right , int &result)
    {
        int mid = (left + right) / 2;
        if(left <= right)
        {
           
            if(nums[mid] == target)
            {
                result = mid;
            }
            else if (nums[mid] > target)
            {
                binarysearch(nums,target,left,mid-1,result);
            }
            else
            {
                 binarysearch(nums,target,mid+1,right,result);
            }
        }
        else
        {
            cout<<" Not Found something";
            result = -1;
        }
        
       
    }
       
};

// Method 2 - Iteration ( While loop)
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        
        while(left <= right)
        {
            int mid = (left + right)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                right = mid-1;
            else
                left = mid + 1;
        }
        return -1;
    }
};