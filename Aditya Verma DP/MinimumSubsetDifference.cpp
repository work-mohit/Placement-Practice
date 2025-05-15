#include<bits/stdc++.h>

using namespace std;

int minimumSubsetDifferenceMemoized(vector<int>& wt, int totalSum, int n, int currSum){
    if(n == 0)
        return abs((totalSum - currSum) - currSum);

    
    int include = minimumSubsetDifferenceMemoized(wt, totalSum, n-1, currSum + wt[n-1]);
    int exclude = minimumSubsetDifferenceMemoized(wt, totalSum, n-1, currSum);

    return min(include, exclude);
}

int minimumSubsetDifferenceMemoized(vector<int>& wt, int totalSum, int n, int currSum, vector<vector<int>>& dp){
    if(n == 0)
        return abs((totalSum - currSum) - currSum);

    if(dp[n][currSum] != -1)
        return dp[n][currSum];

    int include = minimumSubsetDifferenceMemoized(wt, totalSum, n-1, currSum + wt[n-1],dp);
    int exclude = minimumSubsetDifferenceMemoized(wt, totalSum, n-1, currSum,dp);

    return dp[n][currSum] = min(include, exclude);
}


int countNumberOfSubsetsOptimized(vector<int>& wt, int sum, int n) {
    vector<int> store(sum + 1, 0);
    store[0] = 1;  // Base case: Subset sum of 0 is always possible

    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= wt[i-1]; j--) { 
            store[j] = store[j] + store[j - wt[i - 1]];
        }
    }
   
    return store[sum];
}


int getMinimumSumDiff(vector<int>& arr){
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);

    // for memoized version
    vector<vector<int>> dp(n+1, vector<int> (totalSum+1, -1));

    // return minimumSubsetDifferenceMemoized(arr, totalSum, n, 0);
    return minimumSubsetDifferenceMemoized(arr, totalSum, n, 0, dp);

}


int main(){
    vector<int> wt = { 1,2,3,4,5,6};

    vector<pair<vector<int>, int>> testCases = {
        {{1, 6, 11, 5}, 1},
        {{1, 2, 3, 9}, 3},
        {{3, 1, 4, 2, 2}, 0},
        {{10, 20, 15, 5, 25}, 5},
        {{1, 1, 1, 1}, 0},
        {{1, 5, 6, 11, 8}, 1},
        {{1, 2}, 1},
        {{}, 0},
        {{100}, 100},
        {{50, 50, 50, 50, 50}, 50}, 
        {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 1},
        {{1000, 2000, 3000, 4000, 5000}, 1000},
        {{10, 20, 30, 40, 50, 60, 70, 80}, 0},
        {{1, 3, 7, 9, 11, 13}, 0},
        {{2, 4, 6, 8, 10, 12}, 2},
    };

    int passCnt = 0;
    for(int i = 0; i < testCases.size(); i++){
        int res = getMinimumSumDiff(testCases[i].first);
        
        if(res == testCases[i].second){
            passCnt++;
            cout<<"TEST CASE "<<i+1<<" : PASSED"<<endl;
        }           
        else  
            cout<<"TEST CASE "<<i+1<<" : FAILED"<<endl;

        
    }

    cout<<endl<<endl;
    if(passCnt == testCases.size())
        cout<<"HURRRRAYYYY"<<endl;
    cout<<passCnt<<" out of "<<testCases.size()<<" test cases got passed."<<endl;
  

    return 0;
}