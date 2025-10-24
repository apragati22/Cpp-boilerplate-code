void dfs(vector<vector<int>>& adj, vector<int>& dfn, vector<int>& vis, vector<int>& par, int i, set<vector<int>>& ans, vector<int>& hp, int n){
    vis[i]=1;
    dfn[i]=n++;
    for(auto j:adj[i]){
        if(vis[j]==0){
            par[j]=i;
            dfs(adj, dfn, vis, par, j, ans, hp, n);
            hp[i]=min(hp[i], hp[j]);
            if(hp[j]>dfn[i]) ans.insert({i,j});
        }
        else if(j!=par[i]){
            hp[i]=min(hp[i], dfn[j]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& adj) {
    vector<int> dfn(n,n);
    vector<int> vis(n,0);
    vector<int> par(n,0);
    vector<int> hp(n,n);
    set<vector<int>> ans;
    int i=0;
    dfs(adj, dfn, vis, par, 0, ans, hp, i);
    vector<vector<int>> ret(ans.begin(), ans.end());
    return ret;
}