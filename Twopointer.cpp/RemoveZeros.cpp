
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/* 
Difficulty - Easy 
Type - Two pointers 
Attmept 1  - Solved it , 30 mins , Alot of bruteforcing conditions

Algorithm
1. Check the square from both left and right side, push front the max into the vector
2. Then push the pointer left and right accordingly
3. return the result
*/


//Method 1 - Traverse from the right to left and push zero to back and erase that elemet
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        
        
        for(int i = nums.size()-1 ; i >= 0 ; i--)
        {
            if(nums[i] == 0)
            {
                nums.push_back(nums[i]);
                nums.erase(nums.begin()+i);
            }
        }
        
    }
};



// Method 2 - Bring front all the non-zero and simply add 0 the back
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0;
        int j = 0;
        
        while( i < nums.size())
        {
            if(nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
            i++;
        }
        
       for(;j < nums.size() ; j++)
       {
           nums[j] = 0;
       }
           
        
    }
};