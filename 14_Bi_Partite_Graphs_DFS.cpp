/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/bipartite-graph/1
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index.
Check whether the graph is bipartite or not.

Time Complexity: O(V+2E)
Reason: Same as DFS Algorithm

Space Complexity: O(V)
Reason: Same as DFS Algorithm

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int node, vector<int> &color, vector<int> adj[])
    {
        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                color[it] = !color[node];
                if (!dfs(it, color, adj))
                    return false;
            }
            else if (color[it] == color[node])
                return false;
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
                color[i] = 0;
                if (!dfs(i, color, adj))
                    return false;
            }
        }
        return true;
    }
};