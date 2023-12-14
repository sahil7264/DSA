#include <bits/stdc++.h>
using namespace std;

const int MAX = 10;

// Function to find the minimum cost using Branch and Bound
int tsp(vector<vector<int>>& graph, vector<int>& bestPath) {
    int V = graph.size();
    int minCost = INT_MAX;//store min COST Ham Cycle

    // Priority queue to store nodes of search tree
    priority_queue<pair<int, pair<int, vector<int>>>> pq; // cost , vertex , path

    // Create a root node and calculate its cost
    vector<int> path(V, -1);
    pq.push({0, {0, path}});//{0,{0,{-1,-1,-1,..}};

    // Loop to traverse the search space tree
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int cost = top.first;
        int vertex = top.second.first;
        vector<int> currentPath = top.second.second;
        
        //we visited this vertex
        if (currentPath[vertex] == -1) {
            currentPath[vertex] = 1;


            //BASE CASE
            // If all cities are visited
            bool allVisited = true;
            for (int i = 0; i < V; ++i) {
                if (currentPath[i] == -1) {
                    allVisited = false;
                    break;
                }
            }

            if (allVisited) {
                //Check if last to first is connected  or not and minCost we get is  greater than curr cost
                if (graph[vertex][0] != 0 && cost + graph[vertex][0] < minCost) {
                    minCost = cost + graph[vertex][0];
                    bestPath = currentPath;
                    bestPath[0] = 0; // Start from city 0 always
                }
            } else {
                for (int i = 0; i < V; ++i) {

                    
                    if (currentPath[i] == -1 && graph[vertex][i] != 0) {
                        vector<int> newPath = currentPath;
                        pq.push({cost + graph[vertex][i], {i, newPath}});
                    }
                }
            }
        }
    }

    return minCost;
}

int main() {
    // Example graph representation (replace this with your own)
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<int> bestPath;

    // Find the minimum cost using Branch and Bound
    int minCost = tsp(graph, bestPath);

    if (minCost == INT_MAX) {
        cout << "No feasible solution exists." << endl;
    } else {
        cout << "The minimum cost for the TSP is: " << minCost << endl;
        cout << "The best tour is: ";
        for (int i = 0; i < bestPath.size(); ++i) {
            cout << i << " ";
        }
        cout << "0" << endl; // Back to the starting point
    }

    return 0;
}
