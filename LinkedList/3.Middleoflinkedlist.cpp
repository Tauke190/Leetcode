#include <string>
#include <iostream>
#include <cmath>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 1. Make two pointers

// 2. Make one pointer jump once and the other twice 

// 3. Do some error checking

class Solution 
{
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* curr1 = head;
        ListNode* curr2 = head;
        
        while(curr2->next)
        {
            curr1 = curr1->next;
            if(curr2->next->next != NULL)
                curr2 = curr2->next->next;
            else
                curr2 = curr2->next;
        }
        return curr1;
        
    }
};
