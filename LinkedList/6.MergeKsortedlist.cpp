

#include <iostream>
#include <queue>

using namespace std;


/* Difficulty - Hard 
Type - LinkedList
Attmept 1  - Done with syntax help ( 3 hours)

Time Complexity : (0(KNLogn)))
Space Complexity : 0(N)


Algorithms(Heap)

1.Make a heap that can store the element value and index
2.Put all the head values of the list in the heap along with its index
3.Get the min value from the heap and index stored in that node will tell which list to traverse
4.Traverse that list and put the next value in the heap
5.Start another node and keep on buidling the linked list from the min or top values of the heap
6.Again the current_index of the min value will which list to traverse until its null
7.Return the head
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
   
   
    typedef pair<int,int> pq;
   
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
       
        ListNode* head = NULL;
       
        if(lists.size() == 0)
            return NULL;
       
        priority_queue <pq, vector<pq>, greater<pq> > heap; // Store the index and elements
       
       
        int current_index = 0;
        ListNode* current_node  = new ListNode(0);
       
        for(int i = 0 ; i < lists.size() ; i++)
        {
            if(lists[i] != NULL)
            {
                ListNode* headeach = lists[i];
                heap.push(make_pair(headeach->val,i));  
            }
        }
       
        if(!heap.empty())
        {
            current_node->val = heap.top().first;
            current_index = heap.top().second;
            head = current_node;
        }
       
        while(lists[current_index] != NULL)  // Traverse the list containing the minimum element
        {
         
            lists[current_index] = lists[current_index]->next;
           
            heap.pop();
            if(lists[current_index] != NULL)
                heap.push(make_pair(lists[current_index]->val,current_index));
           
           
            ListNode* newnode = new ListNode(heap.top().first);
            cout<<newnode->val;
           
           
            ListNode* temp = head;
           
             while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
       
            current_index = heap.top().second;  
        }
       
        if (head == NULL)
            return NULL;

        if (head->next == NULL) {
            delete head;
            return NULL;
        }
       
       ListNode* second_last = head;
       
       while (second_last->next->next != NULL)
        second_last = second_last->next;
       
       delete(second_last->next);
       
        second_last->next = NULL;
       
        return head;
    }
   
   
};
