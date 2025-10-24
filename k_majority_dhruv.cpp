#include <iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    char A[N];
    int k;
    cin>>k;
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    int count[k-1] = {0};
    char x[k-1];
    
    x[0] = A[0];
    int i=0;
    int j=1;
    while(j<k-1){
        int flag = 0;
        for(int p=0; p<j; p++){
            if(x[p] == A[i]){
                flag = 1;
                count[p]++;
                break;
            }
        }
        if(flag == 0){
            x[j] = A[i];
            count[j] = 1;
            j++;
        }
        i++;
    }
    while(i<N){
        for(int j=0; j<k-1; j++){
            if(count[j] == 0){
                for(int l=0; l<k-1; l++){
                    if(l==j)continue;
                    if(i>=N)break;
                    if(x[l] == A[i]){
                        i++;
                        count[l]++;
                        l=-1;
                    }                    
                }
                if(i>=N)break;
                x[j] = A[i];
                count[j] = 1;
                i++;
            }
        }
        int flag = 1;
        for(int j=0; j<k-1; j++){
            if(i>=N)break;
            if(x[j] == A[i]){
                count[j]++;
                flag = 0;
                i++;
            }
        }
        if(flag){
            for(int j=0; j<k-1; j++){
                count[j]--;
            }
            i++;
        }
    }

    for(int i=0; i<k-1; i++){
        count[i] = 0;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<k-1; j++){
            if(x[j] == A[i]) count[j]++;
        }
    }
    
    int flag = 1;
    for(int i=0; i<k-1; i++){
        if(count[i] > N/k){
            cout<<x[i]<<" ";
            flag = 0;
        }
    }
    if(flag) cout<<"Not found"; 
    
    return 0;
}