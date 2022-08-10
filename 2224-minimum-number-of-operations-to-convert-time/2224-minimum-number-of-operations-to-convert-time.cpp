/* 
Difficulty - Easy 
Type - Array / Prefix Sum
Attmept 1  - 45 Mins(Solved) - with the help of leetcode hints



Time  Complexity: 0(N)
Space Complexity: 0(1)

Algorithm
1. Greedy Algorithms , do the best move/operation that is possible
2. Convert the current and correct time into strings
3. Our goal is to reach from current in mins to correct time in mins
4. Set a while loop and keep track of difference
5. The best possible move would be use the greatest operation which is to increase by 60 if it satisfies the    constraints
6. If the difference is greater than 60 ,we can increase by 60
7. If the difference is between 60 and 15, we can use 15 and so on 
8. Increment the operation counter at the end of the while loop
9. Return the time
4.Return the array
*/


class Solution {
public:
    int convertTime(string current, string correct)
    {
        int operations = 0;
        string a = current;
        string b = correct;
        
        
    
        int starting_minutes = ((a[0]-'0')* 600)+((a[1]-'0')*60)+((a[3]-'0')*10)+ (a[4] - '0');
        int ending_minutes = (b[0]-'0')* 600 +(b[1]-'0')*60+(b[3]-'0')*10+  (b[4] -'0');
         
      
        cout<<starting_minutes<<endl;
        cout<<ending_minutes<<endl;
        
        
       
        while(starting_minutes < ending_minutes)
        {
           int diff = ending_minutes - starting_minutes;
           
           if(diff >= 60)
           {
               starting_minutes+= 60;
           }
           if(diff < 60 && diff >=15)
           {
               starting_minutes+= 15;
               
           }
           if(diff < 15 && diff >= 5)
           {
               starting_minutes+= 5;
           }
           if(diff < 5 && diff >= 1)
           {
               starting_minutes+= 1;
           }
           operations++;
        }
        return operations;
    }
   
};