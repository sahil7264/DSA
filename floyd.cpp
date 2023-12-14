#include <bits/stdc++.h>
using namespace std;

#define INF 99999

void printSolution(vector<vector<int>> &dist, int V);

void floydWarshall(vector<vector<int>> &dist, int V)
{

    int i, j, k;
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist, V);
}

void printSolution(vector<vector<int>> &dist, int V)
{
    cout << "The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF"
                     << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    cout << "Enter the no. of vertices of the graph" << endl;
    int V;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));

    // input

    // 0 4 INF 5 INF
    // INF 0 1 INF 6
    // 2 INF 0 3 INF
    // INF INF 1 0 2
    // 1 INF INF 4 0

    // output

    // 0 4 5 5 7
    // 3 0 1 4 6
    // 2 6 0 3 5
    // 3 7 1 0 2
    // 1 5 5 4 0

    cout << "Enter the adjacency matrix representing the graph" << endl;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, V);
    return 0;
}