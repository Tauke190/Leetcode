#include <string>
#include <iostream>
#include <cmath>
#include <vector>



using namespace std;


// Only works if they are maximum of two duplicates next to each other in the list // 0(n^2)
int removeDuplicates(vector<int>& nums) 
{
    int size = nums.size();
    
    for(int i =.0; i < nums.size()-2; i++)
    {
        if(nums[i] != nums[i+1])
        {
            continue;
        }
        else
        {
            int last = nums[i+1];
            for(int j = i+1 ; j < nums.size()-1 ; j++)
            {
                nums[j] = nums[j+1];
            }
            nums[nums.size()-1] = last;
            size--;
        }
    }
    return size;
}

// Only works if they are any numbers of two duplicates in the list // 0(n^2)

//This can like a segment sort for the duplicates values , it will make the sets of sorted value within the array itself.
int removeDuplicates2(vector<int>& nums) 
{
    int size = nums.size();
    
    for(int i =.0; i < nums.size()-2; i++)
    {
        if(nums[i] != nums[i+1])
        {
            continue;
        }
        else
        {
            int last = nums[i+1];
            for(int j = i+1 ; j < nums.size()-1 ; j++)  //shifting
            {
                nums[j] = nums[j+1];
            }
            nums[nums.size()-1] = last;
            size--;
            i--;
        }
    }
    return size;
}


int main ()
{

}

    

