#include<bits/stdc++.h>

using namespace std;

bool isSusbsetSumRecursive(vector<int>& wt, int sum, int n){
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    
    if(wt[n-1] <= sum){
        return isSusbsetSumRecursive(wt, sum - wt[n-1], n-1) || isSusbsetSumRecursive(wt, sum, n-1);
    } 
    else    
        return isSusbsetSumRecursive(wt, sum , n-1);
}

bool isSusbsetSumMemoized(vector<int>& wt, int sum, int n, vector<vector<int>>& dp){
    if(sum == 0)
        return dp[n][sum]=1;
    if(n == 0)
        return dp[n][sum]=0;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    if(wt[n-1] <= sum){
        return dp[n][sum]=isSusbsetSumMemoized(wt, sum - wt[n-1], n-1,dp) || isSusbsetSumMemoized(wt, sum, n-1,dp);
    } 
    else    
        return dp[n][sum]=isSusbsetSumMemoized(wt, sum , n-1,dp);
}

// bool isSusbsetSumOptimized(vector<int>& wt, int sum, int n){
//     vector<int> store(sum+1, 0);
//     store[0] = 1;

//     for(int i = 1; i <= n;i++){
//         for(int j = sum; j >= 0; j--){
//             if(wt[i-1] <= j){
//                 store[j] = store[j] || store[j - wt[i]];
//             }
//             else    
//                 store[j] = store[j];
//         }
//     }

//     return store[sum];
// }

bool isSubsetSumOptimized(vector<int>& wt, int sum, int n) {
    vector<int> store(sum + 1, 0);
    store[0] = 1;  // Base case: Subset sum of 0 is always possible

    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= wt[i - 1]; j--) {  // Start from wt[i-1]
            store[j] = store[j] || store[j - wt[i - 1]];
        }
    }

    return store[sum];
}





int main(){
    vector<int> wt = { 2, 3, 7, 8, 10};
   
    int sum = 11;
    int n = wt.size();

    // for Memoization
    vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));


    // if(isSusbsetSumRecursive(wt,sum, n))
    // if(isSusbsetSumMemoized(wt,sum, n,dp))
    if(isSubsetSumOptimized(wt,sum, n))
        cout<<"true";
    else 
        cout<<"false";


    return 0;
}