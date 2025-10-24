// Kahn's algo
void topo(vector<vll>& g, ll &n){
    // nodes 1 to n
    vll ind(n+1,0);
    for(auto i:g){
        if(i==0) continue;
        for(auto j:i){
            ind[j]++;
        }
    }
    queue<ll> q;
    fr(i,1,n+1)
        if(ind[i]==0) q.push(i);
    vll list;
    list.reserve(n);
    while(!q.empty()){
        ll x=q.front(); q.pop();
        list.emplace_back(x);
        for(auto j:g[x]){
            ind[j]--;
            if(ind[j]==0) q.push(j);
        }
    }
}

// topo using dfs 
stack<ll> st;
vll topo;
// topo sort is vertices sorted in the decreasing order of thier finish times
void dfs(vector<vll>& g, ll i, ll time, vll& vis, vll& disc_time, vll& finish_time){
    vis[i]=1;
    disc_time[i]=time;
    time++;
    for(auto j:g[i]){
        if(vis[j]==0)
        dfs(g,j,time,vis,disc_time, finish_time);
    }
    finish_time[i]=time;
    time++;
    st.push(i);
}

while(!st.empty()){
    ll x= st.top();
    st.pop();
    topo.pb(x);
}