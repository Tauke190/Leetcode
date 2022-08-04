#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/* Algorithm

 1.Intialize a 2D array upaths[][] in which the solutio is stored for every type of matrix grid;
 2.Fill the  horizontal and vertical line with 1 because there will be only 1 unique path
 3.Find the recurrence relation upaths[i][j] = upaths[i-1][j] + upaths[i][j-1]; 
 */


class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        
        
        vector<vector<long> > upaths( m+1 , vector<long> (n+1, 0)); // intializing a 2D vecto
        
        upaths[0][0] = 1;
        
        for(int i = 1 ; i < m+1 ; i++)
        {
            upaths[i][0] = 1;
            
        }
        
         for(int i = 1 ; i < n+1 ; i++)
        {
            upaths[0][i] = 1;
        }
        
        for(int i = 1 ; i < m+1 ; i++)
        {
            for(int j = 1 ; j < n+1 ; j++)
            {
                upaths[i][j] = upaths[i-1][j] + upaths[i][j-1];
            }
        }
        
        return upaths[m-1][n-1];
    }
};