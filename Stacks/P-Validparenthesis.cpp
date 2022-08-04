#include <iostream>
#include <stack>
using namespace std;
/* 
Difficulty - Easy 
Type - Stack 

Algorithm
1.Check the current element and the top of the element, if they are pair remove from the stack
2.return stack.empty();
*/




class Solution {
public:
    bool isValid(string s) 
    {
        
        int N = s.length();
        
        stack<char> myStack;
        
        for(int i = 0 ; i < N ; i++)
        {
            if(myStack.empty())
            {
                 myStack.push(s[i]);  
            }
            else if((s[i] =='}' && myStack.top()=='{') || (s[i] ==')'&&                                  myStack.top()=='(') || (s[i] ==']'&& myStack.top()=='[')) // if the                    current is equals to the top of the stack , only then pop
            {
                 myStack.pop();
            }
            else
            {
                myStack.push(s[i]);  
            }
        }
        
      
        return myStack.empty();
        
    }
};