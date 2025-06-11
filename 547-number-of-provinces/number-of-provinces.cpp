class Solution {
public:
    void dfs(int node,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
        visited[node]=1;

        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);

        //  pehle aapan graph ko traverse mar dete hai 

        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj);
                cnt++;
            }
        }
        return  cnt;
    }
};