#include <string>
#include <iostream>
#include <cmath>
using namespace std;


// Set the head of the list  // the head of the list and the pointer that transverse should be different

// Set the current pointer to the trasverse through the list 

// Compare the values from each list and put it in the final list 

// Put the remaining value in the final list

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

// Method 1 : Iterative Method
class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
      
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL; 
        
        while(curr)
        {
            next = curr->next; // store the next 
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

// Method 1 : Recursive Method

  ListNode* reverseList(ListNode* head) 
    {
        if(!head || !head->next)
            return head;


        ListNode* h = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;
        return h;
  
    }
