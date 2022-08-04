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
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        
        ListNode* head = list1;
        
        
        if(list2->val < list1->val)
        {
            head = list2;
            list2 = list2->next;
        }
        else
        {
            list1 = list1->next;
        }
        
        
        ListNode* curr = head;
       
        
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
           
        }
        while(list1)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        while(list2)
        {
            curr->next = list2;
            list2 = list2->next; 
        }
        return head;
        
    }
};