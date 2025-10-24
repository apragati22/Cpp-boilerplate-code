// dfs discovery time and finish time
void dfs(vector<vll>& g, ll i, ll &time, vll& vis, vll& disc_time, vll& finish_time){
    vis[i]=1;
    disc_time[i]=time;
    time++;
    for(auto j:g[i]){
        if(vis[j]==0)
        dfs(g,j,time,vis,disc_time, finish_time);
    }
    finish_time[i]=time;
    time++;
}

ll scc(vector<vll>& g, vll& comp, ll& n){
    vll vis(n,0);
    vll discTime(n,0);
    vll finiTime(n,0);
    ll time=0;
    fr(i,0,n){
        if(vis[i]==0)
        dfs(g, i, time, vis, discTime, finiTime);
    }
    vector<pll> fp(n);
    fr(i,0,n) fp[i]={finiTime[i], i};
    sort(all(fp), greater<pll>());
    vector<vll> gr(n);
    fr(i,0,n){
        for(auto j:g[i])
        gr[j].pb(i);
    }
    ll num=1;
    fill(all(vis), 0);
    for(auto i:fp){
        if(vis[i.sec]==1) continue;
        vis[i.sec]=1;
        comp[i.sec]=num;
        queue<ll> q;
        q.push(i.sec);
        while(!q.empty()){
            ll x=q.front(); q.pop();
            for(auto j:gr[x]){
                if(vis[j]==1) continue;
                vis[j]=1;
                comp[j]=num;
                q.push(j);
            }
        }
        num++;
    }
    return num-1;
}