#include <string>
#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

//Given 

//[6,2,3,4,6,6,6] , Remove Elem 6 InPlace 


//To make : [2,3,4,6,6,6,6]

//Loop Through array and ignore the element to be removed 

//keep the track of the index with another variable like k 

class Solution
 {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int j = nums.size();
        int k = 0;
        
        int notuniquelement = 0 ;
        
        for(int i = 0 ; i < nums.size(); i++ )
        {
            if(nums[i] == val)
            {
               continue;
            }
            else
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
        
    }
};



