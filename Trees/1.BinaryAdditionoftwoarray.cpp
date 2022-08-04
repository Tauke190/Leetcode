#include <string>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        
       int lastindex = digits.size()-1;
        
        while(lastindex > -1)
        {
            if(lastindex == 0)
            {
                if(digits[0] == 9)
                {
                    digits.push_back(0);
                    digits[0] = 0;
                }
               
            }
            if(digits[lastindex] == 9)
            {
                digits[lastindex] = 0;
                
            }
            else
            {
                digits[lastindex] = digits[lastindex]+1;
                break;
            }
            lastindex--;
            
        }
        return digits;
        
        
    }
};