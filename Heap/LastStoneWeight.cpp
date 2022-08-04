#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
/* 
Difficulty - Easy 
Attempt - Had to look for hints ( But understood properly)
Type - Heap 

Algorithm
1. Sort the elemets , compare the last 2 elements 
2. If equal , remove both from stack 
3. If not , put the abs(last - secondlast) in the last position of vector , use while loop
4. you have to sort the element inside the while loop
5.  Return the first element in the vector
*/

class Solution {
public:
    
   
    
    int lastStoneWeight(vector<int>& stones) 
    {
        
        //Base Condition
        int N = stones.size();
        
        while(N > 1)
        {
            sort(stones.begin(),stones.end());
            if(stones[N-1] == stones[N-2])
            {
                stones.pop_back();
                stones.pop_back();
                N-=2;
                
            }
            else
            {
                stones[N-2] = abs(stones[N-1] - stones[N-2]);
                stones.pop_back();
                N--;
            }
            
        }
        
        if (N == 0)
            return 0;
        
        return stones[0];
    }


    //Approach 2 - Using priority queue
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(),stones.end());
        
        while(pq.size()!=1){
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            pq.push(top1-top2);
        }
        return pq.top();
    }
};


