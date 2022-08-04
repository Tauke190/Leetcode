#include <iostream>
#include <map>
#include <set>

using namespace std;


// Two pointer method bitch


class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        int str1 = 0;
        int str2 = 0; 
        
        string result = "";
        while(str1 < s.length() && str2 < t.length())
        {
            if(s[str1] == t[str2]) // if the char matches
            {
                result += s[str1];
                str1++;
                str2++;
            }
            else
            {
                str2++;
            }
        }
        return result == s;
    }
};