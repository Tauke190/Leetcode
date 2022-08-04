#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* 
Difficulty - Easy 
Type - Two Pointer 
Attmept 1 - Was trying to convert it to a area problem with no solution , Spent like 3 hours
Attempt 2 - Looked at the complete bruteforce solution 0(n^2) but still getting a TLA 
Attempt 3 - 

Algorithm 1 (BruteForce)
1. Make two pointer to keep track of starting of the word and the ending of the word
2. Depending on the whitespace set the start and end of the words accordingly
3. Swap the letters of the word

Algorithm 2 (Double pointer and binary search)
1. Set two pointers from the left and from the right
2. The least among them moves accordingly because we need that minium value in which water can be stored between blocks
3. If the current element is greater than lmax or rmax then set it to it , no water can be stored in that
4. If the current element is smaller than lmax or rmax then water will stored in that  will lmax or rmax - that current element
5. Then move accordingly
*/


class Solution {
public:
    int trap(vector<int>& height) 
    {
      
        int totalwater = 0;
        
        
        for(int i = 0 ; i < height.size() ; i++)
        {
            int leftmax =  0;
            int rightmax = 0;
            // To find left max because it changes as we move left
            for(int j = i ; j >= 0 ; j--)
            {
                leftmax = max(leftmax,height[j]);
            }
            
            // To find right max because it changes as we move right
            for(int j = i ; j < height.size() ; j++)
            {
                rightmax = max(rightmax, height[j]);
                
            }            
            int water = min(leftmax,rightmax) - height[i];
            cout<< i << " >> "<<"LM "<<leftmax<<" : "<<"RM "<<rightmax<< " = " << water<<endl;
          
            if(water > 0)
            {  
                totalwater+=water;
                 //cout<<water;
              
            }
            
        }
        
        return totalwater;
    }
   
};

// Method 2 : Double pointer method

class Solution {
public:
    int trap(vector<int>& height) 
    {
        
        int l = 0;
        int r = height.size() - 1 ;
        int lmax = 0;
        int rmax = 0;
        
        int result = 0;
        
        while(l <= r)
        {
            if(height[l] <= height[r])
            {
                if(height[r] >= lmax) 
                {
                    lmax = height[l];
                }
                else
                {
                    result += lmax - height[l]; 
                }
                l++;
            }
            else
            {
                if(height[r] >= rmax)
                {
                    rmax = height[r];
                }
                else
                {
                    result += rmax - height[r];
                }
                r--;
            }
       
        }
         return result;
    }
        
      
   
};