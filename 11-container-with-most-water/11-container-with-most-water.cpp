class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int N = height.size();
        
        int left = 0;
        int right = N-1;
        int distance = N-1;
        int maxarea = 0;
        
        while(left < right)
        {
           
           
            int area = min(height[left] , height[right]) * distance;
            maxarea = max(maxarea,area);
            
            if(height[left] <= height[right])
            {
                left++;
                distance--;
            }
            else if(height[left] > height[right])
            {
                right--;
                distance--;
            }
            
        }
        return maxarea;
    }
};