/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands
where a group of connected 1s (horizontally or vertically) forms an island. Two islands are
considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Time Complexity: O(n*m*log(n*m) + n*m*4)
Reason: n*m*4 for DFS algoriithm in the worst case, n and m iterations for the for loop.

Space Complexity: O(n*m)
Reason: Visited vector and stack space takes O(n*m) space


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec,
             int *drow, int *dcol, int rBase, int cBase)
    {

        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        vec.push_back({row - rBase, col - cBase});

        for (int i = 0; i < 4; i++)
        {
            int x = row + drow[i];
            int y = col + dcol[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y])
            {
                dfs(x, y, vis, grid, vec, drow, dcol, rBase, cBase);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        set<vector<pair<int, int>>> st;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (!vis[i][j] && grid[i][j])
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, drow, dcol, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};