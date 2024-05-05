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


int main(){
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    
    cout << knapsack(W, wt, val, n);
    return 0;
}