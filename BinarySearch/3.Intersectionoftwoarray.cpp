#include <iostream>
#include <vector>


using namespace std;



// LOOK FOR A BETTER SOLUTION 



// Algorithm 

// 1. Sort the vectors
// 2. Find the greatest num among two arrays
// 3. forloop till the greatest num 
// 4. binaryseach if i is present in both the vectors
// 5. if yes add to the intersection set

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> intersection_set;
        
        int greatest_num = 0;
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        greatest_num = max(*max_element(nums1.begin(), nums1.end()),*max_element(nums2.begin(), nums2.end()));
            
        
        
        cout<<binarysearch(nums1,6)<<endl;
        for(int i = 0 ; i <= greatest_num ; i++)
        {
            if(binarysearch(nums1,i) && binarysearch(nums2,i))
            {
                intersection_set.push_back(i);
            }
            
        }
        
        return intersection_set;
    }
    
    
    
    bool binarysearch(vector<int>& nums,int target)
    {
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left <= right)
        {
            int mid = (left + right ) / 2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] < target)
                left = mid+1;
            else
                right = mid-1;
        }
        return false;
    }
};