/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index.
Check whether the graph is bipartite or not.

Time Complexity: O(V+2E)
Reason: Same as BFS Algorithm

Space Complexity: O(V)
Reason: Same as BFS Algorithm

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool bfs(int node, vector<int> &color, vector<int> adj[])
    {
        queue<int> q;

        color[node] = 0;
        q.push(node);

        while (!q.empty())
        {

            int nd = q.front();
            q.pop();

            for (auto it : adj[nd])
            {
                if (color[it] == -1)
                {
                    color[it] = !color[nd];
                    q.push(it);
                }
                else if (color[it] == color[nd])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!bfs(i, color, adj))
                    return false;
            }
        }
        return true;
    }
};