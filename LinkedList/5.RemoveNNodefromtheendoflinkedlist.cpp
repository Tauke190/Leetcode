
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* 
Difficulty - Medium 
Type - LinkedList
Attmept 1  - Done with a little bit of help ( Took 2 hours)

Time Complexity : (0(2n))
Space Complexity : 0(N)



Algorithm
1. Make two pointers
2. Point first to head and the second to after N nodes in the linked list
3. Traverse until the second nodes stop and move both first and second by one step
4. when the second stops, the position of the first node is N step from the back of the linked list
5. Check for corner cases like when the length of the linked list is equal to the steps of the linked list
6. For this you have to remove the head of linked list
7. Return the head;
*/



  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        
        ListNode* current1 = head; // This is slow one step pointer
        
        ListNode* current2 = head; // This is the fast N steps pointer
        
        
        
        for(int i = 0 ; i < n ; i++)
        {
             if(current2->next == NULL)
             {
                 // if count is N delete the head node
                 if(i == n-1)
                 {
                    ListNode* temp = head;
                    head = head->next;
                    delete temp;
                    return head;
                 }
             }
             current2 = current2->next; // N = 2 Steps
              
        }
        
        
        while(current2->next)  // Until it reaches the last node
        {
            current1 = current1->next;
            current2 = current2->next;
        }
        
        cout<<current1->val;
        cout<<current2->val;
        
        
        if(current1->next == NULL)
        {
             current1 = NULL; // Remove the node
        }
        else
        {
            current1->next = current1->next->next;
        }
        
        return head;
        
    }
};