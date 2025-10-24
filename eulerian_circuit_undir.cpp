void dfs(vector<vll>& g, vll& vis, ll i){
    vis[i]=1;
    for(auto j:g[i]) if(vis[j]==0) dfs(g,vis,j);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    map<pll,ll> mp;
    vector<vll> g(n+1);
    ll x,y;
    fr(i,0,m){
        cin>>x>>y;
        mp[{x,y}]=0;
        g[x].pb(y);
        g[y].pb(x);
    }
    fr(i,1,n+1){
        if(g[i].size()%2) {cout<<"IMPOSSIBLE"<<endl; return;}
    }
    vll vis(n+1,0);
    dfs(g,vis,1);
    fr(i,1,n+1){
        if(vis[i]==0 && g[i].size()>0) {cout<<"IMPOSSIBLE"<<endl; return;}
    }
    vll ans;
    stack<ll> st;
    st.push(1);
    while(st.size()>0){
        int x=st.top();
        if(g[x].size()>0){
            int y=g[x].back();
            g[x].pop_back();
            if(mp.find({x,y})!=mp.end()){
                if(mp[{x,y}]==1) continue;
                else mp[{x,y}]=1;
            }
            else {
                if(mp[{y,x}]==1) continue;
                else mp[{y,x}]=1;
            }
            st.push(y);
        }
        else{
            ans.emplace_back(x);
            st.pop();
        }
    }
    for(auto i:ans) cout<<i<<" ";
}
