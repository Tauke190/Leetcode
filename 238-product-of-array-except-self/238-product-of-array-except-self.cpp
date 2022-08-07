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