#include <bits/stdc++.h> 
void minHeapify(int i,vector<int>&myheap){
    int size = myheap.size();
    int l=2*i+1;
    int r=2*i+2;
    int smallest=i;
    if(l<size && myheap[l]<myheap[i])    smallest=l;
    if(r<size && myheap[r]<myheap[i] 
        && myheap[r]<myheap[l])         smallest=r;

    if(smallest!=i){
        swap(myheap[smallest],myheap[i]);
        minHeapify(smallest,myheap);
    }
}
void insert(vector<int>&myheap,int x){
    myheap.push_back(x);
    int size = myheap.size();
    int idx=size-1;
    int par=(idx-1)/2;
    while(myheap[par]>myheap[idx]){
        minHeapify(par,myheap);
        idx=par;
        par=(par-1)/2;
    }
}
int removehead(vector<int>&myheap){
    int size = myheap.size();
    int ans=myheap[0];
    swap(myheap[0],myheap[size-1]);
    myheap.pop_back();
    minHeapify(0, myheap);
    return ans;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    
    vector<int>myheap;
    vector<int>ans;
    for(int i=0;i<q.size();i++){
        if(q[i][0]==0){
            insert(myheap,q[i][1]);
        }
        else{
            ans.push_back(removehead(myheap));
        }
    }
    return ans;
}



/************************** without heapify ****************************/
/*************** but giving wrong answer on some test cases  ************/
// class Heap{
// public:
//     vector<int> arr;
//     int size;

//     void heap(){
//         arr.clear();
//         size=0;
//     }

//     void print(){
//         for(int i=0; i<size; i++)    cout<<arr[i]<<" ";
//         cout<<endl;
//     }

//     void insert(int x){
//         if(arr.size()==size)    arr.push_back(x);
//         else    arr[size]=x;
//         size++;
//         int i=size-1;
//         while(i>=0){
//             int par = (i-1)/2;
//             if(arr[par]<=arr[i])  break;
//             swap(arr[par],arr[i]);
//             i = par;
//         }
//     }

//     int pop() {
//         int mini = arr[0];
//         swap(arr[0],arr[size-1]);
//         size--;
//         int i=0;
//         while(i<=size-1){
//             int l = 2*i + 1;
//             int r = 2*i + 2;
//             // cout<<arr[l]<<" ";
//             // cout<<arr[r]<<" ";

//             if(l<=size-1 && arr[i]>=arr[l]){
//                 swap(arr[i],arr[l]);
//                 i = l;
//             }
//             else if(r<=size-1 && arr[i]>=arr[r]){
//                 swap(arr[i],arr[r]);
//                 i = r;
//             }
//             else    break;
//         }
//         // cout<<endl;
//         return mini;
//     }

// };

// vector<int> minHeap(int n, vector<vector<int>>& queries) {
//     vector<int> ans;
//     Heap h = Heap();

//     for(auto v: queries){
//         if(v[0]==0){ // insert v[1]
//             h.insert(v[1]);
//         } else{ // add min element to 'ans' and remove from heap 'h' 
//             int mini = h.pop();
//             ans.push_back(mini);
//         }
//         // cout<<"size: "<<h.size<<endl; 
//         // h.print();
//         // cout<<endl;
//     }
//     return ans;
// }







/*************** Simply using priorit queue ***************/
#include <bits/stdc++.h> 
vector<int> minHeap(int n, vector<vector<int>>& queries) {
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto v: queries){
        int type = v[0];
        if(type==0) pq.push(v[1]);
        else{
            if(!pq.empty()){
                ans.push_back(pq.top());   
                pq.pop();
            } else{
                ans.push_back(-1);
            }
        }
    }
    return ans;
}