/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/number-of-provinces/1
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there
 is a path from u to v or v to u. Your task is to find the number of provinces.
Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Time Complexity: O(V + 2E)
Reason: Same as BFS

Space Complexity: O(3V)
Reason: Same as BFS


*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void bfs(int start, int V, vector<vector<int>> adj, vector<int> &visited)
    {
        // Creating a Queue
        queue<int> q;

        // As traversal always starts from 0 as given in question, and marking 0 as visited
        q.push(start);
        visited[start] = 1;

        // While the queue is not empty
        while (!q.empty())
        {

            // Storing the top element
            int top = q.front();

            // Since we have visited we remove that element from queue
            q.pop();

            // Traversal of the adjacency matrix:
            for (int node = 0; node < V; node++)
            {
                // Getting the element in the matrix
                if (adj[top][node])
                {

                    if (!visited[node])
                    {
                        // If not visited, we push it in the queue
                        q.push(node);

                        // Mark it as visited
                        visited[node] = 1;
                    }
                }
            }
        }
    }

public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // code here
        // Number of provinces
        int provinces = 0;

        // Creating a visited array
        vector<int> visited(V, 0);

        // Iterating through the provinces
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                // Incrementing a new province
                provinces++;

                // Filling the visited array through bfs traversal
                bfs(i, V, adj, visited);
            }
        }

        // Returning the number of provinces
        return provinces;
    }
};