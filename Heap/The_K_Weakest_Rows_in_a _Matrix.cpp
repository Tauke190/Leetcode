#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

/* 
Difficulty - Easy 
Attempt - Done without any help
Type - Heap 

Algorithm
1. Make a priority queue of row_sum and row_no;
2. Insertion will automatically sort the row_sum;
3. push its row_no in the result and return it
*/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int> >& mat, int k) 
    {
        //Make a pair of  number of solidiers in that row and row no;
        typedef pair<int, int> pi;
        priority_queue<pi, vector<pi>, greater<pi> > soldiers_in_row;
        vector<int> result;
        int count = 0;
        
       for(int i = 0 ; i < mat.size(); i++)
       {
           int row_sum = 0;
           for(int j = 0 ; j < mat[i].size(); j++)
           {
               row_sum+=mat[i][j];
           }
           soldiers_in_row.push(make_pair(row_sum,i));
       }
        
        cout<<soldiers_in_row.top().first;
        cout<<soldiers_in_row.top().second;
        
        
        while(count < k)
        {
            result.push_back(soldiers_in_row.top().second);
            soldiers_in_row.pop();
            count++;
        }
        return result;
    }
};