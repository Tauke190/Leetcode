#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/* Algorithm
1. Intialize a lootedcash vector with size()+ 2 elements because we need to access the index at [i-1] && [i-3]
2. Find the recurrence relation of the problem 
3. lootedcash[i] = max(lootedcash[i-1], nums[i] + lootedcash[i-2]);
 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        
        int size = cost.size();
        int *totalcost = new int[size + 1];
        
        totalcost[0] = 0;
        totalcost[1] = 0;   // The total cost to go floor 1 or floor 2 is zero
        
        for(int i = 2 ; i < size+1; i++)
        {
            totalcost[i] = min(totalcost[i-1] + cost[i-1] , totalcost[i-2] + cost[i-2]);
        }
        return totalcost[size];
    }
};