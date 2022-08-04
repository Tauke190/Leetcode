#include <iostream>
#include <map>
#include <set>

#include <unordered_map>


using namespace std;


class Solution {
public:
    
    
    // Dynamic window 
    // Keep on seeing if the window is valid or not so that we can do k replacements
    
    
    int characterReplacement(string s, int k) 
    {
        unordered_map<char,int> charCount;
        int window_start = 0;
        int N = s.length();
        int max_count = 0;      //The maximum frequency of the char in the window
        int max_length = 0;
        for(int window_end = 0; window_end < N; window_end++)
        {
            // Keep on incresing the count of the characters until the window                                                                                   isvalid
            charCount[s[window_end]]++;
            
            // Keep track of the max frequency of the characters also
            
            max_count = max(max_count, charCount[s[window_end]]);
            
            // if windowend - start - maxcount + 1 > allowed replacements maxcount                  window is invalid
            
            while(window_end - window_start - max_count + 1 > k)
            {
                charCount[s[window_start]]--; // pop count from the first of window
                window_start++;               // shift the window
            }
             max_length = max(max_length , window_end - window_start + 1);
            
        }
        
      
        
        return max_length;
    }
};