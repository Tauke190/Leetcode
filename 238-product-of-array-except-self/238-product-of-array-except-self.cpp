/* 
Difficulty - Easy 
Type - Array / Prefix Sum
Attmept 1  - Could Only Solve it with DFS but TLA
Attempt 2  - Could solve it with prefix/postfix



Algorithm
1. Make prefix array and postfix array
2. prefix is like the partial sum that is the sum of all the elements till that index
3. prefix is like the partial sum that is the sum of all elements after that index
4. Instead of adding use mulplication in the prefix sum
5. In the next loop , define logic for the first and last element in the array
6. For all the rest , prefix[i-1] gives the product of the left side
7. For all the rest , postfix[i+1] gives the product on the right side
8. Multiply these and put them in the results array
4. Return the results array
*/


class Solution 
{
    int LEFT = -1;
    int RIGHT = 1;
    
    
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int N = nums.size();
        
        int* prefix = new int[N];
        int* postfix = new int[N];
        vector<int> result(N,0);
        
        prefix[0] = nums[0];
        postfix[N-1] = nums[N-1];
        
        
        for(int i = 1 ; i < N ; i++)                //Prefix algorithm
        {
            prefix[i] = nums[i] * prefix[i-1];
        }
        
        for(int i = N - 2 ; i >= 0 ; i--)          //Postfix algorithm
        {
            postfix[i] = nums[i] * postfix[i+1];
        }
        
        for(int i = 0 ; i < N ; i++)
        {
            if(i == 0 )
            {
                result[i] = postfix[i+1];
                continue;
            }
            if(i == N-1)
            {
                result[i] = prefix[N-2];
                continue;
            }
            result[i] = prefix[i-1] * postfix[i+1];
        }
        
        return result;
        
    }
    
    
};