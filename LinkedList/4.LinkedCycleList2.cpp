#include <string>
#include <iostream>
#include <cmath>
#include<unordered_set>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



// 1. Use ordered set to store the unique nodes
// 2. Make the un_ordered set of type of ListNode*
// 3. We can easily find tail after this
// 4. Return whatever is tail is pointing towards

class Solution {
public:
     ListNode *detectCycle(ListNode *head) 
    {
        
        ListNode* curr = head;
        ListNode* tail = NULL;
        
        unordered_set<ListNode*> set;
        
        if(!head || !head->next)
            return NULL;
        while(curr && set.find(curr) == set.end())
        {
            set.insert(curr);
            if(curr->next)
                curr = curr->next;
            else
                curr = NULL;
        }
        return curr;
     }
};