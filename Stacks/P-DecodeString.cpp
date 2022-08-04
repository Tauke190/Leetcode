#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
/* 
Difficulty - Medium 
Type - Stack 
Status - Almost Solved , Forget to push to stack and to cover a corner case where there is double digit coefficient

Algorithm
1.We make two stacks to store coefficient and the alphabet
2.We push to respective stack and when found "]"(closing bracket), we make a string traversing downward until we 
  find the closing "]"(Closing bracket) and repeat it N time where N is the top of coeffiecntstack
3.We push that in the letterstack
4.Sum up all the elements in the stack at last and return it
*/


class Solution {
public:
    string decodeString(string s) 
    {
        int N = s.length();
        
        
        stack<int> cofficientstack;
        stack<string> letterstack;
        
        
        string result = "";
        
        
        for(int i = 0 ; i < N ; i++)
        {
            if(isalpha(s[i]) || s[i] =='[')
            {
                std::stringstream ss;
                std::string letter;
                ss<<s[i];
                ss>>letter;
                letterstack.push(letter);
            }
            else if(isdigit(s[i]))
            {
                // if there is string continously in stack , we have to do something
                int count = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    count = count * 10 + s[i] - '0';
                    i++;
                }

                i--;
                cofficientstack.push(count);
            }
            else if(s[i] == ']')
            {
                string stack_letters = "";
                
                while(letterstack.top() != "[")
                {
                    stack_letters.insert(0,letterstack.top());
                    letterstack.pop();
                }
             
                letterstack.pop();
                cout<<stack_letters<<endl;
                cout<<cofficientstack.top()<<endl;
               
              
                result = "";
                for(int i = 0 ; i < cofficientstack.top()  ; i++)
                {
                    result += stack_letters;
                }
                cofficientstack.pop();
                letterstack.push(result);
            }
        }
        result = "";
        
        while(!letterstack.empty())
        {
            result.insert(0,letterstack.top());
            letterstack.pop();
        }
        return result;
        
    }
};