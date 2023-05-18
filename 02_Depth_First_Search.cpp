/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
You are given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use a recursive approach to find the DFS traversal of the graph starting from the
0th vertex from left to right according to the graph.

Time Complexity: O(V + 2E)
Reason: The dfs will be called for V nodes, therefore O(V)
        and the for loop in dfs will run for E/2E(directed/undirected) times

Space Complexity: O(3V)
Reason: Traversal vector stores upto V elements
        visited vector is of size V
        and recursion stack stack space is O(V).


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &traversal)
    {

        // Marking the node as visited
        visited[node] = 1;

        // Adding it to the traversal
        traversal.push_back(node);

        // Traversing in the adjacency list
        for (int i = 0; i < adj[node].size(); i++)
        {

            // Storing the element
            int elem = adj[node][i];

            // If elem not visited, call the function for that node
            if (!visited[elem])
                dfs(elem, adj, visited, traversal);
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        // Declaring visited array
        vector<int> visited(V, 0);

        // Declaring vector to store the dfs traversal
        vector<int> traversal;

        // Calling the recursive dfs function
        dfs(0, adj, visited, traversal);

        // Returning the traversal
        return traversal;
    }
};