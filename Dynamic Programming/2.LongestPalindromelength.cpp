#include<vector>
#include<iostream>
#include<map>
#include <iterator>>

using namespace std;    
    
    // Method 1 : Dynamic programming 

    //1. Store the count of the letters in the map , you can just increment the values of the map

    //2. If the count is even , it is pairs and add to result 

    //3. If the count is odd and greater than 1 , it has pairs in it , so add that pair inside it and add to result 

    //4. If result < length of the string , add +1 which is the unique character : if not it means that it does not need a unique character to be a palindrome and all the lettercount is even 
    
    int longestPalindrome(string s) 
    {
        int result = 0;
        int length = s.size();
        
      map<char,int> lettercount;
        
        for(int i = 0 ; i < s.size();i++)
        {
            lettercount[s[i]]++;
        }

       for( map<char,int>::iterator it = lettercount.begin() ; it != lettercount.end(); it++)
       {
           if(it->second % 2 == 1)  // if is odd then
           {
              if(it->second > 1)
              {
                  result += (it->second - 1);
              }
           }
           else
           {
                result+= it->second;
           }   
       }
      result == s.size() ? result : result++;
      return result;
    }