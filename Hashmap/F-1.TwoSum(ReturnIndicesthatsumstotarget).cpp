
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* 
Difficulty - Easy 
Type - Hash Map 
Attmept 1  - Could Not do it 
Attempt 2  - Could Not do it , I thought checking if a  element in hash table exisit of not would be 0(N)

Algorithm
1. Check if the hashtable contains the compliment of a fixed number in the array
2. If yes  return the index of that compliment and i
3. If not, put the element of the array in the hashtable
*/

//Approach 1 - Iterate both the array to find the matching pairs that sums to target value

// Apprach 2 - Double Pass Hash Table 


// Approach 3 - Single Pass Hash Table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> hash_map;
        vector<int> result;
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            int compliment = target - nums[i];   
            // To check if the hashtable contains compliment or not
            if(hash_map.find(compliment) != hash_map.end()) 
            {
                result.push_back(i);
                result.push_back(hash_map[target-nums[i]]);
                break;
            }
            hash_map.insert(nums[i],i);
        }
        return result;
        
    }
};
