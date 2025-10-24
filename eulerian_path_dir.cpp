void dfs(vector<deque<ll>>& g, vll& vis, ll i){
    vis[i]=1;
    for(auto j:g[i]) if(vis[j]==0) dfs(g,vis,j);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<deque<ll>> g(n+1);
    ll x,y;
    vll ind(n+1,0);
    fr(i,0,m){
        cin>>x>>y;
        g[x].pb(y);
        ind[y]++;
    }
    fr(i,2,n){
        if(ind[i]!=g[i].size()) {cout<<"IMPOSSIBLE"<<endl; return;}
    }
    if(g[1].size()!=ind[1]+1) {cout<<"IMPOSSIBLE"<<endl; return;}
    if(g[n].size()!=ind[n]-1) {cout<<"IMPOSSIBLE"<<endl; return;}
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
            int y=g[x][0];
            g[x].pop_front();
            st.push(y);
        }
        else{
            ans.emplace_back(x);
            st.pop();
        }
    }
    reverse(all(ans));
    for(auto i:ans) cout<<i<<" ";
}