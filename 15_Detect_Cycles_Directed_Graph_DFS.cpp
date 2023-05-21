/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges,
check whether it contains any cycle or not.

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
    bool dfs(int i, vector<int> &visited, vector<int> &pathVis, vector<int> adj[])
    {
        visited[i] = 1;
        pathVis[i] = 1;
        for (auto it : adj[i])
        {
            if (!visited[it])
            {
                visited[it] = 1;
                if (dfs(it, visited, pathVis, adj))
                    return true;
            }
            else if (pathVis[it])
            {
                return true;
            }
        }

        pathVis[i] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> visited(V, 0);
        vector<int> pathVis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, visited, pathVis, adj))
                    return true;
            }
        }
        return false;
    }
};