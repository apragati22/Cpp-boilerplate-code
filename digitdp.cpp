void getdig(ll x, vll& v){
    while(x>0){
        v.pb(x%10);
        x=x/10;
    }
}

ll foo(vector<vector<vll>> &dp, vll& dig, ll idx, ll sum, ll tight){
    if(idx==-1) return sum;
    if(dp[idx][sum][tight]!=-1) return dp[idx][sum][tight];
    ll ans=0;
    ll k=(tight==1)?dig[idx]:9;
    fr(i,0,k+1){
        ll newt=(i==dig[idx])?tight:0;
        ans+=foo(dp,dig,idx-1,sum+i,newt);
    }
    if(tight==0) dp[idx][sum][tight]=ans;
    return ans;
}

void solve(){
    ll a,b;
    cin>>a>>b;
    vector<vector<vll>> dp(16, vector<vll>(160, vll(2,-1)));
    vll da,db;
    getdig(b,db);
    a=a-1;
    getdig(a,da);
    ll s1=da.size();
    ll s2=db.size();
    ll ans=foo(dp,da,s1-1,0,1); 
    ll ans2=foo(dp,db,s2-1,0,1);
    cout<<ans2-ans<<endl;
}