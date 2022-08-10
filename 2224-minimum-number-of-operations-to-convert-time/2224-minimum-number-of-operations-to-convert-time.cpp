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