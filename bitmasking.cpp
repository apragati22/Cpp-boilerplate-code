// 1. REPRESENTATION: A 32 (or 64)-bit signed integer for up to 32 (or 64) items. ( To avoid issues with the 
//     two’s complement representation, use a 32-bit/64-bit signed integer to represent bitmasks of up to
//     30/62 items only, respectively ).

//  2. To multiply/divide an integer by 2: 
//      left/right shift

//  3. Add the jth object to the subset (set the jth bit from 0 to 1):
//      use the bitwise OR operation A |= (1 << j).

// 4. Remove the jth object from the subset (set the jth bit from 1 to 0):
//      use the bitwise AND operation A &= ∼(1 << j).

// 5. Check whether the jth object is in the subset (check whether jth bit is 1):
//    use the bitwise AND operation T = A & (1 << j).
//    If T = 0, then the j-th item of the set is off.
//    If T != 0 (to be precise, T = (1 << j)), then the j-th item of the set is on.

// 6. To toggle (flip the status of) the j-th item of the set:
//    use the bitwise XOR operation A ∧ = (1 << j).

// 7. To get the value of the least significant bit that is on (first from the right):
//    use T = (A & (-A)).

// 8. To turn on all bits in a set of size n: (be careful with overflows)
//    use A = (1 << n) - 1 ;

// 9. Iterate through all subsets of a set of size n:
//            `for ( x = 0; x < (1 << n); ++x )`  

// 10. Iterate through all subsets of a subset y (not including empty set):
//            `for ( x = y; x > 0; x = ( y & (x-1) ) )`

void f(vll& dp, vll& score, ll mask){
    if(mask==0) return;
    if(dp[mask]!=0) return;
    for(ll sub=mask; sub>0; sub=(sub-1)&mask){
        f(dp, score, (sub^mask));
        dp[mask]=max(dp[mask], score[sub]+dp[sub^mask]);
    }
}

void solve(){
    ll n = nxt();
    vector<vll> a(n,vll(n));
    fr(i,0,n)
        fr(j,0,n) cin>>a[i][j];

    vll mask_score(1<<n,0);
    vll dp(1<<n,0);
    fr(m,0,(1<<n)){
        fr(i,0,n){
            fr(j,i+1,n){
                if(m&(1<<i) && m&(1<<j)) mask_score[m]+=a[i][j];
            }
        }
    }

    f(dp, mask_score, (1<<n)-1);
    cout<<dp[(1<<n)-1]<<endl;
}