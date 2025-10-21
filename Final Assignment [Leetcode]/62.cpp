class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // space optimization
        // tc = O(n*m) sc = O(n)

        vector<int> dp(n, 0);
        vector<int> curr(n, 0);
        
        for(int i = 0; i < m; i++){

            for(int j = 0; j < n; j++){

                int up = 0, left = 0;

                if(i == 0 && j == 0){ //base case
                    curr[j] = 1;
                    continue;
                }
                if(i > 0) up = dp[j];
                if(j > 0) left = curr[j-1] ;
                
                curr[j] = up + left;
            }
            dp = curr;
        }
        return dp[n-1];
    }
};