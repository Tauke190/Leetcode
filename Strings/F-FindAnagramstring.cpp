#include <iostream>
#include <vector>
#include <unordered_map>

//Count Not Do
using namespace std;
//Approach 1 

//Compare sorted versions of the pattern and all the possible substring
class Solution 
{
public:
    vector<int> findAnagrams(string &s, string &p) 
    {
        vector<int> resultindices;
        int plength = p.length();
        int slength = s.length();
        
        
        //compare the substring with the sorted version of the pat 
        string sortedpattern = p;
        
        sort(sortedpattern.begin(),sortedpattern.end());
        
       
        string substring;
        for(int i = 0 ; i <= slength-plength ; i++)
        {
            substring = "";
            for(int j = i ; j < plength+i ; j++)
            {
                 substring += s[j];
            }   
            sort(substring.begin(),substring.end());
            if(substring == sortedpattern)
            {
                resultindices.push_back(i);
            }
            
        }
        return resultindices;
       
    }
};


// Approach 2


// Algorithm 


/*   Store the frequency of the pattern in array or hashmap 

  Store the frequency of the window of length of pattern in array or hashmap 

  Compare and slide it  */
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> resultindices;
      
        
        int plength = p.length();
        int slength = s.length();
        
        
        unordered_map<char,int> patterncount;
        unordered_map<char,int> windowcount;
        
        for(int i = 0; i < plength; i++)
        {
            patterncount[p[i]]++;
            windowcount[s[i]]++;
        }
        
        for(int i = plength ; i < slength; i++)
        {
            if(patterncount == windowcount)
            {
                resultindices.push_back(i - plength);
            }
            windowcount[s[i]]++;
            windowcount[s[i - plength]]--;
        }

        //compare the last window
        if(patterncount == windowcount)
        {
            resultindices.push_back(slength - plength);
        }
        
      return resultindices;
    }
