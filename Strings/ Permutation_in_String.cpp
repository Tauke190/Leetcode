#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* 
Difficulty - Medium 
Type - Sliding Window , two pointer
Attmept 1  - Done with help (2 : 30 hours)

Algorithm (If two strings are each other permutation or anagram , then they have same frequency count, hence same hash table)
1. Maintain the window of size of the string whose permutation we are checking
2. Put the elemets of that string inside the hashtable
3. Compare both the hash table and return answer
*/