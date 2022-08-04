#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;
/* 
Difficulty - Easy 
Type - Two pointers 
Attmept 1  - Could not Solve it , Almost did it

Algorithm
1. Check the square from both left and right side, push front the max into the vector
2. Then push the pointer left and right accordingly
3. return the result
*/

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int i =.0;
        int j = nums.size() - 1;
        
        vector<int> results;
        cout<<pow(-2,2);
    
        while(i <= j)
        {
            if(pow(nums[i],2) < pow(nums[j],2))
            {
                results.insert(results.begin(),pow(nums[j],2));
                j--;
            }
            else
            {
                results.insert(results.begin(),pow(nums[i],2));
                i++;
            }
            
        }
        return results;
    }
};