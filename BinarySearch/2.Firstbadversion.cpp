#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
/* 
Difficulty - Easy 
Type - Binary Search 
Attmept 1  - Could not Solve it 
Attempt 2 - Solved it in 5 mins

Algorithm
1. If the bad version found on the mid directly , it could be on the left side too , so check on left side
2. If the bad version not found on mid directly , it must be on the right and first bad version is answer
*/

 bool isBadVersion(int version)
{
    return true;
}


class Solution {
public:
    int firstBadVersion(int n) 
    {
        
        int left = 1;
        int right = n;
        
        int result = -1;
        
        while(left <= right)
        {
            int mid = left + (right - left ) / 2;
            
            if(isBadVersion(mid))
            {
                right = mid - 1; // Keep on looking left for the first bad version
                result = mid;
            }
            else
            {
                left = mid + 1; // If bad version on mid , it must be somewhere on right
            }
        }
        return result; 
    }
};