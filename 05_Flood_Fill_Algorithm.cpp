/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.
Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel
value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the
starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those
pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the
aforementioned pixels with the newColor.

Time Complexity: O(n*m + n*m*4)
Reason: the main function is checking for n*m times and for each n*m we check 4 neighbours.

Space Complexity: O(2*n*m + n*m)
Reason: Queue can store n*m elements, visited matrix and compy of image has size of O(n*m)


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        // Code here
        int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> floodFilled = image;

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};
        floodFilled[sr][sc] = newColor;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty())
        {
            int u = q.front().first;
            int v = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int x = u + drow[i];
                int y = v + dcol[i];

                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && floodFilled[x][y] == color)
                {
                    q.push({x, y});
                    floodFilled[x][y] = newColor;
                    visited[x][y] = 1;
                }
            }
        }
        return floodFilled;
    }
};