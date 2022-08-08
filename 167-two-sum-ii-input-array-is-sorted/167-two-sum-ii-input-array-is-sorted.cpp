class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        
        int N = numbers.size();
        int left = 0;
        int right  = N-1;
        vector<int> results;
        
        while(numbers[left] + numbers[right] != target)
        {
            if(numbers[left] + numbers[right] > target)
            {
                right--;
            }
            if(numbers[left] + numbers[right] < target)
            {
                left++;
            }
        }
        
        results.push_back(left+1);
        results.push_back(right+1);
        
        return results;
        
    }
};