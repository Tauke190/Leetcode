
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/* 
Difficulty - Medium 
Type - Hash Map 
Attmept 1  - Done without help right on time (45 mins) 

Time Complexity : (0(nLogn))
Space Complexity : 0(1)



Algorithm
1. Make a array of compliments we will add along the process of [2,7,11,15]
2. Loop the array and check if the first compliment is in the compliments array or not 
3. Since , we cannot use hashmap , we use binary seach to see if the compliments is in the array or not
4. If yes , then we get its index and the current element in the loop index and return
5. If compliment is not in the array , we add the current number in the loop to the array
*/


class Solution {
public:
    
    int complimentindex(int numbers[],int target,int size)
    {
        int left = 0;
        int right = size - 1;
        
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(numbers[mid] == target)
            {
                return mid;
            }
            else if (numbers[mid] < target) // Search right side
            {
                left = mid + 1;
            }
            else                            //Search left side
            {
                right = mid - 1;
            }
            
        }
        return -1;
        
    }
    
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        
        int listofcompliments[numbers.size()]; // To store the compliments of the numbers // Like a hashmap but in ascending order so we can binary search later
        int j = 0;
        
        for(int i = 0 ; i < numbers.size(); i++)
        {
            int compliment = target - numbers[i];
            int indexofcompliment = complimentindex(listofcompliments,compliment,j);
            
            if(indexofcompliment != -1) // To check if there is compliment or not
            {
                return {indexofcompliment+1,i+1};
                break;
            }
            listofcompliments[j++] = numbers[i];
        }
        return {};
    }
};