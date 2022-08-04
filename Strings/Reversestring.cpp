#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* 
Difficulty - Easy 
Type - Two Pointer 
Attmept 1  - Done without help in 5 mins

Algorithm
1. Make two pointer left and rightside of array 
2. Swap it and shift it accordingly
3. If not, put the element of the array in the hashtable
*/
class Solution {
public:
    void Swap(char& a , char &b)
    {
        char temp = a;
        a = b;
        b = temp;
    }
    void reverseString(vector<char>& s) 
    {
        int i = 0;
        int j = s.size()-1;
        
        while(i < j)
        {
            Swap(s[i++],s[j--]);
        }
    }
};