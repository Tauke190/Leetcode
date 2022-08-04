#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;


/* 
Difficulty - Medium
Attempt - Almost  (Could not radix sort based on two keys) 
Type - Heap 

Algorithm
1.Make a map and set of pair(int,string)
2.Count the frequency after one traversal which will sort the alphabets also
3.Put the pair(frequency,string) in the set or priority_queue , it will sort the frequency
4.Put k values in the result and return it
*/



/* class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        
          
        map<string,int> frequency_table;         // Map is sorted
        set<pair<int,string>> frequency_pair;   // Set is sorted
        vector<string> results;
        
        for(int i = 0 ; i < words.size(); i++)
        {
            frequency_table[words[i]]++; // Alphabets gets sorted here
        }
        for(auto x:frequency_table) 
        {
            frequency_pair.insert(make_pair(-x.second,x.first)); // Frequency gets sorted here
        }
        //Since set stores in ascending order , we put minus in front of x.second
         for(auto x:frequency_pair)
        {
           results.push_back(x.second);
           if(results.size() == k) break;
        }
        
        return results;
    }
}; */