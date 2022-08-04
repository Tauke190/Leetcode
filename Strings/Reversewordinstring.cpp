#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* 
Difficulty - Easy 
Type - Two Pointer 
Attmept 1  - Done without help in 5 mins

Algorithm
1. Make two pointer to keep track of starting of the word and the ending of the word
2. Depending on the whitespace set the start and end of the words accordingly
3. Swap the letters of the word
*/


class Solution {
public:
    string reverseWords(string &s) 
    {
        int start = 0;
        int end = 0;
        
        for(int i = 0 ; i <= s.length() ; i++)
        {
            if(s[i]== ' ' || i == s.length ())
            {
                end = i-1;
                while(start < end)
                {
                    swap(s[start++],s[end--]);
                }
                start = i+1;
            }
        }
        return s;
    }
    
};
