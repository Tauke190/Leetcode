/* 
Difficulty - Medium
Type - Array / Two pointers
Attmept 1  - Could Not Solve it
Attempt 2  - Solved it watching a youtube video



Time  Complexity: 0(N)
Space Complexity: 0(1)

Algorithm
1. As you scan through the array
2. You need to maintain the current minimum number till that index
3. You need to matintain the current maximum number till that index
4. When you calculate max element store it in temp before you calculate the minimum number
5. The finalmax is the max between the currMax and the finalmax
6. Return the max 
*/


class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int N = nums.size();
        
        int currMax = nums[0];
        int currMin = nums[0];
        int finalMax = nums[0];
       
        for(int i = 1 ; i < N ; i++)
        {
            
            int temp = max({nums[i],nums[i]*currMax,nums[i]*currMin});
            
            currMin = min({nums[i],currMax*nums[i],nums[i]*currMin});
            
            currMax = temp;
            
            finalMax = max(finalMax,currMax);
            
           
            cout<<currMax<<endl;
            cout<<currMin<<endl;
            cout<<endl;
           
            
            
        }
        
        return finalMax;
    }
};