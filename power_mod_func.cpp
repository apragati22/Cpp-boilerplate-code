int pow(int x, int n, int d) {
    if(x==0) return 0%d;
    if(n==0) return 1%d;
    if(x==1) return 1%d;
    if(x<0 && n==1) return (x+d)%d; 
    if(n==1) return x%d;
    long long ret=pow(x,n/2,d)%d;
    long long int ans=(ret*ret)%d;
    if(n%2) ans=(ans*x)%d;
    if(ans<0) ans=(ans+d)%d;
    return ans%d;
}