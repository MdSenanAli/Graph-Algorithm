/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges
We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j]
can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit
time.

Time Complexity: O(n*m + n*m*4)
Reason: the main function is checking for n*m times and for each n*m we check 4 neighbours.

Space Complexity: O(2*n*m + n*m)
Reason: Queue can store n*m elements, visited matrix and copy of grid has size of O(n*m)


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> rotten = grid;

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        int time = 0;
        int countFresh = 0;

        queue<vector<int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j, 0});
                }
                else if (grid[i][j] == 1)
                {
                    countFresh++;
                }
            }
        }

        while (!q.empty())
        {

            int u = q.front()[0];
            int v = q.front()[1];
            int t = q.front()[2];
            q.pop();

            for (int i = 0; i < 4; i++)
            {

                int x = u + drow[i];
                int y = v + dcol[i];

                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && rotten[x][y] == 1)
                {

                    rotten[x][y] = 2;
                    visited[x][y] = 1;
                    q.push({x, y, t + 1});

                    time = max(t + 1, time);
                    countFresh--;
                }
            }
        }
        return (countFresh == 0) ? time : -1;
    }
};