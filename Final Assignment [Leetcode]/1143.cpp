class Solution {
public:
    int lcs(int i,int j,string &text1, string &text2,vector<vector<int>>&dp){
        if(i==-1||j==-1){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j])return dp[i][j]=1+lcs(i-1,j-1,text1,text2,dp);
        else{
            return dp[i][j]=max(lcs(i-1,j,text1,text2,dp),lcs(i,j-1,text1,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int s1=text1.length()-1;
        int s2=text2.length()-1;
        //i goes from s1 to 0
        //j goes from s2 to 0
        vector<vector<int>>dp(s1+1,vector<int>(s2+1,-1));
        return lcs(s1,s2,text1,text2,dp);
    }
};