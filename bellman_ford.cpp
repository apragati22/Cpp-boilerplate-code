ll bf (vector<vector<pair<ll,ll>>>& g, ll src, ll snk, vector<ll>& dp, ll &n, ll &m){
    // g -> pair of node, weight of edge
    // dp[j][i] -> cost of reaching j in atmost i edges
    // undirected graph
    // n=1 to n nodes
    // m is the nomber of edges
    // if directed, need to maintain for each node a list of nodes from where we can reach that node and use in inside loop 
    for(ll i=1; i<=n; i++) dp[i]=1e9;
    dp[src]=0;
    for(auto i:g[src]) dp[i.first]=i.second;
    for(ll t=2; t<=m ;t++){
        vector<ll> newdp(n+1);
        for(ll i=1; i<=n; i++){
            newdp[i]=dp[i];
            for(auto k:g[i]){ // use that list here
                newdp[i]=min(newdp[i], dp[k.first]+k.second);
            }
        }
        if(dp==newdp) break;
        dp=newdp;
    }
    return dp[n];
}