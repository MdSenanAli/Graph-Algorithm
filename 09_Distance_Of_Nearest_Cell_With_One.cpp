/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number
of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.
There should be atleast one 1 in the grid.

Time Complexity: O(n*m + 4*n*m)
Reason: n*m for the initialising the queue, the queue can have a max size of n*m, and at each node we are running
        a for loop for 4 iterations.

Space Complexity: O(3n*m)
Reason: Visited vector, nearest vector, and stack space takes O(n*m) space


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> nearest(n, vector<int>(m, 0));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j, 0});
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty())
        {
            int u = q.front()[0];
            int v = q.front()[1];
            int dis = q.front()[2];
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = u + drow[i];
                int y = v + dcol[i];
                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] == 0)
                {
                    nearest[x][y] = dis + 1;
                    visited[x][y] = 1;
                    q.push({x, y, dis + 1});
                }
            }
        }
        return nearest;
    }
};