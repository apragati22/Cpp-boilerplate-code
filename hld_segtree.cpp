void upd(ll id, ll val, vll& segtree, ll n){
    id+=n-1;
    segtree[id]=val;
    id=id/2;
    while(id>0){
        segtree[id]=max(segtree[2*id], segtree[2*id+1]);
        id=id/2;
    }
}

ll query(vll& segtree, ll x, ll y, ll n){
    x+=n-1, y+=n-1;
    ll v1=segtree[x], v2=segtree[y];
    while(x/2!=y/2){
        if(x%2==0) v1=max(v1, segtree[x+1]);
        if(y%2==1) v2=max(v2, segtree[y-1]);
        x=x/2; y=y/2;
    }
    return max(v1,v2);
}

void dfs_hld(vector<vll>& g, vll& sz, vll& v, vll& par, vll& idx, vll& head, ll& num, ll i, ll top, vll& segtree, ll& n){
    idx[i]=num++;
    head[i]=top;
    upd(idx[i], v[i], segtree, n);
    ll hc=-1, hs=-1;
    for(auto j:g[i]){
        if(j==par[i]) continue;
        if(sz[j]>hs){
            hs=sz[j];
            hc=j;
        }
    }
    if(hc==-1) return;
    dfs_hld(g, sz, v, par, idx, head, num, hc, top, segtree, n);
    for(auto j:g[i]){
        if(j==par[i]) continue;
        if(j==hc) continue;
        dfs_hld(g, sz, v, par, idx, head, num, j, j, segtree,n);
    }

}

void dfs_sz(vector<vll>& g, vll& par, vll& dep, vll& sz, ll i){
    sz[i]=1;
    for(auto j:g[i]){
        if(j==par[i]) continue;
        par[j]=i;
        dep[j]=dep[i]+1;
        dfs_sz(g,par, dep, sz, j);
        sz[i]+=sz[j];
    }
}

ll path(vll& head, vll& dep, vll& segtree, vll& par, vll& idx, ll& n, ll a, ll b){
    ll ret=0;
    while(head[a]!=head[b]){
        if(dep[head[a]]<dep[head[b]]) swap(a,b);
        ret=max(ret, query(segtree, idx[head[a]], idx[a], n));
        a=par[head[a]];
    }
    if(dep[a]>dep[b]) swap(a,b);
    ret=max(ret, query(segtree, idx[a], idx[b],n));
    return ret;
}

void solve(){
    ll n,q;
    cin>>n>>q;
    vector<vll> g(n+1);
    vll val(n+1);
    fr(i,0,n) cin>>val[i+1];
    fr(i,0,n-1){
        ll x,y;
        cin>>x>>y;
        g[x].pb(y); g[y].pb(x);
    }
    vll par(n+1,0);
    vll dep(n+1,0);
    vll sz(n+1,0);
    par[1]=1;
    dep[1]=0;
    dfs_sz(g, par, dep, sz, 1);
    ll leaf=(1<<(ll)(ceil(log2(n))));
    vll segtree(2*leaf);
    vll idx(n+1);
    vll head(n+1);
    ll num=1; 
    dfs_hld(g, sz, val, par, idx, head, num, 1, 1, segtree, leaf);

    fr(i,0,q){
        ll x,a,b;
        cin>>x>>a>>b;
        if(x==1){
            val[a]=b;
            upd(idx[a], val[a],segtree, leaf);
        }
        else{
            cout<<path(head, dep, segtree, par, idx, leaf, a,b)<<" ";
        }
    }
    cout<<endl;
}