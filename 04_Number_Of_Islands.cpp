/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid)
consisting of '0's (Water) and '1's(Land). Find the number of islands.
Note: An island is either surrounded by water or boundary of grid and is formed by connecting
 adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Time Complexity: O(n*m + n*m*9)
Reason: the main function is checking for n*m times and for each n*m we check 9 neighbours, (includes itself as well)

Space Complexity: O(2*n*m)
Reason: Queue can store n*m elements, visited matrix has size of O(n*m)


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited, int n, int m)
    {
        // Declaring the queue
        queue<pair<int, int>> q;

        // Adding the element in queue
        q.push({i, j});

        // Marking it as visited
        visited[i][j] = 1;

        // While the queue is not empty
        while (!q.empty())
        {

            // Storing the node as {u,v}
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            // Traversing in 8 directions
            for (int r = -1; r < 2; r++)
            {
                for (int s = -1; s < 2; s++)
                {

                    // Neighbour coordinates
                    int x = u + r;
                    int y = v + s;

                    // Checking validity of neighbours
                    if ((x >= 0) && (x < n) && (y >= 0) && (y < m))
                    {

                        if ((grid[x][y] == '1') && !visited[x][y])
                        {
                            q.push({x, y});
                            visited[x][y] = 1;
                        }
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        // Storing the dimensions of the grid
        int n = grid.size();
        int m = grid[0].size();

        // Declaring the count of islands
        int island = 0;

        // Declaring the visited array
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Looping through all the grid elements
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == '1' && !visited[i][j])
                {
                    island++;
                    bfs(i, j, grid, visited, n, m);
                }
            }
        }
        return island;
    }
};