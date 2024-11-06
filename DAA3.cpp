#include<bits/stdc++.h>
using namespace std;
int func(int idx, int w, vector<int> &values, vector<int> &weights, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (weights[0] <= w)
        {
            return values[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[idx][w] != -1)
    {
        return dp[idx][w];
    }
    int notTake = func(idx - 1, w, values, weights, dp);
    int take = INT_MIN;
    if (weights[idx] <= w)
    {
        take = values[idx] + func(idx - 1, w - weights[idx], values, weights, dp);
    }
    return dp[idx][w] = max(take, notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return func(n - 1, w, values, weights, dp);
}

int main(){
    int n,w;
    cin >> n >> w;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n;i++){
        cin >> values[i];
    }
    for (int i = 0; i < n;i++){
        cin >> weights[i];
    }
    //cout << "Using Memoization: " << endl;
    cout << maxProfit(values,weights,n,w) << endl;
    // cout<< "Using Tabulation: " << endl;
    cout << tabulation(values, weights, n, w) << endl;

    return 0;
}

/*
    Input ->
    N = 5 
    W = 100
    Values = {12, 35, 41, 25, 32}
    Weights = {20, 24, 36, 40, 42}

    Ouptut -> 101
*/

/*
    Complexity Analysis ->
    Memoization -> T.C -> O(N*W)
                   S.C -> O(N*W) + O(N)
    Tabulation  -> T.C -> O(N*W)
                   S.C -> O(N*W)

*/