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
          
            hmap.insert({s[end],1});
        
        }
        
        return max(longest_length,(int)hmap.size());
        
    }
};