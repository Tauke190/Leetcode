#include <iostream>
#include <vector>


using namespace std;



// MEDIUM 






/* Method 1 - O(n) - Iterative

Algorithm

1. Sort the arrays 
2. We need to find the maximum distance between two horizontal cuts and two vertical cuts
3. Add h and w to the array (the upper bound)
4.Find the largest difference between the i and i-1 in the for loop 
5. return the maxhorizontaldistance * maxverticaldistance
 */


class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        const int mod = 1e9 + 7;
        // Find the maximum distance between two horizontal cuts and vertical cuts
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        //horizontalCuts.insert(horizontalCuts.begin(),0);
        //verticalCuts.insert(verticalCuts.begin(),0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        vector<int> hcuts; 
        int max_distance_hcut = horizontalCuts[0];
        int max_distance_vcut = verticalCuts[0];
        
        for(int i = 1; i < horizontalCuts.size() ; i++)
        {
            max_distance_hcut = max(max_distance_hcut,horizontalCuts[i]-horizontalCuts[i-1]);
        }
         for(int i = 1; i < verticalCuts.size() ; i++)
        {
            max_distance_vcut = max(max_distance_vcut,verticalCuts[i]-verticalCuts[i-1]);
        }
        
        cout<<"H :"<< max_distance_hcut <<endl;
        cout<<"V :"<< max_distance_vcut <<endl;
        
       return (int)((long)max_distance_hcut * max_distance_vcut
                     % mod);
        
    }
};