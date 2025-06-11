class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {

        vector<int>v;
        queue<int>q;

        vector<vector<int>>adj(num);
        vector<int>ind(num);
        for(auto a:pre){
            adj[a[1]].push_back(a[0]);
            ind[a[0]]++;
        }

        for(int i=0;i<num;i++){
            if(ind[i]==0) q.push(i);
        }

        while(!q.empty()){
            int t=q.front(); q.pop();
            v.push_back(t);
            for(auto a:adj[t]){
                ind[a]--;
                if(ind[a]==0){
                    q.push(a);
                }
            }
        }
        if(v.size()==num) return v;

        return {};
    }
};