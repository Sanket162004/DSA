class Solution {
public:
    void func(vector<string>&ans,int open,int close,int n,string curr){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        if(open<n) func(ans,open+1,close,n,curr+'(');
        if(close<open) func(ans,open,close+1,n,curr+')');
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        func(ans,0,0,n,"");
        return ans;
    }
};