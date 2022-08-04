#include <string>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


/* Difficulty - Easy 
Type - Depth First Search
Attmept 1  - Had the understanding of the concept but looked at solution, couldnt do recursion properly



Algorithm
1. Make a recusrive function 
2. Check if the current color is the desired number or not  ,starting position
3. if it is the desired color , set it to the newcolor 
4. then check for if the rows is greater than 1 or not , if it is you can do a recursive call at r-1;
5. then check for if the colums is greater than 1 or not , if it is you can do a recursive call at c-1;
5. then check for if the rows + 1 is less than nums image.size() not , if it is you can do a recursive call at r+1;
7.then check for if the rows + 1 is less than nums image.size() not , if it is you can do a recursive call at c+1;
8. check for if the curr_color equals to the desired color so that it does not get stuck in the loop  */


class Solution {
public:
    
    

    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int color) 
    {
        int curr_color = image[sr][sc];
        
        
        if(curr_color != color) // if equals infinite loop
        {
             dfs(image,sr,sc,curr_color,color);
        }
      
        return image;
    }
    
    void dfs(vector<vector<int> >& image, int sr, int sc, int currentcolor, int newcolor) 
    {
        if(image[sr][sc] == currentcolor)
        {
            image[sr][sc] = newcolor;
            if(sr >= 1) //. can go left
                dfs(image,sr-1,sc,currentcolor,newcolor);
            if(sc >= 1) //. can go up
                dfs(image,sr,sc-1,currentcolor,newcolor);
            if(sr+1 < image.size()) //. can go right
                dfs(image,sr+1,sc,currentcolor,newcolor);
            if(sc+1 < image[0].size()) //. can go left
                dfs(image,sr,sc+1,currentcolor,newcolor);
        }
    }
};