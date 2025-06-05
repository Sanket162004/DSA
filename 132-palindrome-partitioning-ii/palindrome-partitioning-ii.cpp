class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> palindrome(n, vector<bool>(n, false));
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(s[i]==s[j] && (j-i<2 || palindrome[i+1][j-1])){
                    palindrome[i][j] = true;
                }
            }
        }
        vector<int> dp(n+1, 0);
        for(int ind =n-1; ind>=0; ind--){
            int cnt = INT_MAX;  
            for(int i=ind; i<s.size(); i++){
                if(palindrome[ind][i]) cnt=min(cnt, 1+dp[i+1]);
            }
            dp[ind]=cnt;
        }
        return dp[0]-1;
    }
};