#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }

int dp[1000][1000];
int knapSack(int W, int wt[], int val[], int n)
{

    if (n == 0 || W == 0)
        return 0;
    cout << "Remaining Weight : " << W << " ";
    cout << "Current Item : " << n << " and its weight " << wt[n - 1] << endl;

    if (dp[W][n] != -1)
        return dp[W][n - 1];
    if (wt[n - 1] > W)
        return dp[W][n] = knapSack(W, wt, val, n - 1);
    return dp[W][n] = max(
               val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
               knapSack(W, wt, val, n - 1));
}
int main()
{
    // int profit[] = {60, 100, 120};
    // int weight[] = {10, 20, 30};
    // int W = 50;
    // int n = sizeof(profit) / sizeof(profit[0]);

    memset(dp, -1, sizeof(dp));
    int n;
    cout << "Number of items : ";
    cin >> n;
    int W;
    cout << "Enter the maximum weight : ";
    cin >> W;
    int profit[n];
    int weight[n];
    cout << "Enter Weight Array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    cout << "Enter Profit Array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }
    cout << knapSack(W, weight, profit, n) << endl;
    return 0;
}

// This code is contributed by rathbhupendra
