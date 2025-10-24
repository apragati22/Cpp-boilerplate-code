#define func min

ll find_query(vector<vll> &spt, ll L, ll R){
    ll j=log2(R-L+1);
    return func(spt[L][j], spt[R-(1<<(j))+1][j]);
}

int main(){
    ll n; cin>>n;
    ll a[n];
    fr(i,0,n) cin>>a[i];

//BUILD TABLE    
    ll row=n; ll col=log2(n);
    vector<vll> spt(row+1, vll(col+1));
    // ll spt[row+1][col+1];
    for(int i=0;i<=row;i++)
        for(int j=0;j<=col;j++) 
            spt[i][j]=1e9;

    for(int i=1;i<=row;i++) spt[i][0]=a[i-1];
    for(int j=1;j<=col;j++){
        for(int i=0; i+(1<<j)<=n;i++){
            spt[i][j]=func(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
        }
    }
//BUILD ENDS

//QUERY of form l,r
    ll L,R;
    if(R<L) swap(L,R);
    ll ans=find_query(spt, L,R);

    return 0;
}