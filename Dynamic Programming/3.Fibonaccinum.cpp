#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;



/* 
Algorithm 
1 .Make a list and intialize with 0 , 1
2 .In the for loop keep push elements to the vector 
3 .And modify that same elemets with the sum of previous two elements
 */


class Solution {
public:
    int fib(int n) 
    {
        vector<int> list {0,1};
        
        for(int i = 2 ; i <= n ; i++)
        {
            list.push_back(i);
            list[i] = list[i-1] + list[i-2];
        }
        return list[n];
        
    }
};