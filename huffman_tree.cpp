//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
	public:
	
	struct Node{
        int val;
        // char c;
        struct Node* left;
        struct Node* right;
    };
    
    Node* make_node(int x){
        Node* temp;
        temp=(Node*)malloc(sizeof(Node));
        temp->val=x;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    
     vector<Node*> arr;

	Node* extractMin(int n){
        Node* temp=arr[0];
        swap(arr[0],arr[n-1]);
        int i=0;
        while(i<n-1){
            //int min=arr[i];
            int min=i;
            if((2*i+1)<n-1 && arr[2*i+1]->val<arr[min]->val) {
                min=2*i+1;}
            if(2*i+2<n-1 && arr[2*i+2]->val<arr[min]->val) {
                min=2*i+2;}
            if(min!=i){
                swap(arr[i],arr[min]);
                
                i=min;
            }
            else break;
        }
        return temp;
    }

    void heapify(int n,int i){
            int size=n-1;
            int flag=1;
            while(i<=((size-1)/2) && flag==1){
                int min=i;
                if((2*i+1)<=size && ((arr[2*i+1]->val)<(arr[i]->val))) {
                min=2*i+1;}
            if(2*i+2<=size && arr[2*i+2]->val<arr[min]->val) {
                min=2*i+2;}
                if(min!=i){
                    swap(arr[i],arr[min]);
                    
                    i=min;
                }
                else flag=0;
            }
    }

    void build_heap(int n){
        int i=n/2-1;
        while(i>=0){
            // int min=arr[i]->val;
            int min=i;
            if((2*i+1)<n && arr[2*i+1]->val<arr[min]->val) {
                min=2*i+1;}
            if(2*i+2<n && arr[2*i+2]->val<arr[min]->val) {
                min=2*i+2;}
            if(min!=i){
                swap(arr[i],arr[min]);
                
            }
            heapify(n,min);
            i--;
        }
    }
    
    void update_heap( int N){
        int i=N-1;
        while(i>=0 && arr[i]->val<arr[(i-1)/2]->val){
                swap(arr[i],arr[(i-1)/2]);
                i=(i-1)/2;
        }
    }
    
    vector<string> ans;
    string s;
    
    void traversal(Node* temp){
        Node* p;
        p=temp;
        if(p->left==NULL && p->right==NULL) {
            ans.push_back(s);
            return;
        }
        else {
            if (p->left!=NULL) {
                s.push_back('0');
                traversal(p->left);
                s.pop_back();
            }
            if (p->right!=NULL) {
                s.push_back('1');
                traversal(p->right);
                s.pop_back();
            }
        }
    }
    
	vector<string> huffmanCodes(string S,vector<int> f,int N){
		    
        for(int i=0;i<N;i++){
            Node* temp;
            temp=make_node(f[i]);
            arr.push_back(temp);
        }
        
        build_heap(N);
        Node* head;
    while(N>1){
        Node* x=extractMin(N);
        N--;
        //  cout<<x->val<<" ";
        Node* y=extractMin(N);
        N--;
        //  cout<<y->val<<" ";
        int z=(x->val)+(y->val);
        Node* c=make_node(z);
        c->left=x;
        c->right=y;
        //  cout<<c->val<<endl;
        arr[N]=c;
            N++;
        update_heap(N);
        head=c;
    }
    traversal(head);
    return ans;
}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends