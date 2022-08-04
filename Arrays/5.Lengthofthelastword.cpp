#include <string>
#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

//"         Hello world       "

//Find the length of the last word 

//Remove all the backspaces 

//Count the lettes from front and set it to 0 when encounted space 

//Again add if you encounter a alphabet

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int word = 0;
        
        
        int lastindex = s.size()-1;
        
        while (s[lastindex] == ' ') 
        {
            lastindex--;
        }
       
        for(int i = 0 ; i < lastindex+1; i++)
        {
            if(s[i] == ' ')
            {
                word = 0;
            }
            else
            {
                word++;
            }
        }
        return word;
        
    }
};