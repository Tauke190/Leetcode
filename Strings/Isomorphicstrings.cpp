#include <iostream>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        map<char,char> umap;
        set<char> set;
        int uniquechar = 0;
        
        int t_index = 0;
        if (s.length() != t.length())
		    return false;
      
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(umap.find(i) == umap.end()) // if the key is not present in the map
            {
                //if not mapped to the set which are unique , if the second char are not unique in the set
                if(set.find(t[t_index]) != set.end())
                {
                    return false;
                }
              
                umap[i]= t[t_index];
                set.insert(t[t_index]);
            }
            else                           // if the key is present in the map
            {
                if(t[t_index] != umap.find(i)->second) // if mapped to the same value of the first occurence, return true
                {                                 
                    return false;
                }
            }
            t_index++;
        }
        return true;
    }
};

/* About sets 

1.Stores unique values
2.Stores in ascending order
4.Immutable elements
3.declaration syntax of the set to store the elements in decreasing sorted order.
        set<int,greater<int>> s; 
        
Methods on set
There is a wide range of operations that can be performed on sets in C++. Let us look at some of the vital methods of sets.

1.begin():  This method returns an iterator that points to the first element in the set.
2.end(): This function returns an iterator that points to the theoretical position next to the last element of the set.
3.empty(): This set method is used for checking whether the set is empty or not.
4.size(): This function gives the number of elements present in a set .
5.max_size(): This method returns upper bound of elements in a set, i.e. the maximum number that a set can hold.
6.rbegin(): In contrary to the begin() method, this method returns a reverse iterator pointing to the last element of a set.
7.rend(): In contrary to the begin() method, this method returns a reverse iterator pointing to the logical position before the last element of a set.
8.erase (iterator_position): This method when applied  on a set, removes the element at the position pointed by the pointer given in the parameter.
9.erase (const_n): This function directly deletes the value ‘n’ passed in the parameter from a set .
10.insert (const_n): This function inserts a new element ‘n’ into the set .
11.find( n ): This method searches for the element ‘n’ in the set and returns an iterator pointing to the position of the found element. If the element is not found, it returns an iterator pointing at the end.
12.count( const_n ): This set method checks for the occurrence of the passed value ‘n’ and returns 0 or 1 if the element is found or not found respectively.
13.clear(): It removes all the elements present in a set.  
        
        
        
*/