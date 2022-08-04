#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/* Difficulty - Medium 
Type - Depth First Search / Breadth First Search / Backtracking
Attmept 1  - Had no fucking idea.


 Algorithm
Time complexity : O(2^N)


1.Convert the solution into a binary tree 
2.Then design a recusive function thinking for only one thing

 */
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        vector<int> results;
        
        
        // n = digit of the number
        // i = root of the tree
        // k = difference between two consective number
        // results = vector of results
        for(int i = 1 ; i < 10 ; i++)
        {
            dfs(n-1,i,k,results);
        }
        return results;
    }
    
    void dfs(int N , int num , int K , vector<int> &results) // N is number of digits in the                                                      number
    {
        if(N == 0)
        {
            results.push_back(num);
            return;
        }
        vector<int> listofdigits;
        
        int taildigit = num % 10;
        listofdigits.push_back(taildigit + K);
        if(K != 0)
        {
             listofdigits.push_back(taildigit - K);
        }
       
        for(int i = 0 ; i < 10 ; i++)
        {
            if(listofdigits[i] >= 0 && listofdigits[i] < 10)
            {
                int newnum = (num*10) + listofdigits[i];
                dfs(N-1,newnum,K,results);
            }
        }
    }
};