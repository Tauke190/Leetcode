#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* 
Difficulty - Hard 
Type - Array
Attmept 1  - Done without help in 5 mins

Algorithm
1. 
*/

// Method 1 : Brute Forcing // Time limit exceeded
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        
        
        for(int i= 0 ; i < nums.size();  i++)
        {
            int count = 0;
            for(int j = i ; j < nums.size(); j++)
            {
                if(nums[j] < nums[i])
                {
                    count++;
                }
            }
            cout<<count;
            nums[i] = count;
        }
        return nums;
    }
};


// Method 2 - Still TLA


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int,int>, null_type, 
        less<pair<int,int>>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set_pair;


class Solution
{
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> results;
        ordered_set_pair s;
        int N = nums.size() - 1;
        
        for(int i = N ; i >= 0 ; i--)
        {
           int index = s.order_of_key({nums[i],-1});
           results.insert(results.begin(),index);
           s.insert({nums[i],i});
        }
        return results;
    }
    
};