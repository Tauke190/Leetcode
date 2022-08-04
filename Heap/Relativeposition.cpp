#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

/* 
Difficulty - Easy 
Attempt -  Done without help (Took a bit time)
Type - Heap 

Algorithm
1. Sort the higest_score and align it with the map of medals in ascending order
2. Search the originalscore and push its corresponding value to the resultant vector
*/


/* class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    { 
        
        vector<int> sorted_score{score.begin(),score.end()};
        sort(sorted_score.begin(),sorted_score.end(),greater<int>());
       
        
        map <int,string> player;
        vector<string> results;
        
        for(int i = 0; i < score.size(); i++)
        {
            if(i == 0)
            {
                player.insert({sorted_score[i],"Gold Medal"});
            }
            if(i == 1)
            {
                player.insert({sorted_score[i],"Silver Medal"});
            }
            if(i == 2)
            {
                player.insert({sorted_score[i],"Bronze Medal"});
            }
            else
            {
                 player.insert({sorted_score[i],to_string(i+1)});
            }
            
           
            
        }
        
        for(int i = 0; i < score.size(); i++)
        {
            results.push_back(player[score[i]]);
        }

        return results;
    
    }
}; */