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