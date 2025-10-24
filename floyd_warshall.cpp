void fw(vector<vector<int>>& g, int n, int m, vector<vector<int>>& dp){
    // g[i] = {from, to, price}
    // n nodes -> 1 to n
    // m edges
    // dp -> (n+1)*(n+1) , initialised with 1e9
    for(int i=1; i<=n; i++) dp[i][i]=0;
    for(auto i:g){
        int f,t,p;
        f=i[0], t=i[1], p=i[2];
        dp[f][t]=p;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dp[i][j]=(int)min((long long) dp[i][j], ((long long)dp[i][k]+(long long)dp[k][j]));
            }
        }
    }
}