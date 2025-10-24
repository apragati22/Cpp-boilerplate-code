void update_segTree(ll sum[], ll leaf, ll a, ll b){
    a=a+(1<<leaf)-1;
    sum[a]=b;
    ll j=a/2;
    while(j>=1){
        sum[j]=sum[2*j]+sum[2*j+1];
        j=j/2;
    }
}

ll query_range(ll sum[], ll leaf, ll a, ll b){
    ll t=a;
    a=min(a,b); b=max(b,t);
    a=a+(1<<leaf)-1;
    b=b+(1<<leaf)-1;
    t=0;
    t+=sum[a]; 
    if(a!=b) t+=sum[b];
    while((a/2)!=(b/2)){
        if(a%2==0) t+=sum[a+1];
        if(b%2==1) t+=sum[b-1];
        a=a/2;
        b=b/2;
    }
    return t;
}

void solve(){
    ll n = nxt();
    ll k=nxt();
    ll a[n];
    fr(i,0,n) cin>>a[i];
    vector<vector<ll>> q;
    ll x,y,t;
    fr(i,0,k){
        cin>>t>>x>>y;
        q.pb({t,x,y});
    }

//BUILD SEG TREE
    ll leaf=ceil(log2(n));
    ll p2=(1<<leaf);
    ll sum[2*p2]={0};
    ll j=0;
    fr(i,p2,2*p2){
        if(j==n) break;
        else sum[i]=a[j++];
    }
    j=p2-1;
    while(j>=1){
        sum[j]=sum[2*j]+sum[2*j+1];
        j--;
    }
// BUILD ENDS HERE

    fr(i,0,k){
        if((q[i][0])==1){
            ll a=q[i][1]; 
            ll b=q[i][2]; 
            update_segTree(sum, leaf, a, b);
        }
        else{
            ll a=q[i][1];
            ll b=q[i][2]; 
            ll ans=query_range(sum, leaf, a,b);
            cout<<ans<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}