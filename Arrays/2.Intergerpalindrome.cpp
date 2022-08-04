#include <string>
#include <iostream>
#include <cmath>


using namespace std;

//Check if the given integer is palindrome or not 


// (12121) Is a plaindrome 


//Approach 1 
//Change to string and use two pointers from front and back and check


//Approach 2
//Revert the int itself without changing it to the string using some modulus and math

bool isPalindrome(int x) 
    {
        int rev = 0;
        int lastdigit;
        int num = x;
        
        while  (num != 0)
        {
            lastdigit = num % 10;
            rev = (rev*10)+lastdigit;
            cout << rev<<endl;
            num = floor(num/10);
        }
      
        if(rev == x)
        {
            return true;
        }
        return false;
    }

int main() 
{
    cout<<isPalindrome(-121)<<endl;
  
}