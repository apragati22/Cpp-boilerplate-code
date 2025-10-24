class TreeAncestor {
    vector<vector<int>> dp;
    int root;
public:
    TreeAncestor(int n, vector<int>& parent) {
        int mx=log2(n)+1;
        for(int i=0; i<n; i++){
            vector<int> t(mx,-1);
            dp.push_back(t);
        }
        for(int i=0; i<parent.size(); i++){
            if(parent[i]==-1) {root=i; continue;}
            dp[i][0]=parent[i];
        }
        int col=1;
        vector<bool> vis(n,0);
        vis[root]=1;
        while(col<mx){
            for(int i=0; i<n; i++){
                if(vis[i]==1) continue;
                if((dp[i][col-1])==-1) continue;
                dp[i][col]=dp[dp[i][col-1]][col-1];
                if(dp[i][col]==-1) vis[i]=1;
            }
            col++;
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(node==-1 || k==0) return -1;
        int t=log2(k);
        if(k==(1<<t)) return dp[node][t];
        else return getKthAncestor(dp[node][t], k-(1<<t));
    }
};