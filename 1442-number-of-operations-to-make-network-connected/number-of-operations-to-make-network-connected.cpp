class disjoint{
   
    public:
    vector<int>size;
    vector<int>parent;
    disjoint(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findu(int u)
    {
        if(u==parent[u])
        {
            return u;
        }
        parent[u]=findu(parent[u]);
        return parent[u];
    }
    void unions(int u,int v,int &extra)
    {
        int upar=findu(u);
        int vpar=findu(v);
        if(upar==vpar)
        {
            extra++;
            return ;
        }
        else if(size[upar]<size[vpar])
        {
            parent[upar]=vpar;
            size[vpar]+=size[upar];
        }
        else
        {
            parent[vpar]=upar;
            size[upar]+=size[vpar];
        }
    }
};
class Solution {
public:
    int makeConnected(int v, vector<vector<int>>& connections) {
        disjoint ds(v);
        int extra=0;
        for(int i=0;i<connections.size();i++)
        {
            ds.unions(connections[i][0],connections[i][1],extra);
        }
        int count=0;
        for(int i=0;i<v;i++)
        {
            if(ds.parent[i]==i)
            {
                count++;
            }
        }
        // if(connections.size()>=v-1)
        // {
        //     return count-1;
        // }
        if(extra>=count-1)
        {
            return count-1;
        }
        return -1;
    }
};