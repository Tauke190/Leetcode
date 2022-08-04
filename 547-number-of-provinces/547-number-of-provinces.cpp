class Solution {
public:
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