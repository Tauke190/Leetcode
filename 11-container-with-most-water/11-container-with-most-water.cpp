/* 
Difficulty - Medium 
Type - Array / Two pointers
Attmept 1  - 30 Mins bitch ( Solved AF)



Time  Complexity: 0(N)
Space Complexity: 0(1)

Algorithm
1. The idea is search for the container with highest possible vertical lines with farthest distance
2. To do that , we find area of all  possible the largest container
3. To do that , we use two pointer approach
4. Start with the most left and most right pointer
5. Calcualte the area
6. To go to next largest container , we see which is smaller among pointers
7. And we shift the smaller pointers and calculate area again
8. the max area of all the containers we have calculated is the answer
9. Return the max area
*/

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
            //min(height[left] , height[right]) * distance gives area of the current container
            maxarea = max(maxarea,min(height[left] , height[right]) * distance);
            
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