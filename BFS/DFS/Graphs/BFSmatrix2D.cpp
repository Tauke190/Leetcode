#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<pair<int,pair<int,int> > >getneighbours(pair<int,pair<int,int> >  getter, vector<vector<int> > &matrix) // Get its neighbours in the format of (element, (i,j))
{
    vector<pair<int,pair<int,int> > > neighbours;

    int i = getter.second.first;
    int j = getter.second.second;

    if(i < matrix.size() && j < matrix[0].size()) // if the row and column is in the bound
    {
        if(matrix[i][j+1] != 0)
        {
            neighbours.push_back(make_pair(matrix[i][j+1],make_pair(i,j+1)));   // Add its adjancent neighbours and its index
        }
        if(matrix[i+1][j] != 0)
        {
             neighbours.push_back(make_pair(matrix[i+1][j],make_pair(i+1,j)));
        }
        matrix[i][j+1] = 0;
        matrix[i+1][j] = 0;
       
    }
    return neighbours;
}

void bfs(vector<vector<int> > &matrix)
{
    queue<pair<int,pair<int,int> > > queue; // Pair of its element and its index(i,j)

    queue.push(make_pair(matrix[0][0],make_pair(0,0))); // Push the first element and its index into the queue

    while(!queue.empty())     // Keep on doing it if the queue is not empty
    {
        vector<pair<int,pair<int,int> > > neighbours = getneighbours(queue.front(),matrix);

        for (int i = 0; i < neighbours.size(); i++)
        {
            queue.push(neighbours[i]);
        }

        cout<<queue.front().first;
        queue.pop(); 
        
    }

}





int main()
{
    // Given input matrix
    int grid[4][4] = { { 1, 2, 3, 4 },
                           { 5, 6, 7, 8 },
                           { 9, 10, 11, 12 },
                           { 13, 14, 15, 16 } };
    
    vector<vector<int> > vect;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            vect[i][j] = grid[i][j];
        }
    }
    
    bfs(vect);
}