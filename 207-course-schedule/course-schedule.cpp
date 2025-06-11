class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(V);
        for(int i=0;i<prerequisites.size();i++)
        
        {
            
                adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
        }
    vector<int>visited(V,0);
    vector<int>indegree(V,0);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indegree[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int i=0;i<adj[temp].size();i++)
            {
                indegree[adj[temp][i]]--;
                if(indegree[adj[temp][i]]==0)
                {
                    q.push(adj[temp][i]);
                }
            }
        }
        if(ans.size()==V)
        {
            return true;
        }
        return false;
    }
};