//returns min total cost of edges in ans
//A= total no of nodes
//B = list of ({node1, node2, weight of that edge})


//PRIMS ALGO

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<pair<int,int>> adj[A+1];
for(int i=0;i<B.size();i++){
    adj[B[i][0]].push_back(make_pair(B[i][1], B[i][2]));
    adj[B[i][1]].push_back(make_pair(B[i][0], B[i][2]));
}
pq.push(make_pair(0,1));
// vector<int> dist(A+1, INT_MAX);
bool inMST[A+1]={0};
// inMST[1]=1;
pair<int,int> x;
int v;
// dist[0]=0; dist[1]=0;
int ct=0;
int ans=0;
while(!pq.empty()){
    x=pq.top();
    pq.pop();
    if(inMST[x.second]==1) continue;
    ct++;
    ans+=x.first;
    v=x.second;
    inMST[v]=1;
    
    for(int j=0;j<adj[v].size();j++){
        if(inMST[adj[v][j].first]==0){
            // inMST[adj[v][j].first]=1;
            pq.push({adj[v][j].second, adj[v][j].first});
        }
    }
    if(ct==A) break;
}
return ans;



//KRUSKAL'S ALGO

// uses DSU to find cycle in logE time

int findpar(int par[], int i){
    if(par[i]==i) return i;
    else return findpar(par,par[i]);
}

void unite(int par[], int sz[], int p1, int p2){
    if(sz[p1]>sz[p2]){
        par[p2]=p1;
        sz[p1]+=sz[p2];
        sz[p2]=0;
    }
    else{
        par[p1]=p2;
        sz[p2]+=sz[p1];
        sz[p1]=0;
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<vector<int>> v;
    vector<int> t;
    for(int i=0;i<B.size();i++){
        t.clear();
        for(int j=2;j>=0;j--){
            t.push_back(B[i][j]);
        }
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int par[A+1]={0};
    int sz[A+1]={0};
    for(int i=1;i<=A;i++) par[i]=i;
    for(int i=1;i<=A;i++) sz[i]=1;
    // int m=v.size();
    int i=0;
    int ans=v[0][0];
    par[v[0][1]]=v[0][2];
    sz[v[0][2]]+=sz[v[0][1]];
    sz[v[0][1]]=0;
    i++;
    int ct=2;
    while(ct<A){
        int p1=findpar(par,v[i][1]);
        int p2=findpar(par,v[i][2]);
        if(p1==p2) {i++; continue;}
        else{
            unite(par, sz, p1,p2);
            ans+=v[i][0];
            ct++;
        }
        i++;
    }
    return ans;
}
