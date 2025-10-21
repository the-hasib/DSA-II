class Solution {
public:
    int helper(int i,int sum,int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(i==coins.size()){
            if(sum==amount)return 0;
            else return INT_MAX;
        };
        if(dp[i][sum]!=-1)return dp[i][sum];
        if((long long)sum+coins[i]>(long long)amount)return dp[i][sum]=helper(i+1,sum,amount,coins,dp);//leave
        long long leave=helper(i+1,sum,amount,coins,dp);
        long long take=helper(i,sum+coins[i],amount,coins,dp);
        return dp[i][sum]=min((long long)1+take,leave);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= helper(0,0,amount,coins,dp);
        if(ans==INT_MAX)return -1;
        else return ans;
    }
};