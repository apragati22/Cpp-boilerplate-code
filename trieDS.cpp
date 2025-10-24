// class trienode{
//     public:
//     trienode* zero;
//     trienode* one;
//     trienode() {zero=NULL; one=NULL;}
//     void insert(int num, trienode* root);
//     void search(int num, int &ans, trienode* root);
// };

// void trienode::insert(int num, trienode* root){
//     trienode* temp=root;
//     for(int i=31;i>=0;i--){
//         int bit=(num>>i)&1;
//         if(bit==0){
//             if(temp->zero==NULL){
//                 temp->zero=new trienode();
//             }
//             temp=temp->zero;
//         }
//         else{
//             if(temp->one==NULL){
//                 temp->one=new trienode();
//             }
//             temp=temp->one;
//         }
//     }
// }

// void trienode::search(int num, int &ans, trienode* root){
//     trienode* temp=root;
//     int xr=0;
//     for(int i=31;i>=0;i--){
//         int bit=(num>>i)&1;
//         if(bit==0 && temp->one!=NULL) {xr=xr^(1<<i); temp=temp->one;}
//         else if(bit==0) {temp=temp->zero;}
//         if(bit==1 && temp->zero!=NULL) {xr=xr^(1<<i); temp=temp->zero;}
//         else if(bit==1) {temp=temp->one;}
//     }
//     ans=max(ans,xr);
// }


// class trienode{
//     public:
//     trienode* root[26];
//     int eow;
//     trienode() { eow=0; for(int i=0;i<26;i++) root[i]=NULL;}
//     void insert(string s, trienode* temp);
//     int search(string s,trienode* temp);
// };

// void trienode::insert(string s, trienode* head){
//     trienode* t=head;
//     for(auto i:s){
//         if(t->root[i-'a']==NULL){
//             trienode* ins=new trienode();
//             t->root[i-'a']=ins;
//         }
//         t=t->root[i-'a'];
//     }
//     t->eow=1;
// }

// int trienode::search(string s, trienode* head){
//     trienode* t=head;
//     for(auto i:s){
//         if(t->root[i-'a']!=NULL) { t=t->root[i-'a'];}
//         else return 0;
//     }
//     return t->eow;
// }

