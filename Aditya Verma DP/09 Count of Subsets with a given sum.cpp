class Solution{	
    public:
	int perfectSum(int arr[], int n, int sum)
	{
        int dp[n+1][sum+1];
        long long m = 1e9 + 7;  // for very long input
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j< sum + 1; j++){
                if(i == 0) dp[i][j] = 0;
                
                if(j == 0) dp[i][j] = 1;
            }
        }
        
        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < sum + 1; j++){     // speacial test case handled here by taking j = 0; 
                if(arr[i-1] <= j)
                    dp[i][j] = (dp[i-1][j - arr[i-1]] % m + dp[i-1][j] % m ) % m;   // added modulo for very long inputs
                else
                    dp[i][j] = dp[i-1][j] % m;
                
            }
        }
        return dp[n][sum];
	}
	  
};