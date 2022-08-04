
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
/* 
Difficulty - Medium 
Type - Sliding Window / Two pointers
Attmept 1  - Done without help  (1:30 hrs) 

Time Complexity : 0(N) kinda
Space Complexity : 0(1)

Algorithm
1. Make a window_start pointer and window_end pointer 
2. Loop through the window end pointer and just add the elements into the hastable ( Extending the window_end)
3. If we encounter a already exisiting elements inside the hastable
4. First store the longest length it has been till now 
5. Then move the window_start forward 
6. In some condition , you need to move the window_start until it meets where the window_end was
7. The max size of hashmap should be answer , return it
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> hmap;
        
        int longest_length = 0;
        
        
        int start = 0;
        int end = 0;
       
        
        
        for(int end = 0; end < s.size() ; end++)
        {
            if(hmap.find(s[end]) != hmap.end()) // Could find on the hashtable
            {
                longest_length = std::max(longest_length,(int)hmap.size());
                
                while(s[start] != s[end])
                {
                    hmap.erase(s[start]);
                    start++;
                }
                start++;
               
            }
          
            hmap.insert(make_pair(s[end],1));
        
        }
        
        return max(longest_length,(int)hmap.size());
        
    }
};