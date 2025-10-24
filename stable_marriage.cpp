vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women) {
    int n=men.size(); 
    vector<int> a(n);
    queue<int> unm;
    for(int i=0; i<n; i++) unm.push(i);
    vector<int> idx(n,0);
    vector<int> mate(n,-1);    
    while(!unm.empty()){
        int m=unm.front();
        unm.pop();
        int w=men[m][idx[m]];
        idx[m]++;
        if(mate[w]==-1) {
            a[m]=w;
            mate[w]=m;
        }
        else{
            int i1=-1, i2=-1;
            for(int i=0; i<n; i++) {
                if(women[w][i]==mate[w]) i1=i;
                if(women[w][i]==m) i2=i;
            }
            if(i2<i1){
                unm.push(mate[w]);
                a[m]=w;
                mate[w]=m;
            }
            else{
                unm.push(m);
            }
        }
    }
    return a;
}