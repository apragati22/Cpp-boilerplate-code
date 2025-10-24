//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int size=(r-l+1);
        if (size==1) return arr[l];
        int median[size];
        int a=0;
        for(int i=l;i<l+size;i=i+5){
            if(i+5>=size+l) {
                sort(arr+i,arr+size+l);
                median[a++]=arr[(size+i+l)/2];
                break;
            }
            else{
                int temp=i+5;
                sort(arr+i,arr+temp);
                median[a++]=arr[i+2];
            }
        }
        int x=kthSmallest(median,0,a-1,(a-1)/2);
        int y=r;
        int index_i;
        for(int i=l;i<l+size;i++){
            if(arr[i]==x){
                index_i=i;
                break;
            }
        }
        swap(arr[l],arr[index_i]);
        for(int i=r;i>l;i--){
            if (arr[i]>x){
                swap(arr[i],arr[y]);
                y--;
            }
        }
        swap(arr[l],arr[y]);
        if(y+1==k) return x;
        if(y+1<k) return kthSmallest(arr,y+1,r,k);
        if(y+1>k) return kthSmallest(arr,l,y-1,k);
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends