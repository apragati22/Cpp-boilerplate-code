// undirected graph, with edges numbered from 0 to n-1
// find all articulation points in the graph 

void dfs(vector<int> adj[], vector<int>& dfn, vector<int>& vis, vector<int>& par, int i, set<int>& ans, vector<int>& hp, int n){
    vis[i]=1;
    dfn[i]=n++;
    for(auto j:adj[i]){
        if(vis[j]==0){
            par[j]=i;
            dfs(adj, dfn, vis, par, j, ans, hp, n);
            hp[i]=min(hp[i], hp[j]);
            if(hp[j]>=dfn[i] && i!=0) ans.insert(i);
        }
        else if(j!=par[i]){
            hp[i]=min(hp[i], dfn[j]);
        }
    }
}

vector<int> articulationPoints(int n, vector<int>adj[]) {
    vector<int> dfn(n,n);
    vector<int> vis(n,0);
    vector<int> par(n,0);
    vector<int> hp(n,n);
    set<int> ans;
    int i=0;
    dfs(adj, dfn, vis, par, 0, ans, hp, i);
    int ct=0;
    set<int> s;
    for(auto i:adj[0]) if(i!=0) s.insert(i);
    for(auto i:s){
        if(par[i]==0) {
            ct++; 
        }
    }
    if(ct>1) ans.insert(0);
    if(ans.size()==0) {
        ans.insert(-1);
    }
    vector<int> ret(all(ans));
    return ret;
}

