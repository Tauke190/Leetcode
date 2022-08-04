#include <string>
#include <iostream>
#include <cmath>
#include <unordered_map>


using namespace std;
class Solution {
public:
    string getHint(string secret, string guess)
    {
        int N = secret.length();
        string result;
        
        unordered_map<char,int> umap;
        
        
        int x = 0;  //No of matched digits
        int y = 0;  //No of unmatched digits
        
        
        for(int i = 0 ; i < N ; i++)
        {
            if(secret[i] == guess[i])
            {
                x++;
            }
            else
            {
               umap[secret[i]]++;
            }
        }
        
         for(int i = 0 ; i < N ; i++)
        {
             if(secret[i] != guess[i] && umap.find(guess[i])!=umap.end() && umap[guess[i]] >0)
             {
                 umap[guess[i]]--; // After adding decrease its frequency because no more is left in the unmatched hashmap of the string
                 y++;
             }
        }
        result = to_string(x)+"A"+to_string(y)+"B";
        
        return result;
        
    }
};