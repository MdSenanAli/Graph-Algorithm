/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
Given an undirected graph with V vertices and E edges, check whether it contains any
cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes
ith node is having edge with.

Time Complexity: O(V+2E) + O(V)
Reason: Using the DFS algorithm.

Space Complexity: O(V)
Reason: Recursion stack space is O(V), visited vector takes O(V) space


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool dfs(int node, int parent, vector<int> adj[], vector<int> &visited)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfs(it, node, adj, visited))
                    return true;
            }
            else if (parent != it)
                return true;
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};