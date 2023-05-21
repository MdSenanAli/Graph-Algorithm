/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1
Given a matrix mat of size N x M where every element is either O or X.
Replace all O with X that are surrounded by X.
A O (or a set of O) is considered to be surrounded by X if there are X
at locations just below, just above, just left and just right of it.

Time Complexity: O(n*m*4 + n + m)
Reason: n*m*4 for DFS algoriithm in the worst case, n and m iterations for the for loop.

Space Complexity: O(n*m)
Reason: Visited vector, nearest vector, and stack space takes O(n*m) space


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int row, int col, int n, int m, vector<vector<char>> &mat, vector<vector<int>> &visited,
             vector<int> &drow, vector<int> &dcol)
    {

        visited[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int x = row + drow[i];
            int y = col + dcol[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && mat[x][y] == 'O')
            {
                dfs(x, y, n, m, mat, visited, drow, dcol);
            }
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 'O' && !visited[i][0])
            {
                dfs(i, 0, n, m, mat, visited, drow, dcol);
            }
            if (mat[i][m - 1] == 'O' && !visited[i][m - 1])
            {
                dfs(i, m - 1, n, m, mat, visited, drow, dcol);
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (mat[0][j] == 'O' && !visited[0][j])
            {
                dfs(0, j, n, m, mat, visited, drow, dcol);
            }
            if (mat[n - 1][j] == 'O' && !visited[n - 1][j])
            {
                dfs(n - 1, j, n, m, mat, visited, drow, dcol);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && !visited[i][j])
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};