/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/number-of-enclaves/1
You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or
walking off the boundary of the grid.
Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Time Complexity: O(n*m*4 + n + m)
Reason: n*m*4 for DFS algoriithm in the worst case, n and m iterations for the for loop.

Space Complexity: O(n*m)
Reason: Visited vector and stack space takes O(n*m) space


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(int row, int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &visited,
             vector<int> &drow, vector<int> &dcol)
    {

        visited[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int x = row + drow[i];
            int y = col + dcol[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y])
            {
                dfs(x, y, n, m, grid, visited, drow, dcol);
            }
        }
    }

public:
    int numberOfEnclaves(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] && !visited[i][0])
            {
                dfs(i, 0, n, m, grid, visited, drow, dcol);
            }
            if (grid[i][m - 1] && !visited[i][m - 1])
            {
                dfs(i, m - 1, n, m, grid, visited, drow, dcol);
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] && !visited[0][j])
            {
                dfs(0, j, n, m, grid, visited, drow, dcol);
            }
            if (grid[n - 1][j] && !visited[n - 1][j])
            {
                dfs(n - 1, j, n, m, grid, visited, drow, dcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] && !visited[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};