class Solution {
public:
    /* Difficulty - Medium 
    Type - Graph Union Find
    Attmept 1  -  Almost done it 80%. Algorithm was right but could not implement it



    Algorithm
    1.Iterate through the matrix
    2.Make a parent array which will hold the representative or the parent of the element
    3.Populate with itself because all the nodes will be their own parent
    4.Find two such cities which are connected but not connected with itself
    5.The ith and jth index will be our node of the graph
    6.Union find them , if their parent are different then parent(x) = y and they will be share a common parent or be in a same subset
    7.Find function is a recursive function which finds the main parent of the element
    8.If find gives the element itself , that is the base condition , else it searches for parent of parent
    */
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        int *parent = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    unionlol(parent, i, j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                count++;
            }
        }

        return count;
    }
    int find(int* parent, int i)
    {
        if (parent[i] == i) {
            return i;
        } else {
            return find(parent, parent[i]);
        }
    }

    void unionlol(int* parent, int i, int j) {
        int p1 = find(parent, i);
        int p2 = find(parent, j);
        if (p1 != p2) {
            parent[p1] = p2;
        } 
    }

};
