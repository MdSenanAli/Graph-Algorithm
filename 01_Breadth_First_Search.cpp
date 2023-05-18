/*
GFG Problem Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal
of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should
only take nodes directly or indirectly connected from Node 0 in consideration.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here

        // Vector for storing the traversal
        vector<int> traversal;

        // Creating a visited array
        vector<bool> visited(V, false);

        // Creating a Queue
        queue<int> q;

        // As traversal always starts from 0 as given in question, and marking 0 as visited
        q.push(0);
        visited[0] = true;

        // While the queue is not empty
        while (!q.empty())
        {

            // Storing the top element
            int top = q.front();

            // Adding that element in the traversal
            traversal.push_back(top);

            // Since we have visited we remove that element from queue
            q.pop();

            // Traversal of the adjacency list:
            for (int i = 0; i < adj[top].size(); i++)
            {

                // Getting the element in the list
                int elem = adj[top][i];

                // If not visited, we push it in the queue
                if (visited[elem] == false)
                {
                    q.push(elem);

                    // Mark it as visited
                    visited[elem] = true;
                }
            }
        }
        // Return the traversal
        return traversal;
    }
};
// } Driver Code Ends