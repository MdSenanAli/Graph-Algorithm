/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
Given an undirected graph with V vertices and E edges, check whether it contains any
cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes
ith node is having edge with.

Time Complexity: O(V+2E) + O(V)
Reason: Using the BFS algorithm.

Space Complexity: O(3V)
Reason: Queue and visited can store V elements. Also Queue stores a pair.


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool bfs(int node, vector<int> adj[], vector<int> &visited)
    {

        visited[node] = 1;

        queue<pair<int, int>> q;
        q.push({node, -1});

        while (!q.empty())
        {
            int vertex = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[vertex])
            {
                if (!visited[it])
                {
                    visited[it] = 1;
                    q.push({it, vertex});
                }
                else if (it != parent)
                {
                    return true;
                }
            }
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
                if (bfs(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};