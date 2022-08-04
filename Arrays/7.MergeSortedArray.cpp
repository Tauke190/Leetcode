#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//Sort

//[1,2,3,0,0,0] && [2,4,6] Inplace 

//n=3
//m=3


//Two pointers from the last and another variable to keep track of putting the updated value in the first array itself

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        
        int k = m+n-1;
        int i = m - 1;
        int j = n - 1;
        
        while(j >= 0)
        {
            
            if( i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
               
            }
            else
            {
                 nums1[k--] = nums2[j--];
            }
        }
    }
};