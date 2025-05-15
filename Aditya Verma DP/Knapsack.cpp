#include<bits/stdc++.h>

using namespace std;

int knapsack(int W, int wt[], int val[], int n){
    vector<vector<int>> dp(n+1, vector<int> (W+1,0));

    for(int i = 1; i<=n; i++){
        for(int j = 1; j <= W;j++){
            if(wt[i-1] <= j){
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
int knapsackSpaceOptimized(int W ,int wt[], int val[], int n){
    vector<int> curr(W+1,0), prev(W+1,0);

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= W; j++){
            if(wt[i-1]  <= j)
                curr[j] = max(val[i] + prev[j - wt[i]], prev[j]);
            else
                curr[j] = prev[j];
        }
        prev = curr;
    }
    return curr[W];

}

int knapsackEfficientSpaceOptimized(int W ,int wt[], int val[], int n){
    vector<int> prev(W+1,0);

    for(int i = 1; i <= n; i++){
        for(int j = W; j >= 0; j--){
            if(wt[i-1]  <= j)
                prev[j] = max(val[i] + prev[j - wt[i]], prev[j]);
            else
                prev[j] = prev[j];
        }
    }
    return prev[W];

}

int main(){
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    
    // cout << knapsack(W, wt, val, n);
    // cout << knapsackSpaceOptimized(W, wt, val, n);
    cout << knapsackEfficientSpaceOptimized(W, wt, val, n);


    return 0;
}